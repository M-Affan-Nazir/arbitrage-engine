#include <queue>
#include <functional>
#include <string>
using namespace std;

struct Node{

    int index;
    int predIndex;
    float distance;
    Node(int idx, int predIdx, float dist) : index(idx), predIndex(predIdx), distance(dist) {} //constructor

};

class MinPQ{

    private:
        struct compareDistance{
            bool operator()(Node &a, Node &b){
                return a.distance > b.distance;
            }  // allowing struct to be called as a function, overloading '()' operation. compareDistance comp(a,b) -> boolean
        };
        priority_queue<Node, vector<Node>, compareDistance> minPQ;
    public:
        MinPQ();
        void addNode(int index, int predIndex, float distance);
        Node extractMinAndPop();
        void adjustNode(int index, float newDistance);
};