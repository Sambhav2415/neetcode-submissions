class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);       // odd-length palindromes
            expand(i, i + 1);   // even-length palindromes
        }

        return count;
    }
};
