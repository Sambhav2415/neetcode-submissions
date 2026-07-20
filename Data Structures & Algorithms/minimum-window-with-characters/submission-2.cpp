class Solution {
public:
    vector<int> freq1,freq2;

    bool toCheck(){
        for(int i=0;i<128;i++){
            if(freq2[i] > freq1[i]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int a = s.size();
        int b = t.size();
        if(b>a){
            return "";
        }

        freq1.assign(128,0);
        freq2.assign(128,0);

        for(int i=0;i<b;i++){
            freq2[t[i]]++;
        }
        int beststart = -1;
        int l = 0;
        int bestLen = INT_MAX;

        for(int i=0;i<a;i++){
            freq1[s[i]]++;
            while(toCheck()){
                int currLen = i-l+1;
                if(currLen < bestLen){
                    beststart = l;
                    bestLen = currLen;
                }
                freq1[s[l++]]--;
            }
        }
        if(beststart == -1){
            return "";
        }
        return s.substr(beststart,bestLen);
    }
};
