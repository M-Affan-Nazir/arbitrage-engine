#include <ApiFetcher.hpp>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    json data;
    int x = FetchJsonData(data, "https://jsonplaceholder.typicode.com/posts");
    cout << data[0] << endl;
}