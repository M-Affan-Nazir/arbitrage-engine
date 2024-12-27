#include <ApiFetcher.hpp>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
    
    string usdDirectExchange[17] = { "EUR", "JPY", "GBP", "CHF", "CAD", "AUD", "NZD", "CNY", "HKD", "SGD", "NOK", "SEK", "KRW", "TRY", "INR", "BRL", "ZAR" };    
    string eurDirectExchange[26] = { "USD", "JPY", "GBP", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "HKD", "CNY", "MYR", "IDR" };
    string jpyDirectExchange[13]= { "USD", "EUR", "GBP", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "HKD", "CNY", "KRW" };
    string gbpDirectExchange[26] =  { "USD", "EUR", "JPY", "CHF", "CAD", "AUD", "NZD", "SEK", "NOK", "SGD", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "HKD", "CNY", "MYR", "IDR" };
    string chfDirectExchange[26] = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "NZD", "SGD", "CNY", "HKD", "SEK", "NOK", "DKK", "CZK", "PLN", "HUF", "ILS", "TRY", "RUB", "ZAR", "MXN", "BRL", "INR", "KRW", "MYR", "IDR" };

    json usd;
    json eur;
    json jpy;
    json gbp;
    json chf;

    float usdRates [17];
    float eurRates [26];
    float jpyRates [13];
    float gbpRates [26];
    float chfRates [26];

    FetchJsonData(usd, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/USD");
    FetchJsonData(eur, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/EUR");
    FetchJsonData(jpy, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/JPY");
    FetchJsonData(gbp, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/GBP");
    FetchJsonData(chf, "https://v6.exchangerate-api.com/v6/82f6fed8a66de96e7f6eee2c/latest/CHF");
    
    for(int i=0; i<sizeof(usdRates)/sizeof(float); i++){
        usdRates[i] = usd["conversion_rates"][usdDirectExchange[i]];
    }
    for(int i=0; i<sizeof(eurRates)/sizeof(float); i++){
        eurRates[i] = eur["conversion_rates"][eurDirectExchange[i]];
        gbpRates[i] = gbp["conversion_rates"][gbpDirectExchange[i]];
        chfRates[i] = chf["conversion_rates"][chfDirectExchange[i]];
    }
    for(int i=0; i<sizeof(jpyRates)/sizeof(float); i++){
        jpyRates[i] = jpy["conversion_rates"][jpyDirectExchange[i]];
    }


}