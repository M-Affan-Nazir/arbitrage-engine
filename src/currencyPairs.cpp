#include <ApiFetcher.hpp>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#include "currencyPairs.hpp"
#include <set>



CurrencyPairs::CurrencyPairs(
    string apiKey,  
    vector<string> usdDirectExchange, 
    vector<string> eurDirectExchange, 
    vector<string> jpyDirectExchange, 
    vector<string> gbpDirectExchange, 
    vector<string> chfDirectExchange
) 
{
    this->apiKey = apiKey;
    this->usdDirectExchange = usdDirectExchange;
    this->eurDirectExchange = eurDirectExchange;
    this->jpyDirectExchange = jpyDirectExchange;
    this->gbpDirectExchange = gbpDirectExchange;
    this->chfDirectExchange = chfDirectExchange;
}

CurrencyPairs::CurrencyPairs(string apiKey) {
    this->apiKey = apiKey;
    this->usdDirectExchange = { "EUR", "JPY", "GBP", "CHF", "CAD", "AUD", "NZD", "CNY", "HKD", "SGD", "NOK", "SEK", "KRW", "TRY", "INR", "BRL", "ZAR" };
    this->eurDirectExchange = { "USD", "JPY", "GBP", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "HKD", "CNY", "MYR", "IDR" };
    this->jpyDirectExchange = { "USD", "EUR", "GBP", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "HKD", "CNY", "KRW" };
    this->gbpDirectExchange = { "USD", "EUR", "JPY", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "HKD", "CNY", "MYR", "IDR" };
    this->chfDirectExchange = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "NZD", "SGD", "CNY", "HKD", "SEK", "NOK", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "MYR", "IDR" };
}

void CurrencyPairs::fetch() {
    FetchJsonData(usd, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/USD");
    FetchJsonData(eur, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/EUR");
    FetchJsonData(jpy, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/JPY");
    FetchJsonData(gbp, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/GBP");
    FetchJsonData(chf, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/CHF");

    for (int i = 0; i < usdDirectExchange.size(); i++) {
        usdRates.push_back(usd["conversion_rates"][usdDirectExchange[i]]);
    }
    for (int i = 0; i < eurDirectExchange.size(); i++) {
        eurRates.push_back(eur["conversion_rates"][eurDirectExchange[i]]);
    }
    for (int i = 0; i < gbpDirectExchange.size(); i++) {
        gbpRates.push_back(gbp["conversion_rates"][gbpDirectExchange[i]]);
    }
    for (int i = 0; i < chfDirectExchange.size(); i++) {
        chfRates.push_back(chf["conversion_rates"][chfDirectExchange[i]]);
    }
    for (int i = 0; i < jpyDirectExchange.size(); i++) {
        jpyRates.push_back(jpy["conversion_rates"][jpyDirectExchange[i]]);
    }
}

vector<string> CurrencyPairs::getUsdKey() {
    return usdDirectExchange;
}

vector<string> CurrencyPairs::getEurKey() {
    return eurDirectExchange;
}

vector<string> CurrencyPairs::getJpyKey() {
    return jpyDirectExchange;
}

vector<string> CurrencyPairs::getGbpKey() {
    return gbpDirectExchange;
}

vector<string> CurrencyPairs::getChfKey() {
    return chfDirectExchange;
}

vector<float> CurrencyPairs::getUsdEdge() {
    return usdRates;
}

vector<float> CurrencyPairs::getEurEdge() {
    return eurRates;
}

vector<float> CurrencyPairs::getJpyEdge() {
    return jpyRates;
}

vector<float> CurrencyPairs::getGbpEdge() {
    return gbpRates;
}

vector<float> CurrencyPairs::getChfEdge() {
    return chfRates;
}

vector<string> CurrencyPairs::get_unique_keys(){

    vector<string> combined;
    combined.insert(combined.end(), usdDirectExchange.begin(), usdDirectExchange.end());
    combined.insert(combined.end(), eurDirectExchange.begin(), eurDirectExchange.end());
    combined.insert(combined.end(), jpyDirectExchange.begin(), jpyDirectExchange.end());
    combined.insert(combined.end(), gbpDirectExchange.begin(), gbpDirectExchange.end());
    combined.insert(combined.end(), chfDirectExchange.begin(), chfDirectExchange.end());

    //unique_keys_set/vector are variable names. (.begin(),.end()) is to populate the uniques_keys_set and unique_keys_vector
    set<string> unique_keys_set (combined.begin(), combined.end());
    vector<string> unique_keys_vector (unique_keys_set.begin(), unique_keys_set.end()); //.begin() = iterator pointing to first element - .end() = iterator pointing to last element.

    return unique_keys_vector;
}