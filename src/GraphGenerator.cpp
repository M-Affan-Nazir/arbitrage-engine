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
    this->create_hash_maps();
}

void Graph::add_edge(int u, int v, float weight){
    this->matrix[u][v] = weight;
}

void Graph::add_edge(string u, string v, float weight){
    auto indices = get_indices_from_keys(u,v);
    this->matrix[indices.first][indices.second] = weight;
}

float Graph::get_edge(int u, int v){
    return this->matrix[u][v];
}

float Graph::get_edge(string u, string v){
    auto indices = get_indices_from_keys(u,v);
    return this->matrix[indices.first][indices.second];
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

pair<int,int> Graph::get_indices_from_keys(string u, string v){
    return make_pair(this->keyToIndexMap[u], this->keyToIndexMap[v]);
}

void Graph::create_hash_maps(){
    for(int i=0; i<this->keys.size(); i++){
        this->keyToIndexMap[keys[i]] = i;
        this->indexToKeyMap[i] = keys[i];
    }
}

int Graph::get_index_from_key(string u){
    return this->keyToIndexMap[u];
}

string Graph::get_key_from_index(int u){
    return this->indexToKeyMap[u];
}

vector<string> Graph::get_neighbours(int u){
    vector<string> neighbours;
    for(int i=0; i<this->keys.size(); i++){
        if(this->matrix[u][i] != -1){
            neighbours.push_back(this->get_key_from_index(i));
        }
    }
    return neighbours;
}

vector<string> Graph::get_neighbours(string u){
    vector<string> neighbours;
    int index = this->get_index_from_key(u);
    for(int i=0; i<this->keys.size(); i++){
        if(this->matrix[index][i] != -1){
            neighbours.push_back(this->get_key_from_index(i));
        }
    }
    return neighbours;
}
