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

    vector<Vertex> graphVertrices = myGraph.getVertex();
    /*
    cout << "Remove " << graphVertrices[1].content << endl;
    myGraph.removeVertex(graphVertrices[1]);

    myGraph.printGraph();
    myGraph.printVertex();   */
    
    vector<vector<Vertex>> result = topologicalSort(myGraph);
    printTopoResult(result); 

    cout << "graph method" << endl;
    for(auto& v : graphVertrices){
        cout << v.content << " indegree: " << myGraph.countInDegree(v) << endl; 
    }

    return 0;
}