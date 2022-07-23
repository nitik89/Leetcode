class Solution {
public:
    long long check(long long m){
        return m*(m+1)/2;
    }
    int reachNumber(long long target) {
        long long i=1,j=abs(target),ans=-1;
        while(i<=j){
            long long mid=(i+j)/2;
            if(check(mid)>=abs(target)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        // cout<<ans<<"\n";
        for(long long m=ans;m<10000000;m++){
            long long sum=m*(m+1)/2;
            // cout<<sum<<" ";
            if((sum-abs(target))%2==0){
                return m;
            }
        }
        return ans;
    }
};








