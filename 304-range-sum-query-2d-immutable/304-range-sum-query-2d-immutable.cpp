class NumMatrix {
public:
    vector<vector<int>>vec;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vec.resize(n + 1, vector<int>(m + 1,0));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec[i+1][j+1]=vec[i+1][j]+matrix[i][j]+vec[i][j+1]-vec[i][j];
            }
        }
        
        
         
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
         return vec[row2 + 1][col2 + 1] - vec[row1][col2 + 1] - vec[row2 + 1][col1] + vec[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */