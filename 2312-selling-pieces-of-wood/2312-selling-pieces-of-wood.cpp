typedef long long ll;
class Solution {
public:
    
    // map<pair<ll,ll>,ll>mp;
    ll dp[201][201];
    ll mp[201][201];
    ll getAns(ll m,ll n){
       
       
        ll ans=0;
        //either sell the same piece or either cut the same piece into horizontal or vertical parts and calc cost
        ans=mp[m][n];
        if(m==1&&n==1){
            return ans;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
       
       for(int i=1;i<=m/2;i++){
          ans=max(ans,getAns(i,n)+getAns(m-i,n));
          }
        
    
        for(int j=1;j<=n/2;j++){
            ans=max(ans,getAns(m,j)+getAns(m,n-j));
        }
        
        return dp[m][n]=ans;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        
        memset(dp,-1,sizeof dp);
            for(auto x:prices){
                mp[x[0]][x[1]]=x[2];
            }
        return getAns(m,n);
        
        
    }
};