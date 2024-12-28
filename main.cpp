#include <currencyPairs.hpp>
#include <GraphGenerator.hpp>
#include <stdio.h>

int main() {
    
    CurrencyPairs currencies = CurrencyPairs("82f6fed8a66de96e7f6eee2c");
    currencies.fetch();
    Graph graph = Graph(currencies.get_unique_keys().size());
    graph.set_key(currencies.get_unique_keys());
    graph.print_matrix();
}