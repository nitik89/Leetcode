class Solution {
public:
    int numOfWays(int n) {
       long long a=6,b=6;
        long long mod=1e9+7;
        for(int i=2;i<=n;i++){
            long long x=((a*3)+(b*2))%mod;
            long long y=((a*2)+(b*2))%mod;
            a=x%mod;
            b=y%mod;
        }
        int sum=(a%mod+b%mod)%mod;
        return sum;
    }
};