class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[10][10]={0};
        int cell[10][10]={0};
        int col[10][10]={0};
        
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                int val=board[i][j] - '0';
                row[i][val]++;
                col[j][val]++;
                int add=3*(i/3)+(j/3);
               // cout<<add<<" ";
                    // cout<<add<<" ";
                cell[add][val]++;
                if(row[i][val]>1){
                    // cout<<i<<" "<<j<<" ";
                    return false;
                }
                    if(col[j][val]>1){
                        // cout<<i<<" "<<j<<" ";
                    return false;
                }
                    if(cell[add][val]>1){
                        // cout<<i<<" "<<j<<" "<<add<<" ";
                    return false;
                }
                }
            }
        }
        return true;
    }
};