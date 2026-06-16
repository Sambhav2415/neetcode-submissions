class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size(),n2 = word2.size();
        int st1=0,st2=0;
        string s = "";
        int i =0;
        while(st1 < n1 && st2 < n2){
            if(i%2 == 0){
                s += word1[st1];
                st1++;
            }else{
                s+= word2[st2];
                st2++;
            }
            i++;
        }

        while(st1 < n1){
            s+=word1[st1++];
        }
        while(st2 < n2){
            s+=word2[st2++];
        }
        return s;
    }
};