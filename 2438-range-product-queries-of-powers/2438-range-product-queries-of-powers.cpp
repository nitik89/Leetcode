class Solution {
public:
   int highestPowerof2(unsigned int n)
{
    // Invalid input
    if (n < 1)
        return 0;
    int res = 1;
    // Try all powers starting from 2^1
    for (int i = 0; i < 8 * sizeof(unsigned int); i++) {
        int curr = 1 << i;
        // If current power is more than n, break
        if (curr > n)
            break;
        res = curr;
    }
    return res;

}
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        
        vector<long long>vec;
        int mod=1e9+7;
        long long s = highestPowerof2(n);
        long long sum=0;
        // cout<<s<<" ";
        while(sum<=n&&s>=1){
            // cout<<sum<<" ";
            if(sum+s<=n){
            vec.push_back(s);
            sum+=s; 
            }
            s=s/2;
            
        }
        cout<<sum<<" ";
        reverse(vec.begin(),vec.end());
       // for(int i=1;i<vec.size();i++){
       //     vec[i]=((vec[i])*(vec[i-1]))%mod;
       // }
        // for(auto x:vec){
        //     cout<<x<<" ";
        // }
        vector<int>ans;
         for(auto x:q){
            int s=x[0];
            int e=x[1];
            long long a=1;
            for(int j=s;j<=e;j++){
                a*=(vec[j])%mod;
                a=a%mod;
            }
            ans.push_back(a);
            
        }
        return ans;
        
    }
};