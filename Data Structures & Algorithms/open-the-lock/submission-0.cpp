class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000")) return -1;

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({"0000", 0});
        visited.insert("0000");
        while(!q.empty()){
            auto [val,steps] = q.front();
            q.pop();
            if(val == target){
                return steps;
            }
            for(int i=0;i<4;i++){
                string next = val;

                // Turn wheel forward
                next[i] = (val[i] - '0' + 1) % 10 + '0';
                if (!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }

                // Turn wheel backward
                next = val;
                next[i] = (val[i] - '0' + 9) % 10 + '0';
                if (!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};