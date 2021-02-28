#ifndef FILESPROCESSING_13519083_H
#define FILESPROCESSING_13519083_H

#include <iostream>
#include "Graph_13519083.h"
using namespace std;

Graph filesToGraph(string filename);
vector<Vertex> filesToVertex(string filename);
int countFileLine(string filename);

bool isCommaSpaceDot(char c);
string removeSpace(string str);


#endif // !FILESPROCESSING_13519083_H