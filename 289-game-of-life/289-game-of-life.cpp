class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                // cout<<board[i][j]<<" ";
               int count=0;
                    if(j+1<board[0].size()&&(board[i][j+1]==1||board[i][j+1]==-1)){
                        count++;
                    }
                     if(i+1<board.size()&&(board[i+1][j]==1||board[i+1][j]==-1)){
                         count++;
                     }
                    if(i-1>=0&&(board[i-1][j]==1||board[i-1][j]==-1)){
                            count++;
                    }
                    if(j-1>=0&&(board[i][j-1]==1||board[i][j-1]==-1)){
                            count++;
                    }
                     if(j-1>=0&&i-1>=0&&(board[i-1][j-1]==1||board[i-1][j-1]==-1)){
                            count++;
                    }
                    if(j+1<board[0].size()&&i-1>=0&&(board[i-1][j+1]==1||board[i-1][j+1]==-1)){
                            count++;
                    }
                    if(j-1>=0&&i+1<board.size()&&(board[i+1][j-1]==1||board[i+1][j-1]==-1)){
                            count++;
                    }
                    if(j+1<board[0].size()&&i+1<board.size()&&(board[i+1][j+1]==1||board[i+1][j+1]==-1)){
                            count++;
                    }
                // if(i==1&&j==0){
                //     cout<<board[i][j]<<"\n";
                //     cout<<count<<"\n";
                // }
                    if(board[i][j]==1){
                        if(count>3){
                            board[i][j]=-1;
                        }
                        else if(count<2){
                            board[i][j]=-1;
                        }
                    }
                else if(board[i][j]==0){
                    if(count==3){
                        board[i][j]=-2;
                    }
                }
                        
                }
            // cout<<"\n";
        }
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==-2){
                    board[i][j]=1;
                }
                else if(board[i][j]==-1){
                    board[i][j]=0;
                }
            }
        }
}
                        
};