Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

    Build and Run Instructions
    --------------------------
    generate_map.cpp creates a map based off of a user inputed value and prints it to a text file.
    We then used this text file to test our dijkstras algorithim.
    
    To test replace num with the desired width of the graph and run the code: 
    echo <num> | ./generate_map
    /usr/bin/time -f "Elapsed Time: %e seconds\nMemory: %M KB" ./src/dijkstras < tester_map.txt > /dev/null 

    Benchmark methodology
    ---------------------
    We wrote a shellscript and ran the program five times for each graph size. 
    We then just hand calculated the median and pritned it in the graph below. 


Testing BENCH: 


    | N             | Median Elapsed Time (seconds) | Median Memory (KB)|   
----------------|-------------------------------|-------------------|      
| 10            | 0.00                          | 3456               |           
| 20            | 0.00                          | 3456               |           
| 50            | 0.00                          | 3507               |           
| 100           | 0.14                          | 3712               |           
| 200           | 5.29                          | 4224               |           
| 500           | 26.20                         | 7552               |           
| 1000          | 376.94                        | 20280              |           


1) 

We represented the map as a 2D vector of chars. Each vertex represents the weight cost to move to that index, and to determine neighboring vertices we used addition and subtraction. Vertices to the left and right are -1 and +1 respectively, and Vertices up and down are - cols and + cols. Edge weights are assigned based off the values given by the input text files. I stored all edges inside the 2D vector named graph. I stored all the weights inside a map keyed by the char and valued by the weight. I kept a visited vector to mark what nodes I have visited. I also kept track of all parents using the Parents vector. I also kept track of the distances from the starting node using the distance vector. To find the values for the index of neihgboring vertices I kept track of my current index and calculated their values as stated above. I also hold on to a map named current_path that holds all possible paths we can move to. 


2) 

To read in our graph and store the values it would be a time complexity of O(N^2) with N representing the width.
When moving to a new vertex checking new possible paths is O(1), and inserting them into the current_paths map is nlog(n).
Attempting to find a genuine path we loop through the map current_path until we find a vertix we havent visited will be a time complexity of O (V*E) which is the maxiumum number of edges that we can possibly visit.

3)
Our program is able to handle small graphs quite adequately, however as soon as we enter graphs that are larger then 500 X 500 our program slows down. We can see this in our table where all graphs with a width smaller than 100 took less then a second to complete, but when we take a look at our larger graphs like ones with a width of 1000 we see that it took almost five minutes to complete. 

All members contributed to this project and we both helped test and record our dijkstras program.