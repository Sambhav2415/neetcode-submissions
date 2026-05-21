class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int end = numbers.size()-1;
        int st = 0;
        while(st < end){
            int sum = numbers[st] + numbers[end];
            if(sum == target){
                return {st+1,end+1};
            }else if (sum > target){
                end--;
            }else{
                st++;
            }
        }
        return {};
    }
};
