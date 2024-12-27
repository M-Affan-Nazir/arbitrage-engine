#include <string>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

int FetchJsonData(json &dataRef,  string api);