#include <ApiFetcher.hpp>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
    
    vector<string> usdDirectExchange = { "EUR", "JPY", "GBP", "CHF", "CAD", "AUD", "NZD", "CNY", "HKD", "SGD", "NOK", "SEK", "KRW", "TRY", "INR", "BRL", "ZAR" };    
    vector<string> eurDirectExchange = { "USD", "JPY", "GBP", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "HKD", "CNY", "MYR", "IDR" };
    vector<string> jpyDirectExchange = { "USD", "EUR", "GBP", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "HKD", "CNY", "KRW" };
    vector<string> gbpDirectExchange =  { "USD", "EUR", "JPY", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "HKD", "CNY", "MYR", "IDR" };
    vector<string> chfDirectExchange = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "NZD", "SGD", "CNY", "HKD", "SEK", "NOK", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "MYR", "IDR" };

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

    FetchJsonData(usd, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/USD");
    FetchJsonData(eur, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/EUR");
    FetchJsonData(jpy, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/JPY");
    FetchJsonData(gbp, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/GBP");
    FetchJsonData(chf, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/CHF");
    
    for(int i=0; i<usdDirectExchange.size(); i++){
        usdRates.push_back(usd["conversion_rates"][usdDirectExchange[i]]);
    }
    for(int i=0; i<eurDirectExchange.size(); i++){
        eurRates.push_back(eur["conversion_rates"][eurDirectExchange[i]]);
    }
    for(int i=0; i<gbpDirectExchange.size(); i++){
        gbpRates.push_back(gbp["conversion_rates"][gbpDirectExchange[i]]);
    }
    for(int i=0; i<chfDirectExchange.size(); i++){
        chfRates.push_back(chf["conversion_rates"][chfDirectExchange[i]]);
    }
    for(int i=0; i<jpyDirectExchange.size(); i++){
        jpyRates.push_back(jpy["conversion_rates"][jpyDirectExchange[i]]);
    }

}