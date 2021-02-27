#include<iostream>
#include "Graph.cpp"
using namespace std;

int main(int argc, const char** argv) {
    cout << "Welcome :D" << endl;

    Vertex a; a.content = "A"; a.id = 0;
    Vertex b; b.content = "B"; b.id = 1;
    Vertex c; c.content = "C"; c.id = 2;

    Graph test(3);
    test.addEdge(a, b);
    test.addEdge(a, c);
    test.addEdge(b, c);

    test.printGraph();
    test.printVertex();

    return 0;
}