class Solution {
public:
    int mod=1e9+7;
    
    int getAns(string &str,int i,int k,vector<int>&dp){
        if(i>=str.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(str[i]=='0'){
            return 0;
        }
        long long num=0;
        int ans=0;
        for(int j=i;j<str.size();j++){
            num=num*10+(str[j]-'0');
            if(num>k){
                break;
            }
            ans=ans%mod+getAns(str,j+1,k,dp);
        }
        return dp[i]=ans%mod;
    }
    int numberOfArrays(string s, int k) {
        int n=s.size();
         vector<int> dp(n+1,-1);
       return getAns(s,0,k,dp);
    }
};