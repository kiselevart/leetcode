#include <vector>
#include <iostream>
using namespace std;

int trap(vector<int>& height) {
    int sum = 0;
    int start = 0;
    int end = 1;
    int min;

    while (start <= end) {
        for (int i=start; i<height.size(); i++) {
            if (height[i] < height[i+1]) {
                end = i+1;
                break;
            }
        }
        if (start == end) break;

        if (height[start] < height[end]) {
            min = height[start];
        } else {
            min = height[end];
        }
        for (int j=start+1; j<end; j++) {
            sum += min - height[j];
        }
        start = end;
    }

    return sum;
}

int main() {
    vector<int> height = vector<int>{0,1,0,2,1,0,1,3,2,1,2,1};

    int ret = trap(height);
    cout << ret << endl;
}