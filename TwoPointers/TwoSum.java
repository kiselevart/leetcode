class TwoSum {

}

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int front = 0;
        int rear = numbers.length-1;

        while (front < rear) {
            int a = numbers[front];
            int b = numbers[rear];

            if (a == b) {break;}

            if (a + b < target) {
                front++;
                continue;
            }

            rear--;
        }

        return new int[]{++front,++rear};
    }
}