class Solution {
public:
    int dp[102][102];
    int getAns(vector<string>& strs,int i,int prev){
        if(i==strs[0].size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        
        int b=0;
        if(prev!=-1){
        for(int j=0;j<strs.size();j++){
            if(strs[j][i]<strs[j][prev]){
                b=1;
                break;
            }
        }
        }
        int ans=INT_MAX;
        
            
        ans=min(ans,1+getAns(strs,i+1,prev));    
        
        if(b==0){
        
        ans=min(ans,getAns(strs,i+1,i));
        }
        return dp[i][prev+1]=ans;
    }
    int minDeletionSize(vector<string>& strs) {
        memset(dp,-1,sizeof dp);
        return getAns(strs,0,-1);
    }
};