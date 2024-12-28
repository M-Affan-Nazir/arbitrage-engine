#include <ApiFetcher.hpp>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class CurrencyPairs {
private:
    vector<string> usdDirectExchange;
    vector<string> eurDirectExchange;
    vector<string> jpyDirectExchange;
    vector<string> gbpDirectExchange;
    vector<string> chfDirectExchange;

    json usd;
    json eur;
    json jpy;
    json gbp;
    json chf;

    vector<float> usdRates;
    vector<float> eurRates;
    vector<float> jpyRates;
    vector<float> gbpRates;
    vector<float> chfRates;

    string apiKey;

public:
    
    CurrencyPairs(
        string apiKey,
        vector<string> usdDirectExchange,
        vector<string> eurDirectExchange,
        vector<string> jpyDirectExchange,
        vector<string> gbpDirectExchange,
        vector<string> chfDirectExchange
    );

    CurrencyPairs(string apiKey);

    void fetch();

    vector<string> getUsdKey();
    vector<string> getEurKey();
    vector<string> getJpyKey();
    vector<string> getGbpKey();
    vector<string> getChfKey();

    vector<string> get_unique_keys();

    vector<float> getUsdEdge();
    vector<float> getEurEdge();
    vector<float> getJpyEdge();
    vector<float> getGbpEdge();
    vector<float> getChfEdge();
};
