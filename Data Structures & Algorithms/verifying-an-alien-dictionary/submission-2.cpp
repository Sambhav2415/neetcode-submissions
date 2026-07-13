class Solution {
public:
    vector<int> pos = vector<int>(26, 0);

    bool check(string word1,string word2){
        int n = word1.size();
        int m = word2.size();
        if(word1 == word2){
            return true;
        }
        int i=0;
        while(i <n && i<m){
            if(word1[i] == word2[i]){
                i++;
                continue;
            }
            return pos[word1[i]-'a'] < pos[word2[i]-'a'];
        }
        return n <= m;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if(n == 1){
            return true;
        }
        for(int i = 0; i < order.size(); i++) {
            pos[order[i]-'a'] = i;
        }
        for(int i=1;i<n;i++){
            if(!check(words[i-1],words[i])){
                return false;
            }
        }
        return true;
    }
};