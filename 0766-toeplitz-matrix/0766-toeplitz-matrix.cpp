class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //rows 
        int n=matrix.size(),m=matrix[0].size();
        for(int j=0;j<m;j++){
            int x=matrix[0][j];
            int sr=0,sc=j;
            while(sr<n&&sc<m){
                if(matrix[sr][sc]!=x){
                    return false;
                }
                sr++;
                sc++;
            }
        }
        for(int i=1;i<n;i++){
            int x=matrix[i][0];
            int sr=i,sc=0;
            while(sr<n&&sc<m){
                if(matrix[sr][sc]!=x){
                    return false;
                }
                sr++;
                sc++;
            }
        }
        return true;
    }
};