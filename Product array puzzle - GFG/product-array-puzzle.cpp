// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>&arr, int n) {
       
        vector<long long int>left(n,1);
        vector<long long int>right(n,1);
        vector<long long int>ans(n,1);
        left[0]=arr[0];
        for(int i=1;i<left.size();i++){
            left[i]=left[i-1]*arr[i];
        }
        right[n-1]=arr[n-1];
        for(int i=left.size()-2;i>=0;i--){
            right[i]=right[i+1]*arr[i];
        }
        
        
        for(int i=0;i<ans.size();i++){
            ans[i]*=(i-1>=0?left[i-1]:1)*(i+1<n?right[i+1]:1);
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends