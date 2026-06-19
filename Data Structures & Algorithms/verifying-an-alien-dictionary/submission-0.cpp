class Solution {
public:
    unordered_map<char,int> mp;
    bool toCheck(string a , string b){
        int s1 = a.size();
        int s2 = b.size();
        int i = 0;
        while(i < s1 && i < s2){
            if(a[i] == b[i]){
                i++;
                continue;
            }else{
                if(mp[a[i]] < mp[b[i]]){
                    return true;
                }else{
                    return false;
                }
            }
        }
        if(s1 > s2){
            return false;
        }else{
            return true;
        }
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if(n == 1){
            return true;
        }
        for(int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        for(int i=0;i<n-1;i++){
            if(!toCheck(words[i],words[i+1])){
                return false;
            }
        }
        return true;
    }
};