#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define MAX_NODES 100
#define MAX_EDGES (MAX_NODES * MAX_NODES)
#define INFINITY 999999

struct edge {
    int destination;
    int weight;
    int next;
};

struct graph{
    int num_nodes;
    int num_edges;
    int first_edge[MAX_NODES];
    edge edges[MAX_EDGES];
};

void init_graph(graph& g, int nodes);
void add_edge(graph& g, int src, int dest, int weight);
void dijkstra(graph& g, int start_node, int* distance, int* parent);
void print_shortest_path(int*parent, int current_node);
void print_dijkstra_result(graph& g, int* distance, int* parent, int start_node);

#endif 