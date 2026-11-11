#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define MAX_NODES 1000
#define INFINITY 999999


struct graph{
    int num_nodes;
    int matrix[MAX_NODES][MAX_NODES];
};

void init_graph(graph& g, int nodes);
void add_edge(graph& g, int src, int dest, int weight);
void dijkstra(graph& g, int start_node, int end_node, int* distance, int* parent);

#endif 