import java.util.*;

public class LargestRectangle {
    class Solution {
        public class Element {
            public int index;
            public int height;

            public Element(int index, int height) {
                this.index = index;
                this.height = height;
            }
        }

        public int largestRectangleArea(int[] heights) {
            Stack<Element> stack = new Stack<>();

            stack.push(new Element(0, heights[0]));
            int maxArea = heights[0];

            for (int i=1; i<heights.length; i++) {
                int currentHeight = heights[i];
                int currentIndex = i;

                while(!stack.isEmpty() && stack.peek().height > currentHeight) {
                    Element elem = stack.pop();
                    int index = elem.index;
                    int height = elem.height;
                    maxArea = Math.max(maxArea, height * (i-index));
                    currentIndex = index;                    
                }
                stack.push(new Element(currentIndex, currentHeight));
            }

            while (!stack.isEmpty()) {
                Element elem = stack.pop();
                int index = elem.index;
                int height = elem.height;
                maxArea = Math.max(maxArea, height * (heights.length-index));
            }

            return maxArea;
        }
    }
}
