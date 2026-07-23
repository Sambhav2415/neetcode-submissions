class Solution {
public:
    vector<int> freq1;
    vector<int> freq2;

    bool toCheck(){
        for(int i=0;i<128;i++){
            if(freq2[i]>freq1[i]){
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

        for(char c:t){
            freq2[c]++;
        }

        int l = 0;
        int bestStart = -1;
        int bestLen = INT_MAX;

        for(int r=0;r<a;r++){
            freq1[s[r]]++;
            while(toCheck()){
                int currLen = r-l+1;
                if(currLen < bestLen){
                    bestLen = currLen;
                    bestStart = l;
                }
                freq1[s[l]]--;
                l++;
            }
        }
        if(bestStart == -1){
            return "";
        }
        return s.substr(bestStart,bestLen);
    }
};
