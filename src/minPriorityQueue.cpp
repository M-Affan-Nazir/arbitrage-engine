#include <queue>
#include <functional>
#include <string>
#include <minPriorityQueue.hpp>
#include <iostream>
using namespace std;

MinPQ::MinPQ(){}

void MinPQ::addNode(int index, int predIndex, float distance){
    this->minPQ.push(Node(index, predIndex, distance));
}

Node MinPQ::extractMinAndPop(){
    Node minElement = this->minPQ.top();
    this->visitedNodes.push_back(minElement);
    this->minPQ.pop();
    return minElement;
}

void MinPQ::adjustNode(int index, float newDistance, int predIdx){   //to be revised
    vector<Node> temp;

    while(!this->minPQ.empty()){
        Node top = minPQ.top();
        minPQ.pop();

        if(top.index == index){
            top.distance = newDistance;
            top.predIndex = predIdx;
        }
        temp.push_back(top);
    }
    for(auto &node : temp){
        minPQ.push(node);
    }
}

bool MinPQ::empty(){
    return this->minPQ.empty();
}

Node MinPQ::getNodeByIndex(int index){ //to be revised to HashMap
    vector<Node> temp;
    Node result(-1,-1,-1);

    while(!this->minPQ.empty()){
        Node top = minPQ.top();
        minPQ.pop();

        if(top.index == index){
            result = top;
        }
        temp.push_back(top);
    }

    for (auto &node : temp) {
        minPQ.push(node);
    }

    return result;

}

vector<int> MinPQ::getPath(int u, int v){
    vector<int> path;
    Node current(-1,-1,-1);
    
    for(int i = 0; i<this->visitedNodes.size(); i++){
            if(this->visitedNodes[i].index == v){
                current = visitedNodes[i];  //current holds 'v'
                path.insert(path.begin(), current.index);   //add 'v'
                break;
            }
    }

    while(current.index != u){
        //Add Path
        path.insert(path.begin(), current.predIndex); // add v's predecessor BEFORE 'v'

        //Update 'current' to predecessor
        for(int i = 0; i<this->visitedNodes.size(); i++){
            if(this->visitedNodes[i].index == current.predIndex){
                current = visitedNodes[i];  //current holds 'v'
            }
        }
    }

    return path;

}