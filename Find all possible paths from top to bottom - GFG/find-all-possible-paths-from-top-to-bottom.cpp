// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
vector<vector<int>>vec;
void getAns(int n,int m,int i,int j,vector<vector<int>>&grid,vector<int>temp){
    if(i<0||j<0||i>=n||j>=m){
        return;
    }
    if(i==n-1&&j==m-1){
        temp.push_back(grid[i][j]);
        vec.push_back(temp);
        return;
    }
    temp.push_back(grid[i][j]);
    getAns(n,m,i+1,j,grid,temp);
    getAns(n,m,i,j+1,grid,temp);
    temp.pop_back();
}
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int>temp;
        getAns(n,m,0,0,grid,temp);
        return vec;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends