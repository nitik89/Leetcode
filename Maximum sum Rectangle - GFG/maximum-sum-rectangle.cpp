// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int n, int m, vector<vector<int>> a) {
        //  int n=a.size(),m=a[0].size();
      int mxs=INT_MIN;
      int sr=-1,sc=-1,er=-1,ec=-1;
      for(int j=0;j<m;j++){
          vector<int>sum(n,0);
          for(int i=j;i<m;i++){
              
              for(int k=0;k<n;k++){
                  sum[k]+=a[k][i];
              }
            //   unordered_map<int,int>mp;
              int sm=0,mx=INT_MIN;
              
              //1 d kadane in 2d
              for(int k=0;k<n;k++){
                 sm+=sum[k];
                 mx=max(mx,sm);
                 if(sm<0){
                     sm=0;
                 }
                 
              }
              mxs=max(mx,mxs);
          }
      }
     
      return mxs;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends