#ifndef GRAPH_H
#define GRAPH_H

#include<vector> // Vector 
#include<string> // String
using namespace std;

/*
    < Vertex Abstract Data Type >
    Implemented to make array processing easier
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

int getVertexId(vector<Vertex> v, string content) {
    int temp;
    for(auto& v : v) {
        if (v.content.compare(content) == 0) {
            temp = v.id;
            break;
        }
    }
    return temp;
}

Vertex findVertexById(vector<Vertex> v, int id) {
    Vertex temp;
    for(auto& v : v) {
        if (v.id == id) {
            temp = v;
            break;
        }
    }
    return temp;
}

/*
    < Graph Class > 
    Implemented using the adjacency list representation
    and vector for the realization
*/
class Graph {
    public: 
        Graph(int vertrices); 
        Graph(const Graph& other);
        ~Graph();

        int getVertices();
        void setVertices(int vertices);
        vector<Vertex>* getGraph();
        vector<Vertex> getVertex();

        void addEdge(Vertex source, Vertex destination);
        void removeEdge(Vertex source, Vertex destination);
        void removeVertex(Vertex vertex);
        Vertex findVertex(int id);
        int countInDegree(Vertex vertex);
        void printGraph();
        void printVertex();
    private:
        int nVertices;
        vector<Vertex>* graph;
        vector<Vertex> vertex;
};

#endif // !GRAPH_H