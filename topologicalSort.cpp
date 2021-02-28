#include<iostream>

#include "topologicalSort.h"
using namespace std;

vector<vector<Vertex>> topologicalSort(Graph myGraph) {
    vector<vector<Vertex>> result;
    while (myGraph.getVertices() > 0) {
        cout << "before zero in" << endl;
        myGraph.printGraph();
        vector<Vertex> temp = getZeroInDegree(myGraph);
        cout << "after zero in my" << endl;
        myGraph.printGraph();
        cout << "hiya error" << endl;
        result.push_back(temp);

        for (int i = 0; i < temp.size(); i++){
            cout << "Remove: " << temp[i].content << endl;
            myGraph.removeVertex(temp[i]);
        }
        myGraph.printGraph(); myGraph.printVertex();
    }

    return result;
}

vector<Vertex> getZeroInDegree(Graph graph) {
    vector<Vertex> result; 
    vector<Vertex> vertexVector = graph.getVertex();

    for (auto it = vertexVector.begin(); it != vertexVector.end(); ++it) {
        if (graph.countInDegree(*it) == 0) {
            result.push_back(*it);
            cout << "inside if" << endl;
            cout << it->content << " " << it->id << endl;
            cout << it->content << " in degree " << graph.countInDegree(*it) << endl;
            graph.printGraph();
            cout << endl;
        }
    }

    cout << "resultt" << endl;
    graph.printGraph();
    cout << "result size: " << result.size() << endl << endl;

    return result;
}

void printTopoResult(vector<vector<Vertex>> topoResult) {
    for (int semester = 0; semester < topoResult.size(); ++semester) {
        cout << "Semester " << semester+1 << ":";
        for (int course = 0; course < topoResult[semester].size(); ++course) {
            if (course != topoResult[semester].size()-1) {
                cout << topoResult[semester][course].content << ", ";
            } else {
                cout << topoResult[semester][course].content << endl;
            }
        }
    }
}
