class Solution {
public:
    int dp[1001][1001];
    int getAns(string str,int s,int e){
         // cout<<s<<" "<<e<<"\n";
        int n=e-s+1;
        if(s>e){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        
        
        
        int ans=1;
        for(int i=s;i<s+n/2;i++){
           string temp1=str.substr(s,i+1-s);
           string temp2=str.substr(e-i+s,i+1-s);
            
            
                
            if(temp1.compare(temp2)==0){
               
                int curr=2+getAns(str,i+1,e+s-(i+1));
                ans=max(ans,curr);
            }
        }
        return dp[s][e]=ans;
    }
    int longestDecomposition(string text) {
        memset(dp,-1,sizeof dp);
    return getAns(text,0,text.size()-1);   
    }
};