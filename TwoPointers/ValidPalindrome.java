public class ValidPalindrome {
    class Solution {
        public boolean isPalindrome(String s) {
            s = s.toLowerCase();
            s = s.replaceAll("^[a-zA-Z0-9]", "");

            int j = s.length();
            for (int i=0; i<s.length()/2; i++) {
                if (s.charAt(i) != s.charAt(--j)) {return false;}
            }

            return true;
        }
    }
}
