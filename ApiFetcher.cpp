#include <string>
#include <iostream>
#include <curl/curl.h>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

string api = "https://jsonplaceholder.typicode.com/posts";

size_t write(void* content, size_t size, size_t nmemb, void* userType){ //size_t = size of an object
    size_t totalSize = size * nmemb;
    ((string*)userType) -> append((char*)content, totalSize);
    return totalSize;
}

int main() {

    CURL* curl;     //pointer to curl session
    CURLcode res;
    string dataRecieved;

    curl = curl_easy_init();    //initializes curl session
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, api.c_str());   //Set URL for GET request. '.c_str()' returns pointer to the string.
                                                            // We need to provide C-style string representation, 'string' itself is a higher level definition
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write); //Set Write function
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &dataRecieved); //save data recieved into 'dataRecieved' variable

        res = curl_easy_perform(curl);  //perform the request. 'res' contains return code

        if(res != CURLE_OK){
            cout << "CURL Failed - " << curl_easy_strerror(res) << endl;
        }
        else{
            try{
                json jsonData = json::parse(dataRecieved);
                cout << jsonData[0]["body"] << endl;
            }
            catch (json::parse_error& e){
                std::cout << "JSON Parse Error - " << e.what() << endl;
            }
        }
        curl_easy_cleanup(curl); //cleanup
    }
    return 0;
}