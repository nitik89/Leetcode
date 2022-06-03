class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int diff=arr[0]-1;
        int miss=diff;
        if(miss>=k){
               return k;
           }
        // cout<<miss<<" ";
        for(int i=1;i<arr.size();i++){
            int oldone=miss;
            diff=arr[i]-arr[i-1];
            if(diff>1){
                miss+=(diff-1);
            }
            if(miss>=k){
               return arr[i-1]+k-oldone;
           }
            
           
        }
        return arr[arr.size()-1]+(k-miss);
    }
};