#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define MAX_NODES 100
#define INFINITY 999999


struct graph{
    int num_nodes;
    int matrix[MAX_NODES][MAX_NODES];
};

void init_graph(graph& g, int nodes);
void add_edge(graph& g, int src, int dest, int weight);
void dijkstra(graph& g, int start_node, int* distance, int* parent);
void print_shortest_path(int*parent, int current_node);
void print_dijkstra_result(graph& g, int* distance, int* parent, int start_node);

#endif 