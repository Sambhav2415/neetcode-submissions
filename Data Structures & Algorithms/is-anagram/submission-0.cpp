class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> data(26,0);
        if(s.size()!=t.size()){
            return false;
        }

        for(char c : s){
            data[c-'a']++;
        }

        for(char c : t){
            if(data[c-'a'] <= 0){
                return false;
            }
            data[c-'a']--;
        }
        return true;
    }
};
