class Solution {
public:
    int unequalTriplets(vector<int>& arr) {
        int n=arr.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]!=arr[j]&&arr[j]!=arr[k]&&arr[i]!=arr[k]){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};