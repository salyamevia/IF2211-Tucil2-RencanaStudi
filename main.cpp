#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<regex>

#include "Graph.cpp" // Graph Class
#include "filesProcessing.cpp" // filesToGraph
#include "topologicalSort.cpp" // topologicalSort, printTopoResult
using namespace std;

int main(int argc, const char** argv) {
    cout << "Welcome :D" << endl;
    cout << "Enter filename: ";
    string filename; cin >> filename;
    cout << "File name is " << filename << endl;

    Graph myGraph = filesToGraph(filename);
    myGraph.printGraph();
    myGraph.printVertex();  

    cout << endl << endl;
    
    vector<vector<Vertex>> result = topologicalSort(myGraph);
    printTopoResult(result); 

    return 0;
}