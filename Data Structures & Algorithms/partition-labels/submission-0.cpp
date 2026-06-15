class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }
        vector<int> ans;
        int endPos = mp[s[0]];
        int len = 0;
        for(int i=0;i<s.size();i++){
            len++;
            endPos = max(endPos,mp[s[i]]);
            if(i == endPos){
                ans.push_back(len);
                len = 0;
            }
        }
        return ans;
    }
};
