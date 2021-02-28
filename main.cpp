#include<iostream>
#include<limits> // try catch

#include "Graph.cpp" // Graph Class
#include "filesProcessing.cpp" // filesToGraph
#include "topologicalSort.cpp" // topologicalSort, printTopoResult
using namespace std;

void run();
int handleExit();

int main() {
    int pilihan;
    cout << " ___                            _      " << endl;
    cout << "| _ \\___ _ _  __ __ _ _ _  __ _(_)_ _  " << endl;
    cout << "|   / -_) ' \\/ _/ _` | ' \\/ _` | | ' \\ " << endl;
    cout << "|_|_\\___|_||_\\__\\__,_|_||_\\__,_|_|_||_|" << endl;
    cout << "Selamat datang di Rencanain! Dimana kamu bisa tahu mata kuliah tiap semesternya" << endl;
    cout << "berdasarkan pilihan mata kuliah kamu dengan prerequisites-nya!" << endl;
    cout << endl; 

    run();
    cout << endl;
    pilihan = handleExit();
    while (pilihan != 2) {
        if (pilihan == 1) {
            run();
            cout << endl;
            pilihan = handleExit();
        }
    }

    cout << "Terima kasih sudah menggunakan Rencanain! Semoga lulus kuliahnya :)" << endl;

    return 0;
}

void run() {
    cout << "Apabila file berada di dalam folder maka bisa menggunakan relative path, misalnya './test/test8.txt'" << endl;
    cout << "Masukkan nama file : ";
    string filename; cin >> filename;

    Graph myGraph = filesToGraph(filename);
    /* myGraph.printGraph();
    myGraph.printVertex();  */

    cout << endl << endl; 
    
    vector<vector<Vertex>> result = topologicalSort(myGraph);

    cout << "Rencana Studi Semestermu adalah..." << endl;
    printTopoResult(result); 
}

int handleExit() {
    int pilihan; bool pilihanBenar = false;
    while (!pilihanBenar){
        cout << "Apakah kamu masih ingin menggunakan Rencanain? (Masukkan angkanya ya!)" << endl;
        cout << "1. ya" << endl;
        cout << "2. keluar" << endl;
        cout << "Pilihan: " << endl; 
        cin >> pilihan;
        cout << endl;

        if (cin.fail()) {
            cout << "Wah, mohon masukkan angka saja ya! Mohon coba lagi." << endl; 
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else if (pilihan < 1 || pilihan > 2) {
            cout << "Ups, sepertinya anda tidak memasukkan pilihan yang tepat. Mohon coba lagi." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else {
            pilihanBenar = true;
        }
    }

    return pilihan;
}