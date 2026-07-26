class Solution {
public:
    vector<string> ans;

    void rec(string &s, int idx,unordered_set<string> &dict,string curr){

        if(idx == s.size()){
            curr.pop_back();           // remove trailing space
            ans.push_back(curr);
            return;
        }

        string word = "";

        for(int i = idx; i < s.size(); i++){

            word += s[i];

            if(dict.count(word)){
                rec(s, i + 1, dict, curr + word + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        rec(s, 0, dict, "");

        return ans;
    }
};