class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int ans = 0;
        for(string st : operations){
            if(st == "C"){
                s.pop();
            }else if(st == "D"){
                int k = s.top();
                s.push(2*k);
            }else if(st == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b);
                s.push(a);
                s.push(a+b);
            }else{
                s.push(stoi(st));
            }
        }
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};