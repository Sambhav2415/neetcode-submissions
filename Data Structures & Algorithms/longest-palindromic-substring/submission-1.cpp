class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n <= 1) return s;

        int start = 0;
        int maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;

                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }

                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);       // odd length palindrome
            expand(i, i + 1);   // even length palindrome
        }

        return s.substr(start, maxLen);
    }
};
