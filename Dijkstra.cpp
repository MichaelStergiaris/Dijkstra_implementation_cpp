#include <iostream>
#include "Dijkstra.h"

//Arxikopoihsh tou grafou me mhdenika se ola ta kelia
void init_graph(graph& g, int nodes) {
    g.num_nodes = nodes;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            g.matrix[i][j] = 0;
        }
    }
}

//Prosthetoume mia nea akmi an oi komvoi einai entos oriwn
void add_edge(graph& g, int src, int dest, int weight){
    if(src >= 0 && src < g.num_nodes && dest >= 0 && dest < g.num_nodes){
        g.matrix[src][dest] = weight;
    }
}

//O vasikos algorithmos
void dijkstra(graph& g, int start_node, int* dist, int* parent) {
    bool visited[MAX_NODES] = {false};

    //Arxikopoihsh twn apostasewn kai twn gonewn
    for (int i = 0; i < g.num_nodes; i++){
        dist[i] = INFINITY;
        parent[i] = -1;
    }

    //H apostash apo ton eauto tou einai panta 0
    dist[start_node] = 0;

    //Trexoume to loop gia olous tous komvous
    for(int count = 0; count < g.num_nodes; count++){
        int minimum_distance = INFINITY;
        int current_node = -1;

        //Vriskoume ton komvo me th mikroterh apostash pou den exoume episkefthei
        for(int i = 0; i < g.num_nodes; i++){
            if(!visited[i] && dist[i] < minimum_distance){
                minimum_distance = dist[i];
                current_node = i;
            }
        }
        
        //An den yparxei allos prosvasimos komvos stamatame
        if(current_node == -1) break;
        
        //Shmeiwnoume ton komvo ws visited gia na mhn ton ksanadoume
        visited[current_node] = true;

        //Ananewnoume tis apostaseis twn geitonwn tou current_node
        for(int i = 0; i < g.num_nodes; i++){
            //An uparxei akmh (matrix != 0) kai o geitonas den einai visited
            if(!visited[i] && g.matrix[current_node][i] != 0){
                int new_distance = dist[current_node] + g.matrix[current_node][i];
                
                //An h nea diadromi einai pio kontinh(oxi Mano Kontinh), thn krataw kai allazw ton gonio
                if(new_distance < dist[i]){
                    dist[i] = new_distance;
                    parent[i] = current_node; 
                }
            }
        }
    }
}

//Anadromikh sunarthsh gia na typwsw to monopati
void print_shortest_path(int* parent, int current_node) {
    //Base case an ftasoume sthn arxh pou o gonios einai -1
    if (parent[current_node] == -1) {
        std::cout << current_node;
        return; 
    }
    //Anadromikh klhsh gia na paei mexri thn arxh kai na ta tupwsei me th swsth seira
    print_shortest_path(parent, parent[current_node]);
    std::cout << " -> " << current_node;
}

//Typwma twn apotelesmatwn se morfh pinaka
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