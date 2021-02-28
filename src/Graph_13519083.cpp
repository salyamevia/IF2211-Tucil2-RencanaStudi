#include <iostream>
#include<vector> // Vector 
#include<string> // String
#include <algorithm> // Find

#include "Graph_13519083.h"
using namespace std;

// Constructor
Graph::Graph(int vertrices) {
    this->nVertices = vertrices;
    this->graph = new vector<Vertex>[vertrices];
}

// Copy Constructor
Graph::Graph(const Graph& other) {
    this->nVertices = other.nVertices;
    this->graph = new vector<Vertex>[this->nVertices];
    for(int i = 0; i < this->nVertices; i++) {
        for(auto& v : other.graph[i]) {
            this->graph[i].push_back(v);
        }
    }

    for(auto& v : other.vertex) {
        this->vertex.push_back(v);
    }
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

vector<Vertex>* Graph::getGraph() {
    return this->graph;
}

vector<Vertex> Graph::getVertex() {
    return this->vertex;
}

// Methods
void Graph::addEdge(Vertex source, Vertex destination) {
    this->graph[source.id].push_back(destination);
}

void Graph::removeEdge(Vertex source, Vertex destination) {
    for (int i = 0; i < this->graph[getVertexId(this->vertex, source.content)].size(); i++) {
        if(isContentSame(this->graph[getVertexId(this->vertex, source.content)][i], destination)) {
            this->graph[getVertexId(this->vertex, source.content)].erase(
                this->graph[getVertexId(this->vertex, source.content)].begin() + i
            );
            break;
        } 
    }
}

void Graph::addVertex(Vertex vertex) {
    this->vertex.push_back(vertex);    
}

void Graph::removeVertex(Vertex vertex) {
    // Remove All Edges 
    for (int i = 0; i < this->nVertices; i++) {
        for(int j = 0; j < this->graph[i].size(); j++) {
            Vertex v = this->graph[i][j];
            if (isContentSame(vertex, v)){
                this->removeEdge(this->findVertex(i), vertex);
            } else {
                this->removeEdge(vertex, this->findVertex(i));
            }
        }
    }

    // Update Vertex Id and Graph
    for (int i = getVertexId(this->vertex, vertex.content); i < this->nVertices; i++) {
        if (this->vertex[i].id > getVertexId(this->vertex, vertex.content)){
            this->vertex[i].id--;
        }
        if (i+1 != this->nVertices) {
            this->graph[i] = this->graph[i+1];
        }
    };

    // Update edges
    for (int i = 0; i < this->nVertices; i++) {
        for(auto& e : this->graph[i]) {
            for(auto& v : this->vertex) {
                if (isContentSame(v, e)) {
                    e.id = v.id;
                }
            }
        }
    }

    // Remove from Vertex List
    int index;
    for (int i = 0; i < this->nVertices; i++) {
        if (isContentSame(this->vertex[i], vertex)){
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
            if (isContentSame(v, vertex)) {
                inDegree++;
            }
        }
    }

    return inDegree;
}

void Graph::printGraph() {
    for(int i = 0; i < this->nVertices; i++) {
        cout << "Vertex " << this->findVertex(i).content << " " << i << " :";
        for (auto& v : this->graph[i]) {
            cout << " -> " << v.content << " " << v.id;
        }
        cout << endl;
    }
}

void Graph::printVertex() {
    for(auto& v : this->vertex) {
        cout << "Vertex " << v.content << " with id " << v.id << endl;
    }
}
