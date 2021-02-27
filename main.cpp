#include<iostream>
#include<vector>
#include<string>
#include<sstream>

#include "Graph.cpp" // Graph Class
#include "filesProcessing.cpp" // filesToGraph
using namespace std;

int main(int argc, const char** argv) {
    cout << "Welcome :D" << endl;
    cout << "Enter filename: ";
    string filename; cin >> filename;
    cout << "File name is " << filename << endl;

    Graph myGraph = filesToGraph(filename);

    myGraph.printGraph();
    myGraph.printVertex();  

    return 0;
}