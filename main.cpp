#include <GraphGenerator.hpp>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    
    Graph graph = Graph(8);
    vector<string> k = {"a","b","c","d","e","f","g","h"};
    graph.set_key(k);
    float x = graph.get_edge_using_index(5,5);
    cout << x << endl;
    graph.add_edge_using_index(5,5,100);
    x = graph.get_edge_using_index(5,5);
    cout << x << endl;

    string a = "e";
    string b = "e";
    graph.add_edge_using_key(a,b,200);
    float y = graph.get_edge_using_key(a,b);
    cout << y << endl;
}