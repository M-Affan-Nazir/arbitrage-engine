#include <currencyPairs.hpp>
#include <GraphGenerator.hpp>
#include <cmath>
#include <stdio.h>
#include <iostream>

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

void currencyPathway(Graph graph){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    if(graph.check_negative_weight_cycle("USD") ==  true){
        cout << "\t * MESSAGE: Negative weight cycles exist." << endl;
        cout << "\t * MESSAGE: Current Most Shortest Path Not Avilable\n" << endl;
    }
    else{
        cout << "Currency List: " << endl;
        int index = 0;
        for(int i = 0; i<graph.keys.size();i++){
            cout << "\t- " << i+1 << ". " << graph.keys[i] << endl;
        }
        int key1;
        int key2;
        cout << "Please Enter Currency 1: ";
        cin >> key1;
        cout << endl;
        cout<< "Please Enter Currency 2: ";
        cin >> key2;
        cout << endl;

        graph.dijkstra(graph.keys[key1-1], graph.keys[key2-1]);
    }
    cout << "Press 0 to continue" << endl;
    int temp;
    cin >> temp;

}

void arbitrageEngine(Graph graph){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        graph.bellman_ford("USD");
        cout << "Press 0 to continue" << endl;
        int temp;
        cin >> temp;

}

int main(){
    Graph graph = getFilledGraph();
    bool exit = false;
    while(exit == false){
        int option;
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        cout << "\n---------------------------------------\n" << endl;
        cout << "\t ARBITRAGE ENGINE" << endl;
        cout << "\n---------------------------------------\n" << endl;
        cout << "SELECT OPTION:" <<  endl;
        cout << "\t 1. Find Shortest Currency Pathway" << endl;
        cout << "\t 2. Run Arbitrage Engine" << endl;
        cout << "\t 3. Exit\n" << endl;

        cout<< "Please Enter Option Number: ";
        cin >> option;

        if(option == 1){
            currencyPathway(graph);
        }
        else if(option == 2){
            arbitrageEngine(graph);
        }
        else if(option == 3){
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            exit = true;
        }

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
}