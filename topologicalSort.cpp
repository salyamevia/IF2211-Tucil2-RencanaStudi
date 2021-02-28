#include<iostream>

#include "topologicalSort.h"
using namespace std;

vector<vector<Vertex>> topologicalSort(Graph myGraph) {
    vector<vector<Vertex>> result;
    while (myGraph.getVertices() > 0) {
        vector<Vertex> temp = getZeroInDegree(myGraph);
        result.push_back(temp);

        for (int i = 0; i < temp.size(); i++){
            cout << "Remove: " << temp[i].content << endl;
            myGraph.removeVertex(temp[i]);
        }

        cout << "Current Result: " << endl;
        for(auto& res : result){
            for(auto& v : res) {
                cout << v.content << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return result;
}

vector<Vertex> getZeroInDegree(Graph graph) {
    vector<Vertex> result; 
    vector<Vertex> vertexVector = graph.getVertex();

    graph.printGraph();

    cout << "Indegree" << endl;
    for (auto& v : vertexVector) {
        if (graph.countInDegree(v) == 0) {
            result.push_back(v);
        }

        cout << v.content << " indegree " << graph.countInDegree(v) << endl;
    }


    return result;
}

void printTopoResult(vector<vector<Vertex>> topoResult) {
    for (int semester = 0; semester < topoResult.size(); ++semester) {
        cout << "Semester " << semester+1 << " : ";
        for (int course = 0; course < topoResult[semester].size(); ++course) {
            if (course != topoResult[semester].size()-1) {
                cout << topoResult[semester][course].content << ", ";
            } else {
                cout << topoResult[semester][course].content << endl;
            }
        }
    }
}
