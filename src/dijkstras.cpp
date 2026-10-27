// Title : dijsktras.cpp
// Names  : Abraham Rashdan & Eric Mcilrath
// email :  arashdan@vols.utk.edu and emciltat@vols.utk.edu
// Description: This program reads in a graph, and then using the dijkstra's algorithim finds the shortest path between two end points provided by the user

#include <iostream> 
#include <iomanip>
#include <map> 
#include <vector> 
#include <utility>
#include <climits>
#include <algorithm>
#include <set> 
using namespace std; 



int main(int argc, char *argv[]){
    int Tile_n, cost, r,c, d, rows,cols,index, current, starting, ending;
    char symbol, right,down,up,left; 
    map < char, int> tiles; // a map of the tile costs keyed by their chars
    multimap < int,int> current_paths; //distance, index
    multimap <int,int>:: iterator till;
    vector < vector < char > > graph; //char graph 
    vector <int> distances;
    vector <int> visited; 
    vector <int> parents;






    cin >> Tile_n;

    for(int i=0; i< Tile_n; i++) {
        cin >> symbol >> cost; 
        tiles.insert(make_pair(symbol,cost));

    }

     //creating map
    cin >> rows >> cols;
    graph.resize(rows);
    for(int i =0; i<rows; i++){
        for (int j=0; j< cols; j++){
            cin >> symbol;
            graph[i].push_back(symbol);
        }
    }
    

    //get starting and ending rows
    cin >> r >> c;
    current = r*cols+c;
    starting = current; // prgroam begins at the starting node
    cin >> r >> c;
    ending = r*cols+c;

    //fix vector sizes
    distances.resize(rows*cols, INT_MAX);
    visited.resize(rows*cols, 0); //0 = vistied 1 = unvisited
    parents.resize(rows*cols,0);

    //establish starting values
    distances[current] = 0;
    parents[starting] = starting; // set the starting node parent equal to itself
    visited[current ] = 1; // declare it as visited

    while(true){
        index = current;

        //update right node
        if(index%cols != cols-1){ // if there is a node to the right
            right = graph[current/cols][(current%cols)]; // find the weight of the node index/cols = row value index%cols = col value
            d = distances[index] + tiles.find(right)->second; // find the distance from the current node

            if(distances[index+1] > d){ // if our new found distance is smaller update it
                distances[index+1] = d; //update distance
                parents[index+1] = index; //set current node as it's new parent
                current_paths.insert(make_pair(d,index+1)); //add this as a possible path to check later

            }
            
        }

        // update left node 
         if(index%cols != 0){ // if there is a node to the left
            left = graph[current/cols][(current%cols)]; // find the weight of the node
            d = distances[index] + tiles.find(left)->second; //find its distance from the current node
            if(distances[index-1] > d){ // update distance if new found distance is smaller and push it into current_paths
                distances[index-1] = d;
                current_paths.insert(make_pair(d,index-1));
                parents[index-1] = current; //update parents edge
            }
        }

         //update node below 

        
         if(index/cols != rows-1){ // if there is a node below
            down = graph[(current/cols)][(current%cols)]; // find the weight of the node
            d = distances[index] + tiles.find(down)->second; //find its distance from the current node
            if(distances[index+cols] > d){ // update distance if new found distance is smaller and push it into current_paths
                distances[index+cols] = d;
                current_paths.insert(make_pair(d,index+cols));
                parents[index+cols] = current;// update parents edge
            }
        }


        //update node above 
        if(index/cols != 0){ // if there is a node above
            up = graph[(current/cols)][current%cols]; // find the weight of the node
            d = distances[index] + tiles.find(up)->second; //find its distance from the current node
            if(distances[index-cols] > d){ // update distance if new found distance is smaller and push it into current_paths
                distances[index-cols] = d;
                current_paths.insert(make_pair(d,index-cols));
                parents[index-cols] = current; //update parents edge
            }
        }

        for(till = current_paths.begin(); till != current_paths.end(); till++){ // go from least to greatest possible path

            if(visited[till->second] != 1 ){ // if we havent visited the node and we are able to move to it
                
                current = till->second; //move to this node
                current_paths.erase(till);//remove node from our frontier
                break; //break out of for loop
            }

        }
        
         visited[current] = 1; //declare current node as visited
        
        if (current == ending) break; // leave the loop once we have finalized our ending node
    }


    cout << distances[ending] << endl; //print the total weight

    visited.clear();//reuse visited vector to find the path

    while(current != starting){ //keep going until we reach the starting node
        
        visited.push_back(current); // go backwards and find the shortest path from the ending node to starting node
        current = parents[current]; // move to the parent
        
    }

    cout << starting/cols << ' ' << starting%cols << endl;

    for(int i = visited.size()-1; i>=0; i--) cout << visited[i] /cols << ' ' << visited[i]%cols << endl;
    

}