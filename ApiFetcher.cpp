#include <string>
#include <iostream>
#include <curl/curl.h>
using namespace std;

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
        curl_easy_setopt(curl, CURLOPT_URL, api.c_str());   //Set URL for GET request. '.c_str()' returns pointer to the string. We can not use 'api', since it is of higher definition type 'string'.
                                                            // We need to provide C-style string representation
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write); //Set Write function
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &dataRecieved); //save data recieved into 'dataRecieved' variable

        res = curl_easy_perform(curl);  //perform the request. 'res' contains return code

        if(res != CURLE_OK){
            cout << "CURL Failed - " << curl_easy_strerror(res) << endl;
        }
        else{
            cout << "Data: " << endl;
            cout << dataRecieved << endl;
        }
        curl_easy_cleanup(curl); //cleanup
    }
    return 0;
}