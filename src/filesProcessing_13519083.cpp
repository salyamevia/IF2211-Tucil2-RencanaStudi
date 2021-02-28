#include <iostream>
#include<fstream> // ifstream
#include<sstream> // stringstream
#include <vector> // vector
#include<algorithm> // erase, remove_if

#include "Graph_13519083.h"
#include "filesProcessing_13519083.h"
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
        line = removeSpace(line);

        // Seperate by commas
        vector<string> vertrices;
        stringstream ss(line);

        while(ss.good()) {
            string substr;
            getline(ss, substr, ',');
            vertrices.push_back(substr);
        }

        // Get and Add Vertex
        string firstContent = vertrices[0];
        Vertex first = findVertexById(vertexList,
                            getVertexId(vertexList, firstContent)
                        );
        fileGraph.addVertex(first);

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
        line = removeSpace(line);

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

/*  
    Additional Helper Functions
*/
int countFileLine(string filename) {
    ifstream file(filename); 

    int lineCount = 0; string line;
    while(getline(file, line)) {
        lineCount++;
    }

    file.close();

    return lineCount;
}

bool isCommaSpaceDot(char c) {
   return c == ' ' || c == ',' || c == '.';
}

string removeSpace(string str) {
    string result = ""; char last = ' ';
    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] != ' ' ||
            (!isCommaSpaceDot(last) &&
            i < str.length()-1 && !isCommaSpaceDot(str[i+1])))
        {
            result += str[i];
            last = str[i];
        }
    }
    return result;
}