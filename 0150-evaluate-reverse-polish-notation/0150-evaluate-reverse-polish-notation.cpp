class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> HelperStack;
        for(string token : tokens){
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                int b = HelperStack.top();
                HelperStack.pop();
                int a = HelperStack.top();
                HelperStack.pop();
                if(token=="+") HelperStack.push(a+b);
                if(token=="-") HelperStack.push(a-b);
                if(token=="*") HelperStack.push(a*b);
                if(token=="/") HelperStack.push(a/b);
            }
            else{
                HelperStack.push(stoi(token));
            }
        }
        return HelperStack.top();   
    }
};