class Solution {
public:
    void  dfs(vector<vector<char>>&board,int i,int j){
   
        if(i>=board.size()||j>=board[0].size()||i<0||j<0){
           
            return;
        }
        
        
      
        if(board[i][j]=='O'){
            
    board[i][j]='1';
        dfs(board,i+1,j);
          
         dfs(board,i,j+1);
              
        dfs(board,i-1,j);
              
        dfs(board,i,j-1);
              
         
        }
       
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        // vector<vector<int>>vis(n,vector<int>(0,m));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
              if(board[i][j]=='O'&&(i==0||j==0||i==board.size()-1||j==board[i].size()-1)){
                  dfs(board,i,j);
              }
                  
                }
            }
        
      
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
              if(board[i][j]=='O'){
                  board[i][j]='X';
              }
                }
            }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
              if(board[i][j]=='1'){
                  board[i][j]='O';
              }
                }
            }
        
        
    }
};