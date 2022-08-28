class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0;i<mat[0].size();i++){
            int row=0,col=i;
            vector<int>temp;
            while(row<mat.size()&&col<mat[0].size()){
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(),temp.end());
            row=0;
            col=i;
            int j=0;
            while(row<mat.size()&&col<mat[0].size()){
                mat[row][col]=temp[j];
                row++;
                col++;
                j++;
            }
        }
        
        
         for(int i=1;i<mat.size();i++){
            int row=i,col=0;
            vector<int>temp;
            while(row<mat.size()&&col<mat[0].size()){
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(),temp.end());
            row=i;
            col=0;
            int j=0;
            while(row<mat.size()&&col<mat[0].size()){
                mat[row][col]=temp[j];
                row++;
                col++;
                j++;
            }
        }
        return mat;
    }
};