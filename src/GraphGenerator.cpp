#include <vector>
#include <string>
using namespace std;
#include <GraphGenerator.hpp>
#include <iostream>

Graph::Graph(int n){
    this->matrix = vector<vector<float>> (n, vector<float>(n, -1)); //each edge value is -1
}

void Graph::set_key(vector<string> keys){
    this->keys = keys;
}

void Graph::add_edge_using_index(int u, int v, float weight){
    this->matrix[u][v] = weight;
}

void Graph::add_edge_using_key(string u, string v, float weight){
    int index_u, index_v;
    for(int i=0;i<this->keys.size();i++){
        
        if(this->keys[i] == u){
            index_u = i;
        }
        if(this->keys[i] == v){
            index_v = i;
        }
    }
    this->matrix[index_u][index_v] = weight;
}

float Graph::get_edge_using_index(int u, int v){
    return this->matrix[u][v];
}

float Graph::get_edge_using_key(string u, string v){
    int index_u, index_v;
    for(int i=0;i<this->keys.size();i++){
        if(this->keys[i] == u){
            index_u = i;
        }
        if(this->keys[i] == v){
            index_v = i;
        }
    }
    return this->matrix[index_u][index_v];
}


void Graph::print_matrix(){
    cout << "---------------" << endl;
    for(int i = 0; i<this->matrix.size();i++){
        for(int j = 0; j<this->matrix.size();j++){
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl;
}