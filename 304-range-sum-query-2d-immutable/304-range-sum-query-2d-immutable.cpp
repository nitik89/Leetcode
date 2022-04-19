class NumMatrix {
public:
    vector<vector<int>>vec;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vec.resize(n + 1, vector<int>(m + 1));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                vec[i][j]+=vec[i][j-1];
            }
        }
       
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                vec[i][j]+=vec[i-1][j];
            }
        }
         
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        if(col1-1>=0){
            sum-=vec[row2][col1-1];
           
        }
        if(row1-1>=0){
            sum-=vec[row1-1][col2];
             // cout<<vec[row1-1][col2]<<" ";
        }
        if(col1-1>=0&&row1-1>=0){
            sum+=vec[row1-1][col1-1];
        }
        sum+=vec[row2][col2];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */