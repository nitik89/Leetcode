class Solution {
public:
    int calculate(string s) {
        stack<int>stk;
        int num=0;
        int sum=0;
        int sign=1;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                int val=0;
                while(i<s.size()&&(s[i]>='0'&&s[i]<='9')){
                    val=val*10+(s[i] - '0');
                    i++;
                }
                i--;
                sum+=val*sign;
                sign=1;
            }
            else if(s[i]=='-'){
                sign*=-1;
            }
            else if(s[i]=='('){
                stk.push(sum);
                stk.push(sign);
                sum=0;
                sign=1;
            }
            else if(s[i]==')'){
                sum*=stk.top();
                stk.pop();
                sum+=stk.top();
                stk.pop();
            }
            
            
           
        }
        return sum;
    }
};