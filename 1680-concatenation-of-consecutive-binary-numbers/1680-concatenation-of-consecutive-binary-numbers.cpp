class Solution {
public:
    int concatenatedBinary(int n) {
        int curr=0;
        long long ans=0;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
             int bits=(int)log2(i)+1;
          ans=((ans<<bits)%mod+i) ;
       
           
        }
        return ans%mod;
    }
};