// Title : dijsktras.cpp
// Name  : Abraham Rashdan & Eric Mcilrath
// email : arashdan@vols.utk.edu & emciltat@vols.utk.edu
// Description: This program generates a graph to test my dijkstras algorithim in dijkstras.cpp. 

#include <iomanip> 
#include <iostream>
#include <vector> 
#include <fstream>

/*
For my random generator I will use the following characters with their corresponding values: 
f 3
g 1
G 2
h 4
m 7
r 5
*/

using namespace std;
int main(){
    int N, random; 
    vector <char> symbols; 
    vector <char> graph; 
    


    symbols.push_back('f');
    symbols.push_back('g');
    symbols.push_back('G');
    symbols.push_back('h');
    symbols.push_back('m');
    symbols.push_back('r');

    
    while(cin >> N) {

        //begin with a fresh graph and text file
        graph.clear();
        ofstream file ("tester_map.txt");

        //create the graph
        for(int i=0; i< (N*N); i++) {
            random = rand() % symbols.size(); // a random index of symbols
            graph.push_back(symbols[random]); // insert into our graph
        }

        //create a text file to output to our dijkstras algoirthim 

        //graph specs
        file << 6 << endl;
        file << "f " << 3 << endl;
        file << "g " << 1 << endl;
        file << "G " << 2 << endl;
        file << "h " << 4 << endl;
        file << "m " << 7 << endl; 
        file << "r " << 5 << endl;
        file << N << ' ' << N << endl;

        //graph itself

        for(int i= 0; i< N; i++){ // rows
            
            for(int j=0; j<N; j++) file << graph[i*N +j] << ' '; // cols

            file << endl;

        }

        //starting node 
        file << rand() % (N) << ' ' << rand() % (N) << endl;

        // ending node 

        file << rand() % (N) << ' ' << rand() % (N) << endl;

    }

return 0;
}