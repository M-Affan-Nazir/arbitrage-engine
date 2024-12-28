#include <vector>
#include <string>
using namespace std;

class Graph{

    private:
        vector<vector<float>> matrix;
        vector<string> keys;
    public:
        Graph(int n); //Constructor
        void set_key(vector<string> keys);
        void add_edge_using_index(int u, int v, float weight);
        void add_edge_using_key(string u, string v, float weight);
        float get_edge_using_index(int u, int v);
        float get_edge_using_key(string u, string v);
        void print_matrix();

};