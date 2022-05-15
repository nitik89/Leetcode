// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int facDigits(int N){
        double num=0;
        for(int i=2;i<=N;i++){
            num+=(log10(i));
        }
        // cout<<num<<" ";
        
        return ceil(num);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.facDigits(n)<<"\n";
       
        
    }
    return 0;
}  // } Driver Code Ends