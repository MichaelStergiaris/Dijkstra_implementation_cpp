# Dijkstra's Shortest Path

This C++ program finds the shortest paths from a chosen starting node to every other reachable node in a directed, weighted graph. Its sample in `Software_task.cpp` builds an eight-node graph, runs the algorithm from node 0, and prints each node's distance and route.

The graph is stored in a fixed-size adjacency list, so the program does not allocate memory dynamically and supports up to 100 nodes. Dijkstra's algorithm starts by setting every distance to infinity except the source, then repeatedly processes the reachable node with the smallest known distance using a min-heap. It relaxes that node's outgoing edges, recording the preceding node whenever it finds a shorter route. The recorded predecessors are then used to print each path in order. With `V` nodes and `E` edges, the algorithm runs in `O((V + E) log V)` time.

Edge weights must be positive: a weight of zero represents the absence of an edge, and Dijkstra's algorithm does not support negative weights. Distances use `999999` as the infinity sentinel, so route costs should remain below that value.

## Build and run

```sh
g++ -std=c++11 Dijkstra.cpp Software_task.cpp -o Dijkstra
```

Run the resulting `Dijkstra.exe` on Windows or `./Dijkstra` on Linux and macOS.


## Diagram of code
[![Architecture diagram of michaelstergiaris/dijkstra_implementation_cpp](https://gitdiagram.com/michaelstergiaris/dijkstra_implementation_cpp/diagram.png)](https://gitdiagram.com/michaelstergiaris/dijkstra_implementation_cpp?utm_source=readme&utm_medium=picture)
