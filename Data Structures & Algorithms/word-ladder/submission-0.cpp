class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());

        if (!words.count(endWord))
            return 0;

        queue<pair<string,int>> qu;
        qu.push({beginWord,1});
        words.erase(beginWord);

        while(!qu.empty()){
            auto [s,steps] = qu.front();
            qu.pop();

            if(s == endWord){
                return steps;
            }
            for(int i=0;i<s.size();i++){
                char orig = s[i];
                for(char c = 'a';c<='z';c++){
                    s[i] = c;
                    if(words.count(s)){
                        qu.push({s,steps+1});
                        words.erase(s);
                    }
                }
                s[i] = orig;
            }
        }
        return 0;
    }
};
