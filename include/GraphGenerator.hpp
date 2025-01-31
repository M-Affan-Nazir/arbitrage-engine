#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <functional>
using namespace std;

class Graph{

    private:
        vector<vector<float>> matrix;
        unordered_map<string, int> keyToIndexMap;
        unordered_map<int, string> indexToKeyMap;
        pair<int,int> get_indices_from_keys(string u, string v);
        void create_hash_maps();
        int get_index_from_key(string u);
        string get_key_from_index(int u);
        vector<string> get_neighbours(int u);
        vector<string> get_neighbours(string u);
        
    public:
        vector<string> keys;
        Graph(int n); //Constructor
        void set_key(vector<string> keys);
        void add_edge(int u, int v, float weight);
        void add_edge(string u, string v, float weight); //Overloaded
        float get_edge(int u, int v);
        float get_edge(string u, string v); //Overloaded
        void print_matrix();
        void dijkstra(string u, string v);
        void bellman_ford(string u);
        bool check_negative_weight_cycle(string u);
};