class Solution {
public:
    bool parseBoolExpr(string exp) {
       stack<char>stk;
        for(int i=exp.size()-1;i>=0;i--){
            if(exp[i]==','){
                continue;
            }
            if(exp[i]=='t'||exp[i]=='f'||exp[i]==')'||exp[i]=='('){
                stk.push(exp[i]);
            }
            else if(exp[i]=='|'){
                int ans=0;
                while(!stk.empty()&&stk.top()!=')'){
                   if(stk.top()=='f'){
                        ans|=0;
                       
                    }
                    else if(stk.top()=='t'){
                        ans|=1;
                    }
                     stk.pop();
                }
                if(!stk.empty()&&stk.top()==')'){
                    stk.pop();
                }
                if(ans){
                    stk.push('t');
                }
                else {
                    stk.push('f');
                }
            }
              else if(exp[i]=='&'){
                int ans=1;
                while(!stk.empty()&&stk.top()!=')'){
                   if(stk.top()=='f'){
                        ans&=0;
                       
                    }
                    else if(stk.top()=='t'){
                        ans&=1;
                    }
                     stk.pop();
                }
                if(!stk.empty()&&stk.top()==')'){
                    stk.pop();
                }
                if(ans){
                    stk.push('t');
                }
                else {
                    stk.push('f');
                }
            }
            else if(exp[i]=='!'){
                cout<<i<<" ";
                int ans;
                while(!stk.empty()&&stk.top()!=')'){
                   if(stk.top()=='f'){
                        ans=1;
                       
                    }
                    else if(stk.top()=='t'){
                        ans=0;
                    }
                     stk.pop();
                }
                if(!stk.empty()&&stk.top()==')'){
                    stk.pop();
                }
                if(ans){
                    stk.push('t');
                }
                else {
                    stk.push('f');
                }
            }
        }
        // }cout<<stk.size()<<" ";
        return stk.top()=='f'?0:1;
    }
};