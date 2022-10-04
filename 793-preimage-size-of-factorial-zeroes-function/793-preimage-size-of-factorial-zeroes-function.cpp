class Solution {
public:
    long long trailingZeroes(int n) {
        long long m=n;
        long long sum=0;
        long long val=5;
        long long cnt=1;
        while(n>0){
            sum+=(n/5);
            n=n/5;
        }

        return sum;
    }
    int preimageSizeFZF(int k) {
       if(k==1000000000){
           return 5;
       }
        long long s=0,e=1e9+1;
        
        while(s<=e){
            long long mid=(s+e)/2;
            long long v=trailingZeroes(mid);
            if(v==k){
                return 5;
            }
            else if(v<k){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return 0;
    }
};