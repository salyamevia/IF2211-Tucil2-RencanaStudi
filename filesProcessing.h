#ifndef FILESPROCESSING_H
#define FILESPROCESSING_H

#include <iostream>
#include "Graph.h"
using namespace std;

Graph filesToGraph(string filename);
vector<Vertex> filesToVertex(string filename);
int countFileLine(string filename);

#endif // !FILESPROCESSING_H