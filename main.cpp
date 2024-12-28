#include <currencyPairs.hpp>
#include <stdio.h>

int main() {
    
    CurrencyPairs getter = CurrencyPairs("82f6fed8a66de96e7f6eee2c");
    getter.fetch();
    std::vector<string> data = getter.get_unique_keys();
    for(int i = 0; i< data.size();i++){
        cout << data[i] << endl;
    }

}