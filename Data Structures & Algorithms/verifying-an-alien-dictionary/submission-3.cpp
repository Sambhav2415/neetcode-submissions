class Solution {
public:
    unordered_map<char,int> mp;

    bool toCheck(string words1 , string words2){
        int n = words1.size();
        int m = words2.size();
        int i=0;
        while(i <n && i<m){
            if(words1[i] == words2[i]){
                i++;
                continue;
            }
            return mp[words1[i]] < mp[words2[i]];
        }
        return n<=m;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++){
            mp[order[i]] = i;
        }
        for(int i=1;i<words.size();i++){
            if(!toCheck(words[i-1],words[i])){
                return false;
            }
        }
        return true;
    }
};