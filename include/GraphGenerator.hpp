#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

class Graph{

    private:
        vector<vector<float>> matrix;
        vector<string> keys;
        unordered_map<string, int> keyToIndexMap;
        pair<int,int> get_indices_from_keys(string u, string v);
        void create_hash_map();

    public:
        Graph(int n); //Constructor
        void set_key(vector<string> keys);
        void add_edge_using_index(int u, int v, float weight);
        void add_edge_using_key(string u, string v, float weight);
        float get_edge_using_index(int u, int v);
        float get_edge_using_key(string u, string v);
        void print_matrix();

};