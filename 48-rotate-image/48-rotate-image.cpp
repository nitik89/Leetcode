class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               swap(matrix[j][i],matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            int k=0,j=matrix.size()-1;
            while(k<j){
            swap(matrix[i][k],matrix[i][j]);
                k++;
                j--;
            }
        }
    }
};