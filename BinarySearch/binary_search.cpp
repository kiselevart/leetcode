#include <stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;

        cout << left << ", " << mid << ", " << right << endl;

        while (left <= right) {
            mid = (left + right + 1) / 2;
            cout << left << ", " << mid << ", " << right << endl;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) {
                right = mid - 1;
                continue;
            }
            else {
                left = mid + 1;
                continue;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    Solution solution;
    int ret = solution.search(nums, target);
    cout << ret << endl;
}
