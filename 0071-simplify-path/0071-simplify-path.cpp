class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);
        stack<string> s;
        while(getline(ss,token,'/')){
            if(token=="."||token==""){
                continue;
            }
            else if(token==".."){
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(token);
            }
        }
        if(s.empty()) return "/";
        string result = "";
        while(!s.empty()){
            result = "/" + s.top() + result;
            s.pop();
        }
        return result;
    }
};