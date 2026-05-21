class Solution {
public:
    int maxArea(vector<int>& heights) {
        int st =0;
        int end = heights.size()-1;
        int result =0;
        while(st < end){
            result = max(result , (end-st)*(min(heights[st],heights[end])));
            if(heights[st]>heights[end]){
                end--;
            }else{
                st++;
            }
        }
        return result;
        
    }
};
