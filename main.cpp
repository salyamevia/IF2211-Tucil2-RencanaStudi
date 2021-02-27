#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<regex>

#include "Graph.cpp" // Graph Class
#include "filesProcessing.cpp" // filesToGraph
using namespace std;

int main(int argc, const char** argv) {
    cout << "Welcome :D" << endl;
    cout << "Enter filename: ";
    string filename; cin >> filename;
    cout << "File name is " << filename << endl;

    Graph myGraph = filesToGraph(filename);
    vector<Vertex> graphVertrices = myGraph.getVertex();

    myGraph.printGraph();
    myGraph.printVertex();  

    cout << "Remove " << graphVertrices[1].content << endl;
    myGraph.removeVertex(graphVertrices[1]);

    myGraph.printGraph();
    myGraph.printVertex();  

    return 0;
}