class Solution {
public:
    bool isValid(char c){
        if((c >='a' && c <= 'z') || (c >='A' && c <= 'Z') || (c >='0' && c <= '9')){
            return true;
        }else{
            return false;
        }
    }

    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size()-1;
        while(st <= end){
            if(isValid(s[st]) && isValid(s[end])){
                if(tolower(s[st]) == tolower(s[end])){
                    st++;
                    end--;
                }else{
                    return false;
                }
            }else if(!isValid(s[st])){
                st++;
            }else if(!isValid(s[end])){
                end--;
            }
        }
        return true;
    }
};
