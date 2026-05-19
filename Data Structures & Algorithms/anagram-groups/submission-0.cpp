class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> m;
        for(string s : strs){
            string k = s;
            sort(k.begin() , k.end());
            if(m.count(k)){
                m[k].push_back(s);
            }else{
                m[k] = {s};
            }
        }

        vector<vector<string>> vec;
        for(auto &pair : m){
            vec.push_back(pair.second);
        }
        
        return vec;
    }
};
