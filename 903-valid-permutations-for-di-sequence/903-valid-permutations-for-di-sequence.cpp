class Solution {
public:
    int dp[201][201];
    int mod=1e9+7;
    int getAns(string &str,int prev,int i,vector<int>&vis){
        if(i>=str.size()){
            return 1;
        }
        if(dp[prev][i]!=-1){
            return dp[prev][i];
        }
        int cnt=0;
        if(str[i]=='D'){
          for(int j=prev-1;j>=0;j--){
               if(vis[j])continue;
                 vis[j]=1;
              cnt=cnt%mod+getAns(str,j,i+1,vis);
              vis[j]=0;
          }   
            }
        else if(str[i]=='I'){
             for(int j=prev+1;j<=str.size();j++){
                 if(vis[j])continue;
                 vis[j]=1;
                 cnt = cnt%mod + getAns(str,j,i+1,vis);
                 vis[j]=0;
          } 
        }
        
        return dp[prev][i]=cnt%mod;
    }
    int numPermsDISequence(string s) {
        
        int cnt=0;
        vector<int>vis(s.size()+1,0);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<=s.size();i++){
            
            vis[i]=1;
            cnt=cnt%mod+getAns(s,i,0,vis);
            vis[i]=0;
        }
        return cnt%mod;
    }
};