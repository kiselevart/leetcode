#include <string>
#include <vector>
#include <set>
using namespace std;

class TimeMap {
public:
    set<tuple<string, string, int>> tset;

    TimeMap() {
        tset;
    }

    void set(string key, string value, int timestamp) {
        if (tset.find(key)) {

        }
    }

    string get(string key, int timestamp) {

    }
};
