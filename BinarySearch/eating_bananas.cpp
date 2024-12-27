#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can_eat(int k, const vector<int>& piles, int h) {
        int hours = 0;
        for (const auto& pile : piles) {
            hours += (pile + k - 1) / k;  // This is equivalent to ceil(pile / k)
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (can_eat(mid, piles, h)) {
                result = mid;
                right = mid - 1;  // Try to find a smaller k
            } else {
                left = mid + 1;  // Increase k to eat faster
            }
        }

        return result;
    }
};

int main() {
    vector<int> piles = {1,4,3,2};
    int h = 9;

    Solution solution;
    cout << solution.minEatingSpeed(piles, h) << endl;
}
