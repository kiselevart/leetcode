#include <stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uset;

        for (int & num : nums) {
            if (uset.find(num) != uset.end()) {
                return true;
            } else {
                uset.emplace(num);
            }
        }
        return false;
    }
};