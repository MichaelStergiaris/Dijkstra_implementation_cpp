#include <iostream>
#include "Dijkstra.h"

struct heap_entry {
    int node;
    int distance;
};

//Eisagoume mia apostash ston elaxisto swro
static void push_heap(heap_entry* heap, int& size, int node, int distance) {
    int index = size++;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].distance <= distance) break;
        heap[index] = heap[parent];
        index = parent;
    }
    heap[index].node = node;
    heap[index].distance = distance;
}

//Afairoume th mikroterh apostash apo ton elaxisto swro
static heap_entry pop_heap(heap_entry* heap, int& size) {
    heap_entry minimum = heap[0];
    heap_entry last = heap[--size];
    int index = 0;

    while (index * 2 + 1 < size) {
        int child = index * 2 + 1;
        if (child + 1 < size && heap[child + 1].distance < heap[child].distance) {
            child++;
        }
        if (heap[child].distance >= last.distance) break;
        heap[index] = heap[child];
        index = child;
    }
    if (size > 0) heap[index] = last;
    return minimum;
}

//Arxikopoihsh tou grafou xwris akmes
void init_graph(graph& g, int nodes) {
    if (nodes < 0) nodes = 0;
    if (nodes > MAX_NODES) nodes = MAX_NODES;

    g.num_nodes = nodes;
    g.num_edges = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        g.first_edge[i] = -1;
    }
}

//Prosthetoume akmh, h an uparxei hdh akmh me idio proorismo thn enhmerwnoume
void add_edge(graph& g, int src, int dest, int weight){
    if(src >= 0 && src < g.num_nodes && dest >= 0 && dest < g.num_nodes){
        for (int edge_index = g.first_edge[src]; edge_index != -1; edge_index = g.edges[edge_index].next) {
            if (g.edges[edge_index].destination == dest) {
                g.edges[edge_index].weight = weight;
                return;
            }
        }

        if (g.num_edges < MAX_EDGES) {
            int edge_index = g.num_edges++;
            g.edges[edge_index].destination = dest;
            g.edges[edge_index].weight = weight;
            g.edges[edge_index].next = g.first_edge[src];
            g.first_edge[src] = edge_index;
        }
    }
}

//O Dijkstra me lista geitniashs kai elaxisto swro
void dijkstra(graph& g, int start_node, int* dist, int* parent) {
    bool visited[MAX_NODES] = {false};

    //Arxikopoihsh twn apostasewn kai twn gonewn
    for (int i = 0; i < g.num_nodes; i++){
        dist[i] = INFINITY;
        parent[i] = -1;
    }

    if (start_node < 0 || start_node >= g.num_nodes) return;

    //H apostash apo ton eauto tou einai panta 0
    dist[start_node] = 0;
    heap_entry heap[MAX_EDGES + 1];
    int heap_size = 0;
    push_heap(heap, heap_size, start_node, 0);

    //Epexergazomaste prwta ton komvo me th mikroterh gnwsth apostash
    while (heap_size > 0) {
        heap_entry current = pop_heap(heap, heap_size);
        int current_node = current.node;

        //Agnooume palies eggrafes tou swrou kai komvous pou exoun hdh epexergastei
        if (current.distance != dist[current_node] || visited[current_node]) continue;
        visited[current_node] = true;

        //Ananewnoume tis apostaseis twn geitonwn tou komvou
        for (int edge_index = g.first_edge[current_node]; edge_index != -1; edge_index = g.edges[edge_index].next) {
            int neighbor = g.edges[edge_index].destination;
            int weight = g.edges[edge_index].weight;

            //Varos 0 shmainei oti den yparxei akmh, opws kai ston arxiko pinaka
            if (!visited[neighbor] && weight != 0) {
                int new_distance = dist[current_node] + weight;
                
                //Kratame th mikroterh apostash kai ton komvo apo ton opoio pername
                if (new_distance < dist[neighbor]) {
                    dist[neighbor] = new_distance;
                    parent[neighbor] = current_node;
                    push_heap(heap, heap_size, neighbor, new_distance);
                }
            }
        }
    }
}

//Anadromikh sunarthsh gia na typwsoume to monopati apo thn arxh pros ton proorismo
void print_shortest_path(int* parent, int current_node) {
    //Vash anadromhs: ftasame sthn arxh tou monopatiou
    if (parent[current_node] == -1) {
        std::cout << current_node;
        return; 
    }
    //Typwnoume prwta ton gonea gia na emfanistoun oi komvoi me th swsth seira
    print_shortest_path(parent, parent[current_node]);
    std::cout << " -> " << current_node;
}

//Typwnoume tis apostaseis kai ta syntomotera monopatia
void print_dijkstra_result(graph& g, int* distance, int* parent, int start_node){
    std::cout << "=================================================\n";
    std::cout << "Komvos\tApostash\tMonopati\n";
    std::cout << "=================================================\n";
    
    for(int i = 0; i < g.num_nodes; i++){
        std::cout << i << "\t";
        
        //Elegxos an o komvos einai prosvasimos apo ton arxiko komvo
        if(distance[i] == INFINITY){
            std::cout << "Apeiro\t\n";
        } else {
            std::cout << distance[i] << "\t\t";
            //Kalesma ths anadromikhs gia to monopati
            print_shortest_path(parent, i);
        }
        std::cout << "\n";
    }
    std::cout << "=================================================\n";
}