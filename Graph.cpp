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

    /* // Add vertex to vertex vector if not exists
    if (find(this->vertex.begin(), this->vertex.end(), destination) == this->vertex.end()) {
        this->vertex.push_back(destination);
    }
    if (find(this->vertex.begin(), this->vertex.end(), source) == this->vertex.end()) {
        this->vertex.push_back(source);
    } */
}

void Graph::removeEdge(Vertex source, Vertex destination) {
    for (int i = 0; i < this->graph[getVertexId(this->vertex, source.content)].size(); i++) {
        //cout << "From " << this->graph[getVertexId(this->vertex, source.content)][i].content << " " << this->graph[getVertexId(this->vertex, source.content)][i].id;
        if(isContentSame(this->graph[getVertexId(this->vertex, source.content)][i], destination)) {
            //cout << " remove " << destination.content << endl; //
            this->graph[getVertexId(this->vertex, source.content)].erase(
                this->graph[getVertexId(this->vertex, source.content)].begin() + i
            );
            break;
        } /* else {
            cout << endl;
        } */
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

    /* this->printGraph();
    this->printVertex(); */

    // Update Vertex Id and Graph
    //cout << "update verted id and graph" << endl;
    for (int i = getVertexId(this->vertex, vertex.content); i < this->nVertices; i++) {
        /* cout << "vertex " << getVertexId(this->vertex, vertex.content) << " " << vertex.content << endl;
        cout << "change: " << this->vertex[i].content << " " << this->vertex[i].id << endl;   */  
        if (this->vertex[i].id > getVertexId(this->vertex, vertex.content)){
            this->vertex[i].id--;
            //cout << "to: " << this->vertex[i].content << " " << this->vertex[i].id << endl;    
        }
        if (i+1 != this->nVertices) {
            this->graph[i] = this->graph[i+1];
        }
        //cout << this->vertex[i].content << " " << this->vertex[i].id << endl;
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
    //cout << " remove from Vertex List" << endl;
    int index;
    for (int i = 0; i < this->nVertices; i++) {
        if (isContentSame(this->vertex[i], vertex)){
            index = i;
        }
    }
    this->vertex.erase(this->vertex.begin() + index);
    this->nVertices--;

    /* for (int i = 0; i < this->nVertices; i++){
        cout << this->vertex[i].content << " " << this->vertex[i].id << endl;
    } */
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
    //cout << "vertex to check: " << vertex.content << endl;
    for (int i = 0; i < this->nVertices; i++) {
        for(auto v : this->graph[i]) {
            //cout << "sama ga?" << v.content << endl;
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
