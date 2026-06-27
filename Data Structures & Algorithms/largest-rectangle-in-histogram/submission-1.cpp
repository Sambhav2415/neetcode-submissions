class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> leftMax(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(!s.empty()){
                leftMax[i] = s.top();
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }
        vector<int> rightMax(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(!s.empty()){
                rightMax[i] = s.top();
            }
            s.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int width = rightMax[i]-leftMax[i]-1;
            ans = max(ans , width*heights[i]);
        }
        return ans;
    }
};
