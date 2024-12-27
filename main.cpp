#include <currencyPairs.hpp>
#include <stdio.h>

int main() {
    
    CurrencyPairs getter = CurrencyPairs("82f6fed8a66de96e7f6eee2c");
    getter.fetch();
    std::vector<float> data = getter.getChfEdge();
    std::cout << data.size() << endl;

}