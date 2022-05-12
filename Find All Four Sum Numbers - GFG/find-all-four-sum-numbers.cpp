// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
         if(nums.size()<4){
            
            return {};
        }
        sort(nums.begin(),nums.end());
        
        int i=0;
        vector<vector<int>>ans;
        while(i<nums.size()-3){
            if(i==0||(i>0&&nums[i]!=nums[i-1])){
            int sum=target-nums[i];
            int start=i+1;
            while(start<nums.size()-2){
                int sumfor2=sum-nums[start];
                int idx=start+1;
                int j=nums.size()-1;
                if(start==i+1||(start>0&&nums[start]!=nums[start-1])){
                while(idx<j){
                    if(nums[idx]+nums[j]>sumfor2){
                        j--;
                    }
                    else if(nums[idx]+nums[j]<sumfor2){
                        idx++;
                    }
                    else{
                        ans.push_back({nums[i],nums[start],nums[idx],nums[j]});
                        idx++;
                        j--;
                        while(idx<j&&nums[idx-1]==nums[idx]) idx++;
                        while(idx<j&&nums[j+1]==nums[j]) j--;
                    }
                    
                }
                    start++;
                }
                else{
                    start++;
                }
            
            }
                i++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends