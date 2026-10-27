1)

The map is held in a 2D vector of chars. Each vertex stands for the cost of moving onto that spot, and neighbors are found with simple index math: left and right are -1 and +1, while up and down are - cols and + cols. The edge weights come from the tile costs listed in the input file. All of the edges live in the 2D vector called graph, and the tile costs are kept in a map that uses the char as the key and the cost as the value. To run Dijkstra's we kept a visited vector to mark the nodes we are done with, a parents vector to remember where each node came from, and a distance vector to track how far each node is from the start. We follow our current index and compute the neighbor indexes from it using the math above. We also keep a map called current_path that stores every path we could move to next.


2)

Reading in the graph and storing it takes O(N^2), where N is the width of the map.
Looking at the possible paths from a new vertex is O(1), and putting each one into the current_paths map costs n log(n).
To pick the next path, we walk through current_path until we reach a vertex we have not visited yet. This makes the overall time O(V*E), since that is the most edges we could end up going through.

3)

Our program does fine on small graphs, but it starts to slow down once the graphs get bigger than 500 X 500. Our table shows this: every graph with a width under 100 finished in less than a second, while a graph with a width of 1000 took close to five minutes.
