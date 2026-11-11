#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

void init_graph(graph& g, int nodes) {
    g.num_nodes = nodes;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            g.matrix[i][j] = 0;
        }
    }
}

void add_edge(graph& g, int src, int dest, int weight){
    if(src >= 0 && src < g.num_nodes && dest >= 0 && dest < g.num_nodes){
        g.matrix[src][dest] = weight;
    }
}

void dijkstra(graph& g, int start_node, int end_node, int* dist, int* parent) {
    bool visited[MAX_NODES] = {false};

    for (int i = 0; i < g.num_nodes; i++){
        dist[i] = INFINITY;
    }

    parent[start_node] = -1;
    dist[start_node] = 0;

    while(start_node != end_node){
        int minimum_distance = INFINITY;

        for(int i = 0; i < g.num_nodes; i++){
            if(!visited[i] && dist[i] < minimum_distance){
                minimum_distance = dist[i];
                start_node = i;
            }
        }
        visited[start_node] = true;
        for(int i = 0; i < g.num_nodes; i++){
            if(!visited[i] && g.matrix[start_node][i] != 0){
                int new_distance = dist[start_node] + g.matrix[start_node][i];
                if(new_distance < dist[i]){
                    dist[i] = new_distance;
                    parent[i] = start_node;
                }
            }
        }
    }


}