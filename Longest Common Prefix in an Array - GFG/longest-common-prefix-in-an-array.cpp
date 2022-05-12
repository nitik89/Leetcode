// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string strs[], int N)
    {
         int curr=strs[0].size();
        for(int i=1;i<N;i++){
            int len=min((int)strs[i].size(),curr);
            int j=0;
            int size=0;
            while(j<len){
                if(strs[i][j]!=strs[i-1][j]){
                  break;  
                }
                size++;
                j++;
            }
            curr=min(curr,size);
            
        }
        return (strs[0].substr(0,curr))==""?"-1":strs[0].substr(0,curr);
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends