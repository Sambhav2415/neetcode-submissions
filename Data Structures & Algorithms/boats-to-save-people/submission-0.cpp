class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int end = people.size()-1;
        int s = 0;
        int ans = 0;
        while(s <= end){
            ans++;
            if(s == end){
                break;
            }
            if(people[s] + people[end] <= limit){
                s++;
                end--;
            }else{
                end--;
            }
        }
        return ans;
    }
};