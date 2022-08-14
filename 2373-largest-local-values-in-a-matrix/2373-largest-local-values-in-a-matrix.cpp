class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>vec;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int mx=INT_MIN;
                for(int k=i;k<i+3;k++){
                    for(int p=j;p<j+3;p++){
                        mx=max(mx,grid[k][p]);
                    }
                }
                vec.push_back(mx);
            }
        }
        int l=n-2,b=n-2;
        vector<vector<int>>ans(l,(vector<int>(b)));
       
        int idx=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<b;j++){
                ans[i][j]=vec[idx];
                              idx++;
            }
        }
        return ans;
    }
};