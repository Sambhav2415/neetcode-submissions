class Solution {
public:
    vector<int> freq1;
    vector<int> freq2;

    bool checkInclusion(string s1, string s2) {
        int a = s1.size(),b = s2.size();
        if(a > b){
            return false;
        }
        freq1.assign(26,0);
        freq2.assign(26,0);

        for(char c:s1){
            freq1[c-'a']++;
        }
        for(int i=0;i<a;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1 == freq2){
            return true;
        }
        for(int i=a;i<b;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-a]-'a']--;
            if(freq1 == freq2){
                return true;
            }
        }
        return false;
    }
};
