// dijsktras.cpp
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
    int Tile_n, cost, r,c, d, rows,cols,index,total_weight;
    char symbol, right,down,up,left; 
    map < char, int> tiles; // a map of the tile costs keyed by their chars
    vector < vector < char > > graph; //char graph
    pair <int,int> current;//x,y
    pair <int,int> ending;
    pair <int,int> starting;
    map < int, pair <int,int>> marked; // distance, coordinates
    map < int, pair <int,int>>:: iterator it; 
    multimap <int , int> current_paths; //distance,index
    multimap <int, int>:: iterator till;
    vector <int> distances;
    vector <int> visited;
    vector <pair<int,int>> parents;




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
    current = make_pair(r,c);
    starting = current;
    cin >> r >> c;
    ending = make_pair(r,c);

    
    distances.resize(rows*cols, INT_MAX);
    distances[current.first*cols + current.second]= 0;
    marked.insert(make_pair(0, current));
    visited.resize(rows*cols,0);
    visited[current.first*cols+current.second] = 1;
    parents.resize(rows*cols);
    parents[current.first*cols+current.second] = current;

    while(true){ // keep looping until we find the shortest path to our ending node
        
        index = current.first*cols + current.second;

        //update right node
        if(index%cols != cols-1){ // if there is a node to the right
            right = graph[current.first][current.second+1]; // find the weight of the node
            d = distances[index] + tiles.find(right)->second; //find its distance from the current node
            if(distances[index+1] > d){ // update distance if new found distance is smaller and push it into current_paths
                distances[index+1] = d;
                current_paths.insert(make_pair(d,index+1));
                parents[index+1] = current;//update parent edge
            }
        }
        // update left node 
         if(index%cols != 0){ // if there is a node to the left
            left = graph[current.first][current.second-1]; // find the weight of the node
            d = distances[index] + tiles.find(left)->second; //find its distance from the current node
            if(distances[index-1] > d){ // update distance if new found distance is smaller and push it into current_paths
                distances[index-1] = d;
                current_paths.insert(make_pair(d,index-1));
                parents[index-1] = current; //update parents edge
            }
        }


        //update node below 

        
         if(index/cols != rows-1){ // if there is a node below
            down = graph[current.first+1][current.second]; // find the weight of the node
            d = distances[index] + tiles.find(down)->second; //find its distance from the current node
            if(distances[index+cols] > d){ // update distance if new found distance is smaller and push it into current_paths
                distances[index+cols] = d;
                current_paths.insert(make_pair(d,index+cols));
                parents[index+cols] = current;// update parents edge
            }
        }


        //update node above 
        if(index/cols != 0){ // if there is a node above
            up = graph[current.first-1][current.second]; // find the weight of the node
            d = distances[index] + tiles.find(up)->second; //find its distance from the current node
            if(distances[index-cols] > d){ // update distance if new found distance is smaller and push it into current_paths
                distances[index-cols] = d;
                current_paths.insert(make_pair(d,index-cols));
                parents[index-cols] = current; //update parents edge
            }
        }


    //finding the right node to move to 
    //which one has the least distance and is not visited

    //loop through current paths untill we find one that is not already in our map marked
    for(till = current_paths.begin(); till != current_paths.end(); till++){ //loop through from smallest to greatest value

        if(visited[index-(index-till->second)] != 1){ //if we haven't visited it
            index = till -> second; 
            current.first = index/cols; // find new row
            current.second = index%cols; // find new cols
            break;
        }
        
    }
    marked.insert(make_pair(till->first, current)); //push it back
    total_weight = till->first; //update weight
    visited[current.first*cols+current.second] = 1;
    current_paths.clear();
    
    if (current == ending) break; // if we find the desired node exit while loop

}

    
    
     //printing
     //TODO
     
   
    
    
    





return 0;
}