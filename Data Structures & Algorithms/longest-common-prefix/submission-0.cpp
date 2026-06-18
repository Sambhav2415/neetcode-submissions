class Solution {
public:
    string toCheck(string a , string b){
        int s1 = a.size();
        int s2 = b.size();
        int i=0 , j =0;
        string res = "";
        while(i < s1 && j < s2){
            if(a[i] == b[j]){
                res += a[i];
                i++;
                j++;
            }else{
                break;
            }
        }
        return res;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0){
            return "";
        }else if(n == 1){
            return strs[0];
        }
        string result = toCheck(strs[0],strs[1]);
        for(int i=2;i<n;i++){
            if(result == ""){
                return "";
            }
            result = toCheck(result,strs[i]);
        }
        return result;
    }
};