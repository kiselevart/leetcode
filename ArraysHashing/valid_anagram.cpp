#include <stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> s_map, t_map;
        for (int i=0; i<s.size(); i++) {
            s_map[s[i]]++;
            t_map[s[i]]++;
        }

        for (const auto& s_pair : s_map) {
            const auto t_pair = t_map.find(s_pair.first);

            cout << s_pair.first << " " << s_pair.second << endl;
            cout << t_pair.first << " " << t_pair.second << endl;

            if (t_pair == t_map.end() || t_pair->second != t_pair.second) {
                return false;  
            }
        }

        return true;
    }
};