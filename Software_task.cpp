#include <iostream>
#include "Dijkstra.h"

using namespace std;

int main() {
    graph g;
    
    //Ftiaxnoume enan grafo me 8 komvous
    init_graph(g, 8);

    //Prosthetoume tis akmes me ta varh tous
    add_edge(g, 0, 1, 4);
    add_edge(g, 0, 2, 2);
    add_edge(g, 1, 2, 5);
    add_edge(g, 1, 3, 10);
    add_edge(g, 2, 4, 3);
    add_edge(g, 4, 3, 4);
    add_edge(g, 3, 5, 11);
    add_edge(g, 4, 6, 5);
    add_edge(g, 6, 5, 2);
    add_edge(g, 5, 7, 3);
    add_edge(g, 6, 7, 8);

    //Dhmiourgia twn pinakwn gia ta apotelesmata
    int distance[MAX_NODES];
    int parent[MAX_NODES];

    //Kaloume ton algorithmo me start_node ton komvo 0
    dijkstra(g, 0, distance, parent);

    //Tupwnoume ola ta data se pinaka
    print_dijkstra_result(g, distance, parent, 0);

    return 0;
}