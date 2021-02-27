#include <iostream>
#include<fstream> // ifstream
#include<sstream> // stringstream
#include <vector> // vector
#include<algorithm> // erase, remove_if

#include "Graph.h"
#include "filesProcessing.h"
using namespace std;

/* 
    Opens a file then converts it to
    graph format
*/
Graph filesToGraph(string filename) {
    // Get Vertex Count and List
    vector<Vertex> vertexList = filesToVertex(filename);
    int vertexCount = countFileLine(filename);

    ifstream file(filename); 

    // Make Graph
    Graph fileGraph(vertexCount);

    // Convert to Graph
    int id = 0; string line;
    while(getline(file, line)) {
        // Remove dots and space
        line.erase(remove(line.begin(), line.end(), '.'), line.end());
        line.erase(remove(line.begin(), line.end(), ' '), line.end());

        // Seperate by commas
        vector<string> vertrices;
        stringstream ss(line);

        while(ss.good()) {
            string substr;
            getline(ss, substr, ',');
            vertrices.push_back(substr);
        }

        // Get Vertex
        string firstContent = vertrices[0];
        Vertex first = findVertexById(vertexList,
                            getVertexId(vertexList, firstContent)
                        );

        // Add edges
        auto it = vertrices.begin(); ++it;
        while (it != vertrices.end()) {
            Vertex temp = findVertexById(vertexList,
                            getVertexId(vertexList, *it)
                        );
            fileGraph.addEdge(temp, first);
            ++it;
        }
    }

    file.close();
    
    return fileGraph;
}
 
/*
    Opens a file then convert to 
    unique vertex
*/
vector<Vertex> filesToVertex(string filename) {
    ifstream file(filename); 
    vector<string> vertrexContents;

    // Get Vertex
    string line;
    while(getline(file, line)) {
        // Remove dots and space
        line.erase(remove(line.begin(), line.end(), '.'), line.end());
        line.erase(remove(line.begin(), line.end(), ' '), line.end());

        // Seperate by commas
        vector<string> vertrices;
        stringstream ss(line);

        while(ss.good()) {
            string substr;
            getline(ss, substr, ',');
            vertrices.push_back(substr);
        }

        // Insert unique values to vertrexContents
        for (auto& v : vertrices) {
            if (find(vertrexContents.begin(), vertrexContents.end(), v) == vertrexContents.end()) {
                vertrexContents.push_back(v);
            }
        }
    }

    // Convert to Vertex
    vector<Vertex> result; int id = 0;
    for (auto& content : vertrexContents) {
        Vertex temp; temp.id = id;
        temp.content = content;
        result.push_back(temp);
        id++;
    }
    
    file.close();

    return result;
}

int countFileLine(string filename) {
    ifstream file(filename); 

    int lineCount = 0; string line;
    while(getline(file, line)) {
        lineCount++;
    }

    file.close();

    return lineCount;
}