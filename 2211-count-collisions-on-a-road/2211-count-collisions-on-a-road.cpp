class Solution {
public:
    int countCollisions(string dir) {
        stack<char>stk;
        int ans=0;
        for(int i=0;i<dir.size();i++){
            if(dir[i]=='R'){
                stk.push('R');
            }
            else if(dir[i]=='S'){
                while(!stk.empty()&&stk.top()=='R'){
                    ans++;
                    stk.pop();
                }
                stk.push('S');
            }
            else if(dir[i]=='L'){
                bool col=false;
                if(!stk.empty()&&stk.top()=='S'){
                    ans++;
                    col=true;
                    stk.pop();
                }
                
                if(!stk.empty()&&stk.top()=='R'){
                    ans+=2;
                    col=true;
                    stk.pop();
                }
                while(!stk.empty()&&stk.top()=='R'){
                    ans++;
                    stk.pop();
                }
                if(col){
                    stk.push('S');
                }
            }
            
        }
        return ans;
    }
};