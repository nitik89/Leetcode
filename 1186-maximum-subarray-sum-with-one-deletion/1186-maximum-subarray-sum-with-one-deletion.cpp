class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>lf(n);
        lf[0]=arr[0];
    
        int sum=arr[0];
        for(int i=1;i<n;i++){
            sum+=arr[i];
            if(sum < arr[i]){
                sum=arr[i];
            }
            
            lf[i]=sum;
            
        }
         vector<int>rgt(n);
        rgt[n-1]=arr[n-1];
         sum=arr[n-1];
        for(int i=n-2;i>=0;i--){
            sum+=arr[i];
            if(sum < arr[i]){
                sum=arr[i];
            }
            rgt[i]=sum;
            
        }
        int ans=INT_MIN;
        for(int i=1;i<n-1;i++){
            ans=max(ans,lf[i-1]+rgt[i+1]);
            ans=max(ans,lf[i-1]);
            ans=max(ans,rgt[i+1]);
        }
        if(n>=2){
            ans=max(ans,lf[n-2]);
            ans=max(ans,lf[n-1]);
        }
    ans=max(ans,rgt[0]);
        return ans;
    }
};