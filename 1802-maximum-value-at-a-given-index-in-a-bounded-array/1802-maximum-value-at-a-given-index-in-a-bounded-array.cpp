class Solution {
public:
    int isPos(long long n,long long v,long long idx,long long sum ){
        long long mySum=(v*(v+1)/2);
        //create the left sum and the right sum
        
       if(idx>=v){
           mySum+=(idx-v+1);
          }
        else{
            long long ele=(v-idx-1);
            long long sm=((ele)*(ele+1))/2;
            mySum-=sm;
        }
        long long diff=(n-idx-1);
        long long sm=((v-1)*(v))/2;
        if(diff>=(v-1)){
            mySum+=sm;
            mySum+=(n-idx-v);
        }
        else{
            long long ms=(v-diff-1);
            long long tot=((ms)*(ms+1))/2;
            mySum+=sm;
            mySum-=tot;
        }
        return mySum<=sum;
        
        
    }
    int maxValue(int n, int index, int maxSum) {
        long long s=1,e=maxSum;
        int ans=-1;
        while(s<=e){
            long long mid=(s+e)/2;
            if(isPos(n,mid,index,maxSum)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};