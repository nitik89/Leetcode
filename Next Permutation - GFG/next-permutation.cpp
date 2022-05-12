// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> nums){
         
        int i=n-2;
        int j=n-1;
        while(i>=0&&nums[i]>=nums[i+1]){
            i--;  //find the break point ie 1 2 3 5 4 find where 3 lies
            
        }
        //5 4 3 2 1 to avoid this base case
        if(i>=0){
            while(i<j&&nums[j]<=nums[i]){ //find an index smaller than the i th index
                j--;
            }
            swap(nums[i],nums[j]);
        }
        // cout<<i<<" "<<j<<"\n";
        //now swap them to generate 
        //generate a smaller version reverse the in between i+1 and till the last index
         reverse(nums.begin()+1+i,nums.end());
         return nums;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends