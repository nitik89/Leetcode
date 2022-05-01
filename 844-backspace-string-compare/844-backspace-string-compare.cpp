class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!stk.empty()){
                    stk.pop();
                }
            }
            else{
                stk.push(s[i]);
            }
        }
        string temp="";
        while(!stk.empty()){
            temp.push_back(stk.top());
            stk.pop();
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!stk.empty()){
                    stk.pop();
                }
            }
            else{
                stk.push(t[i]);
            }
        }
        string tm="";
        while(!stk.empty()){
            tm.push_back(stk.top());
            stk.pop();
        }
        return tm==temp;
    }
};