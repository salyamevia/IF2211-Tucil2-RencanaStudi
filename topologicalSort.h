#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include "Graph.h"

vector<vector<Vertex>> topologicalSort(Graph graph);
vector<Vertex> getZeroInDegree(Graph graph);
void printTopoResult(vector<vector<Vertex>> topoResult);

#endif // !TOPOLOGICALSORT_H