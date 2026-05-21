class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // return 0;
        stack<int> s;
        for(string k : tokens){
            if(k != "+" && k != "-" && k != "*" && k != "/"){
                s.push(stoi(k));
            }else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(k == "+"){
                    s.push(a+b);
                }else if(k == "-"){
                    s.push(-a+b);
                }else if(k == "*"){
                    s.push(a*b);
                }else if(k == "/"){
                    s.push(b/a);
                }
            }
        }
        if(s.empty()){
            return 0;
        }
        return s.top();
    }
};
