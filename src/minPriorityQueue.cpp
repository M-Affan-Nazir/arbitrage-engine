#include <queue>
#include <functional>
#include <string>
#include <minPriorityQueue.hpp>
using namespace std;

MinPQ::MinPQ(){}

void MinPQ::addNode(int index, int predIndex, float distance){
    this->minPQ.push(Node(index, predIndex, distance));
}

Node MinPQ::extractMinAndPop(){
    Node minElement = this->minPQ.top();
    this->minPQ.pop();
    return minElement;
}

void MinPQ::adjustNode(int index, float newDistance){   //to be revised
    vector<Node> temp;

    while(!minPQ.empty()){
        Node top = minPQ.top();
        minPQ.pop();

        if(top.index == index){
            top.distance = newDistance;
        }
        temp.push_back(top);
    }
    for(auto &node : temp){
        minPQ.push(node);
    }
}