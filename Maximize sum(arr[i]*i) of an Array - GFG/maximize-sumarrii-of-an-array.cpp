// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long Maximize(int a[],int n)
    {
        sort(a,a+n);
        long long int sum=0;
        long long int prod=1;
        long long int mod=1000000007;
        
        for(long long int i=0;i<n;i++){
            prod=(a[i]*i);
            sum+=prod;
        }
        return sum%mod;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}  // } Driver Code Ends