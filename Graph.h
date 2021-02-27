#ifndef GRAPH_H
#define GRAPH_H

#include<vector> // Vector 
#include<string> // String
using namespace std;

/*
    < Graph Class >
    Implemented using the adjacency list representation
    and a custom vertex data structure
*/
struct Vertex {
    int id;
    string content;

    bool operator==(const Vertex& rhs) {
        if ((this->id == rhs.id) && (this->content.compare(rhs.content) == 0)) {
            return true;
        } else {
            return false;
        }
    }
};

class Graph {
    public: 
        Graph(int vertrices); 
        ~Graph();

        int getVertices();
        void setVertices(int vertices);
        vector<Vertex> getGraph();
        vector<Vertex> getVertex();

        void addEdge(Vertex source, Vertex destination);
        Vertex findVertex(int id);
        void printGraph();
        void printVertex();
    private:
        int nVertices;
        vector<Vertex>* graph;
        vector<Vertex> vertex;
};

#endif // !GRAPH_H