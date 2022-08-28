class Solution {
public:
    string removeStars(string s) {
        stack<char>stk;
        for(auto x:s){
            if(x!='*'){
                stk.push(x);
            }
            else if(!stk.empty()){
                stk.pop();
            }
        }
        string ans="";
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};