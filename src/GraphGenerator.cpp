#include <vector>
#include <string>
using namespace std;
#include <GraphGenerator.hpp>
#include <iostream>
#include <queue>
#include <functional>
#include <minPriorityQueue.hpp>
#include <limits>
#include <cmath>

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

void Graph::dijkstra(string u, string v){

    //Filling MinPQ
    MinPQ minPQ = MinPQ();
    for(int i = 0; i<this->keys.size(); i++){
        string key = this->keys[i];
        if(key == u){
            minPQ.addNode(i,-1,0);
        }
        else{
            minPQ.addNode(i,-1,numeric_limits<float>::infinity());
        }
    }

    //Dijsktra:
    while(!minPQ.empty()){
        Node μ = minPQ.extractMinAndPop();
        vector<string> neighbours = this->get_neighbours(this->get_key_from_index(μ.index));
        for (auto &λ : neighbours ){
            int indexInKey = this->get_index_from_key(λ);
            Node λ_node = minPQ.getNodeByIndex(indexInKey);
            if(λ_node.distance > μ.distance + this->get_edge(μ.index, λ_node.index)){
                minPQ.adjustNode(λ_node.index, μ.distance + this->get_edge(μ.index, λ_node.index), μ.index);
            }
        }
    };

    //Displaying Pathway:
    vector<int> path = minPQ.getPath(this->get_index_from_key(u), this->get_index_from_key(v));
    cout << "\n---------------------------------------\n" << endl;
    cout << "BEST EXCHANGE RATE PATH" << endl;
    cout << "\t- Pathway: ";
    for(int i = 0; i < path.size()-1; i++){
        cout << this->get_key_from_index(path[i]) << " --> ";
    }
    cout << this->get_key_from_index(path[path.size()-1]);
    cout << endl;

    //Message:
    float orignalConversion = this->get_edge(u, v);
    cout << "\t- ORIGNAL CONVERSION RATE: " << "1 " + u + " = " << exp(-orignalConversion) << " " + v << endl;

    int index = 0;
    float pathwayConversionRate = 1;
    while(index < path.size()-1){
        float rate = this->get_edge(path[index],path[index+1]);
        pathwayConversionRate = pathwayConversionRate * exp(-rate);
        index = index + 1;
    }
    //pathwayConversionRate > orignalConversion; due to -log(rate) being used as Graph's edge weight. You get more goal currency!!
    cout << "\t- BEST EXCHANGE RATE: " << "1 " + u + " = " << pathwayConversionRate << " " + v << endl;
    cout << "\t- GAIN PER " + u + ": "  <<  pathwayConversionRate - exp(-orignalConversion) << " " + v + " (" << ((pathwayConversionRate - exp(-orignalConversion))/exp(-orignalConversion))*100 << "%)" << endl;
    cout << "\n---------------------------------------\n" << endl;
}

void Graph::bellman_ford(string u){

    //filling:
    vector<Node> rates;
    for(int i = 0; i<this->keys.size(); i++){
        string key = this->keys[i];
        if(key == u){
            rates.push_back(Node(i,-1,0));
        }
        else{
            rates.push_back(Node(i,-1,numeric_limits<float>::infinity()));
        }
    }

    //Relax Edges:
    for(int i = 0; i<rates.size()-1; i++){
        
        for(int μ=0; μ<rates.size();μ++){
            for(int λ=0; λ<rates.size();λ++){

                if(this->get_edge(rates[μ].index,rates[λ].index) != -1){
                    
                    if(rates[λ].distance > rates[μ].distance + this->get_edge(rates[μ].index,rates[λ].index)){
                        rates[λ].distance = rates[μ].distance + this->get_edge(rates[μ].index,rates[λ].index);
                        rates[λ].predIndex = rates[μ].index;
                    }

                }
                

            }
        }

    }

    //Detect Negative Cycle:
    int negativeCycleIndex = -1;
    for(int μ=0; μ<rates.size();μ++){

        for(int λ=0; λ<rates.size()-1;λ++){

            if(this->get_edge(rates[μ].index,rates[λ].index) != -1){
                    
                if(rates[λ].distance > rates[μ].distance + this->get_edge(rates[μ].index,rates[λ].index)){
                    negativeCycleIndex = λ;
                    break;
                }

            }
                

        }
    }

    if(negativeCycleIndex != -1){
        
        vector<int> negativeCycle;
        
        //Back Track
        int current = negativeCycleIndex;
        for (int i = 0; i < rates.size(); i++) {
            current = rates[current].predIndex;
        }

        int start = current;
        do {
            negativeCycle.insert(negativeCycle.begin(), current);
            current = rates[current].predIndex;
        } while (current != start);

        //Output
        cout << "\n---------------------------------------\n" << endl;
        cout << "NEGATIVE WEIGHT CYCLE DETECTED!" << endl;
        cout << "PATHWAY FOR ARBITRAGE:" << endl;
        cout << "\t- ";
        for(int i = 0; i<negativeCycle.size()-1;i++){
            cout << this->get_key_from_index(negativeCycle[i]) << " --> ";
        }
        cout << this->get_key_from_index(negativeCycle[negativeCycle.size()-1]) << " --> ";
        cout << this->get_key_from_index(negativeCycle[0]);
        cout << endl;

        float initial_currency_unit = 1;
        for(int i = 0; i < negativeCycle.size(); i++){
            int from = negativeCycle[i];
            int to = negativeCycle[(i + 1) % negativeCycle.size()];
            float rate = this->get_edge(from, to);
            initial_currency_unit *= exp(-rate);
        }
        cout << "\t- Arbitrage Gain: 1 " << this->get_key_from_index(negativeCycle[0]) << " TO " << initial_currency_unit << " " << this->get_key_from_index(negativeCycle[0]) << endl;
        cout << "\n---------------------------------------\n" << endl;

    }
}