// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    if(n==1){
     return nums[0];
 }
        long long mx=1,mn=1,mxans=LONG_MIN,mnans=LONG_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                mxans=max(mxans,(long long)0);
                mx=1;
                mn=1;
            }
            else{
            long long temp=mx;
              mx=max((long long)nums[i],max(mx*nums[i],mn*nums[i]));
            mn=min((long long)nums[i],min(temp*nums[i],mn*nums[i]));
            mxans=max(mxans,max(mx,mn));
            } 
           
        }
        return mxans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends