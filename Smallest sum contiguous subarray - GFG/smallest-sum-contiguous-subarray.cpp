// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
    int mx=INT_MAX,sum=0,mnEle=INT_MAX;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum>0){
            sum=0;
        }
        mnEle=min(mnEle,a[i]);
        mx=min(sum,mx);
    }
    if(mx==0){
        return mnEle;
    }
    return mx;
  }
};


// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends