class Solution {
public:
    string smallestSubsequence(string s, int k, char let, int rep) {
       stack<char>stk;
        int cnt=0;
        for(auto x:s){
            if(x==let){
                cnt++;
            }
        }
        int curr=0;
        //taking the conditions
        //there must be atlest k elments
        int n=s.size();
        for(int i=0;i<n;i++){
            while(!stk.empty()&&(stk.top()>s[i])&&(stk.size()+(n-i)>k)){
                if(stk.top()==let&&(curr+cnt-1>=rep)){
                   curr--;
                    stk.pop();
                }
                else if(stk.top()==let){
                    break;
                }
                else{
                stk.pop();
                }
            }
           
           
                 if(s[i]==let){
                cnt--;
                curr++;
                
            
            
            }
            stk.push(s[i]);
            
        }
        
        string str="";
        
        int req=rep-curr;
        
        
        while(!stk.empty()){
            str+=stk.top();
            stk.pop();
        }
        
        // cout<<req<<" ";
        reverse(str.begin(),str.end());
        string ans="";
        int req1=(k-rep);
        for(int i=0;i<str.size();i++){
            if(str[i]==let&&rep>0){
                ans+=str[i];
                rep--;
            }
            else if(req1>0){
                ans+=str[i];
                req1--;
            }
        }
        while(rep>0){
            ans+=let;
            rep--;
        }
        
        
        return ans;
    }
};