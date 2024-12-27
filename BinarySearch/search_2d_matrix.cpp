#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // cout << rows << ", " << cols << endl;

        int left = 0;
        int right = rows * cols - 1;

        int curr, mid, row_mid, col_mid;
        while (left <= right) {
            mid = (left + right + 1) / 2;
            row_mid = mid / cols;
            col_mid = mid - (row_mid * cols);

            // printf("%d, %d, %d, %d, %d \n", left, right, mid, row_mid, col_mid);

            curr = matrix[row_mid][col_mid];
            if (target == curr) return true;
            else if (target < curr) {
                right = mid - 1;
                continue;
            } else {
                left = mid + 1;
                continue;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>>matrix = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    int target = 10;

    Solution solution;
    bool flag = solution.searchMatrix(matrix, target);
    if (flag) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
