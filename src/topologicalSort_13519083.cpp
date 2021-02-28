#include<iostream>
#include<string> // string
#include<iterator> // size
#include<vector> // vector

#include "topologicalSort_13519083.h"
using namespace std;

/*
    < Topological Sort >
    Will decreas graph size for every vertrices with zero in degree
    The resulted vector is classified as semesters
*/
vector<vector<Vertex>> topologicalSort(Graph myGraph) {
    vector<vector<Vertex>> result;
    while (myGraph.getVertices() > 0) {
        vector<Vertex> temp = getZeroInDegree(myGraph);
        result.push_back(temp);

        for (int i = 0; i < temp.size(); i++){
            myGraph.removeVertex(temp[i]);
        }

    }

    return result;
}

/*
    < Get Zero In Degree >
    Get all vetrices with zero in degree
*/
vector<Vertex> getZeroInDegree(Graph graph) {
    vector<Vertex> result; 
    vector<Vertex> vertexVector = graph.getVertex();

    for (auto& v : vertexVector) {
        if (graph.countInDegree(v) == 0) {
            result.push_back(v);
        }
    }

    return result;
}

/*
    < Print Topological Search Result >
    Print result with the semester format
*/
void printTopoResult(vector<vector<Vertex>> topoResult) {
    for (int semester = 0; semester < topoResult.size(); ++semester) {
        cout << "Semester " << convertIntToRoman(semester+1) << " : ";
        for (int course = 0; course < topoResult[semester].size(); ++course) {
            if (course != topoResult[semester].size()-1) {
                cout << topoResult[semester][course].content << ", ";
            } else {
                cout << topoResult[semester][course].content << endl;
            }
        }
    }
}

/*
    < Convert Integer to Roman >
    Convert numeric form to roman numerals
*/
string convertIntToRoman(int value) {
    vector<string> romans = {"X", "IX", "V", "IV", "I"};
    vector<int> integer = {10, 9, 5, 4, 1};

    string result = "";
    for (auto i = 0; i < integer.size(); i++) {
        while (value - integer[i] >= 0) {
            result+= romans[i];
            value-= integer[i];
        }
    }
    return result;
}