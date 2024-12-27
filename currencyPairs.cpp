#include <ApiFetcher.hpp>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class CurrencyPairs{

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
        CurrencyPairs(string apiKey,  vector<string> usdDirectExchange, vector<string> eurDirectExchange, vector<string> jpyDirectExchange, vector<string> gbpDirectExchange, vector<string> chfDirectExchange){
            this->apiKey = apiKey;
            this->usdDirectExchange = usdDirectExchange;
            this->eurDirectExchange = eurDirectExchange;
            this->jpyDirectExchange = jpyDirectExchange;
            this->gbpDirectExchange = gbpDirectExchange;
            this->chfDirectExchange = chfDirectExchange;
        }
        CurrencyPairs(string apiKey){
            this->apiKey = apiKey;
            this->usdDirectExchange = { "EUR", "JPY", "GBP", "CHF", "CAD", "AUD", "NZD", "CNY", "HKD", "SGD", "NOK", "SEK", "KRW", "TRY", "INR", "BRL", "ZAR" };;
            this->eurDirectExchange = { "USD", "JPY", "GBP", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "HKD", "CNY", "MYR", "IDR" };
            this->jpyDirectExchange = { "USD", "EUR", "GBP", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "HKD", "CNY", "KRW" };
            this->gbpDirectExchange = { "USD", "EUR", "JPY", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "HKD", "CNY", "MYR", "IDR" };
            this->chfDirectExchange = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "NZD", "SGD", "CNY", "HKD", "SEK", "NOK", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "MYR", "IDR" };
        }
    
        void fetch(){
            FetchJsonData(usd, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/USD");
            FetchJsonData(eur, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/EUR");
            FetchJsonData(jpy, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/JPY");
            FetchJsonData(gbp, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/GBP");
            FetchJsonData(chf, "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/CHF");

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

        vector<string> getUsdKey(){
            return usdDirectExchange;
        } 
        vector<string> getEurKey(){
            return eurDirectExchange;
        } 
        vector<string> getJpyKey(){
            return jpyDirectExchange;
        } 
        vector<string> getGbpKey(){
            return gbpDirectExchange;
        } 
        vector<string> getChfKey(){
            return chfDirectExchange;
        } 

        vector<float> getUsdEdge(){
            return usdRates;
        }
        vector<float> getEurEdge(){
            return eurRates;
        }
        vector<float> getJpyEdge(){
            return jpyRates;
        }
        vector<float> getGbpEdge(){
            return gbpRates;
        }
        vector<float> getChfEdge(){
            return chfRates;
        }

};


int main() {
    
    CurrencyPairs getter = CurrencyPairs("82f6fed8a66de96e7f6eee2c");
    getter.fetch();

}