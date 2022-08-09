class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<long long>dp(n,0);
        unordered_map<int,int>mp;
        dp[0]=1;
        mp[arr[0]]=0;
        int cnt=1;
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            int my=0;
            for(int j=0;j<i;j++){
                
                if(arr[i]%arr[j]==0&&mp.find(arr[i]/arr[j])!=mp.end()){
                    
                    
                    int val1=mp[arr[j]],val2=mp[arr[i]/arr[j]];
                   
                
                  my=my%mod+(dp[val1]%mod*dp[val2]%mod)%mod;  
                
                }
            }
            // cout<<my<<" ";
            dp[i]=my%mod+1;
            cnt=cnt%mod+dp[i];
            mp[arr[i]]=i;
            
        }
// for(auto x:dp){
//     cout<<x<<" ";
// }
        
        return cnt%mod;
        
    }
};