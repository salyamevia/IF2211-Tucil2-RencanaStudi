#include <iostream>
#include<vector> // Vector 
#include<string> // String
#include <algorithm> // Find

#include "Graph.h"
using namespace std;

// Constructor
Graph::Graph(int vertrices) {
    this->nVertices = vertrices;
    this->graph = new vector<Vertex>[vertrices];
}

// Destructor
Graph::~Graph() {
    delete[] graph;
}

// Getter - Setter
int Graph::getVertices() {
    return this->nVertices;
}

void Graph::setVertices(int vertices) {
    this->nVertices = vertices;
}

vector<Vertex> Graph::getGraph() {
    return *this->graph;
}

vector<Vertex> Graph::getVertex() {
    return this->vertex;
}

// Methods
void Graph::addEdge(Vertex source, Vertex destination) {
    this->graph[source.id].push_back(destination);

    // Add vertex to vertex vector if not exists
    if (find(this->vertex.begin(), this->vertex.end(), destination) == this->vertex.end()) {
        this->vertex.push_back(destination);
    }
    if (find(this->vertex.begin(), this->vertex.end(), source) == this->vertex.end()) {
        this->vertex.push_back(source);
    }
}

void Graph::removeEdge(Vertex source, Vertex destination) {
    for (int i = 0; i < this->graph[source.id].size(); i++) {
        if(this->graph[source.id][i] == destination) {
            this->graph[source.id].erase(
                this->graph[source.id].begin() + i
            );
            break;
        }
    }
}

void Graph::removeVertex(Vertex vertex) {
    // Remove All Edges 
    for (int i = 0; i < this->nVertices; i++) {
        for(auto& v : this->graph[i]) {
            if (v == vertex){
                this->removeEdge(this->findVertex(i), vertex);
            } else {
                this->removeEdge(vertex, this->findVertex(i));
            }
        }
    }

    // Update Vertex Id and Graph
    for (int i = vertex.id; i < this->nVertices; i++) {
        if (this->vertex[i].id != vertex.id){
            this->vertex[i].id--;
        }
        if (i+1 != this->nVertices) {
            this->graph[i] = this->graph[i+1];
        }
    };

    // Remove from Vertex List
    int index;
    for (int i = 0; i < this->nVertices; i++) {
        if (this->vertex[i] == vertex){
            index = i;
        }
    }
    this->vertex.erase(this->vertex.begin() + index);
    this->nVertices--;
}

Vertex Graph::findVertex(int id) {
    Vertex found;
    for(auto v : this->vertex) {
        if (v.id == id) {
            found = v;
            break;
        }
    }
    return found;
}

int Graph::countInDegree(Vertex vertex) {
    int inDegree = 0;
    for (int i = 0; i < this->nVertices; i++) {
        for(auto v : this->graph[i]) {
            if (v == vertex) {
                inDegree++;
            }
        }
    }
    return inDegree;
}

void Graph::printGraph() {
    for(int i = 0; i < this->nVertices; i++) {
        cout << "Vertex " << this->findVertex(i).content << " :";
        for (auto& v : this->graph[i]) {
            cout << " -> " << v.content;
        }
        cout << endl;
    }
}

void Graph::printVertex() {
    for(auto& v : this->vertex) {
        cout << "Vertex " << v.content << " with id " << v.id << endl;
    }
}
