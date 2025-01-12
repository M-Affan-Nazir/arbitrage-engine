#include <currencyPairs.hpp>
#include <GraphGenerator.hpp>
#include <cmath>
#include <stdio.h>
using namespace std;

Graph getFilledGraph(){

    //Initialization
    CurrencyPairs currencies = CurrencyPairs("82f6fed8a66de96e7f6eee2c");
    currencies.fetch();
    Graph graph = Graph(currencies.get_unique_keys().size());
    graph.set_key(currencies.get_unique_keys());
    
    //Filling:
    vector<string> usdKey = currencies.getUsdKey();
    vector<float> usdEdge = currencies.getUsdEdge();

    vector<string> eurKey = currencies.getEurKey();
    vector<float> eurEdge = currencies.getEurEdge();

    vector<string> jpyKey = currencies.getJpyKey();
    vector<float> jpyEdge = currencies.getJpyEdge();

    vector<string> gbpKey = currencies.getGbpKey();
    vector<float> gbpEdge = currencies.getGbpEdge();

    vector<string> chfKey = currencies.getChfKey();
    vector<float> chfEdge = currencies.getChfEdge();

    for(int i = 0; i<usdKey.size();i++){
        graph.add_edge("USD", usdKey[i], -log(usdEdge[i]));
        graph.add_edge(usdKey[i], "USD", -log(1/usdEdge[i]));
    }
    for(int i = 0; i<eurKey.size();i++){
        graph.add_edge("EUR", eurKey[i], -log(eurEdge[i]));
        graph.add_edge(eurKey[i], "EUR", -log(1/eurEdge[i]));
    }
    for(int i = 0; i<jpyKey.size();i++){
        graph.add_edge("JPY", jpyKey[i], -log(jpyEdge[i]));
        graph.add_edge(jpyKey[i], "JPY", -log(1/jpyEdge[i]));
    }
    for(int i = 0; i<gbpKey.size();i++){
        graph.add_edge("GBP", gbpKey[i], -log(gbpEdge[i]));
        graph.add_edge(gbpKey[i], "GBP", -log(1/gbpEdge[i]));
    }
    for(int i = 0; i<chfKey.size();i++){
        graph.add_edge("CHF", chfKey[i], -log(chfEdge[i]));
        graph.add_edge(chfKey[i], "CHF", -log(1/chfEdge[i]));
    }

    return graph;
}

int main(){
    Graph graph = getFilledGraph();
    graph.dijkstra("USD","CHF");
}