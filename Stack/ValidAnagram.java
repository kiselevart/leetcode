import java.util.*;

public class ValidAnagram {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {return false;}
        HashMap<Character, Integer> map = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();

        for (int i=0; i<s.length(); i++) {
            char[] a1 = s.toCharArray();
            char[] a2 = t.toCharArray();

            map.compute(a1[i], (k, v) -> (v == null) ? 1 : v+1);
            map.compute(a2[i], (k, v) -> (v == null) ? 1 : v+1);
        }

        for (Character ch : map.keySet()) {
            if (map.get(ch) != map2.get(ch)) {return false;}
        }
        return true;
    }
}
