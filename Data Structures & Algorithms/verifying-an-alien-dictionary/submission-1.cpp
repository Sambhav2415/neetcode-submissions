class Solution {
public:
    vector<int> pos = vector<int>(26, 0);
    bool toCheck(string a , string b){
        int s1 = a.size();
        int s2 = b.size();
        int i = 0;
        while(i < s1 && i < s2){
            if(a[i] == b[i]){
                i++;
            }else{
                return pos[a[i]-'a'] < pos[b[i]-'a'];
            }
        }
        return s1 <= s2;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if(n == 1){
            return true;
        }
        for(int i = 0; i < order.size(); i++) {
            pos[order[i]-'a'] = i;
        }
        for(int i=0;i<n-1;i++){
            if(!toCheck(words[i],words[i+1])){
                return false;
            }
        }
        return true;
    }
};