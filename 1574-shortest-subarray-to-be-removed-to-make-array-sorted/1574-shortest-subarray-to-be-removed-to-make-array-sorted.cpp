class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int lf=0,rg=n-1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                lf++;
            }
            else{
                break;
            }
            
        }
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1]){
                rg--;
            }
            else{
                break;
            }
        }
        if(lf==arr.size()-1){
            return 0;
        }
        int ans=min(n-lf-1,rg);
        for(int i=0;i<=lf;i++){
            //we will do a binary search to find the perfect seq
            
            int idx=lower_bound(arr.begin()+rg,arr.end(),arr[i])-arr.begin();
            ans=min(ans,idx-i-1);
            
        }
        return ans;
        
    }
};