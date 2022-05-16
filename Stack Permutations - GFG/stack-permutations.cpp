// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &a,vector<int> &b){
        stack<int>stk;
        int i=0,j=0;
        while(i<a.size()&&j<b.size()){
            stk.push(a[i]);
            i++;
            while(!stk.empty()&&stk.top()==b[j]){
                stk.pop();
                j++;
            }
        }
    return stk.empty()?1:0;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends