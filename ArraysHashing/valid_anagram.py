class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_chars = {}; t_chars = {}

        if len(s) != len(t): return False
        for i in range(len(s)):
            s_curr = s[i]; t_curr = t[i]
            s_chars[s_curr] = s_chars.get(s_curr, 0) + 1
            t_chars[t_curr] = t_chars.get(t_curr, 0) + 1

        return s_chars.__eq__(t_chars)