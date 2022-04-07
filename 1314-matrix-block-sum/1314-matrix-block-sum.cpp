class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>pre=mat;
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
          for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
               mat[i][j]+=mat[i-1][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int row=min(n-1,i+k);
                int col=min(m-1,j+k);
                int sum=mat[row][col];//actual sum lies here
                int top=i-k-1>=0?mat[i-k-1][col]:0;
                int bottom=j-k-1>=0?mat[row][j-k-1]:0;
                int up=(i-k-1>=0&&j-k-1>=0)?mat[i-k-1][j-k-1]:0;
                sum=sum-top-bottom+up;
                ans[i][j]=sum;
                
            }
        }
        return ans;
        
       
        return ans;
        
    }
};