class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0||s.size()==1){
            return 0;
        }
      stack<int>stk;
        stk.push(-1);
        int len=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                if(!stk.empty()){
                    stk.pop();
                    if(!stk.empty()){
                    len=max(i-stk.top(),len);
                    }
                    else{
                        stk.push(i);
                    }
                 
                }
                else{
                    stk.push(i);
                }
            }
        }
        return len;
    }
};