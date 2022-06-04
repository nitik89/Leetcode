class Solution {
public:
    bool isSafe(vector<string>temp,int row,int col,int n){
        
        for(int i=0;i<row;i++){
            if(temp[i][col]=='Q'){
                return false;
            }
        }
      int i=row-1,j=col-1;
        while(i>=0&&j>=0){
            if(temp[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
         i=row-1;
        j=col+1;
        while(i>=0&&j<n){
            if(temp[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void getAns(vector<vector<string>>&ans,int n,int row,vector<string>&temp){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            
            if(isSafe(temp,row,i,n)){
                
                temp[row][i]='Q';
                getAns(ans,n,row+1,temp);
                 temp[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
       vector<string> temp(n,string(n, '.'));
        getAns(ans,n,0,temp);
        return ans;
    }
};