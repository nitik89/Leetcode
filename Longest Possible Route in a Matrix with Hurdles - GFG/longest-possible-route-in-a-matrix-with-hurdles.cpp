// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
int ans;
void getAns(vector<vector<int>>mat,int sr,int sc,int er,int ec,int p,vector<vector<int>>&vis){
    
    if(sr<0||sc<0||sr>=mat.size()||sc>=mat[0].size()||vis[sr][sc]){
        return;
    }
    if(sr==er&&sc==ec){
        ans=max(ans,p);
        return;
    }
    if(mat[sr][sc]==0){
        return;
    }
    vis[sr][sc]=1;
    getAns(mat,sr+1,sc,er,ec,p+1,vis);
    getAns(mat,sr,sc+1,er,ec,p+1,vis);
    getAns(mat,sr-1,sc,er,ec,p+1,vis);
    getAns(mat,sr,sc-1,er,ec,p+1,vis);
    vis[sr][sc]=0;
}
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int n=matrix.size(),m=matrix[0].size();
        ans=INT_MIN;
        vector<vector<int>>vis(n,vector<int>(m,0));
        getAns(matrix,xs,ys,xd,yd,0,vis);
        return ans==INT_MIN?-1:ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends