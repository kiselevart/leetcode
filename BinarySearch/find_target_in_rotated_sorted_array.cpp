#include <iostream>
#include <sys/_types/_off_t.h>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (target == nums[m]) return m;
            else if (nums[l] <= nums[m]) {
                if (target > nums[m] || target < nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (target < nums[m] || target > nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {3,5,6,0,1,2};
    int target = 4;

    Solution solution;
    cout << solution.search(nums, target) << endl;
}
