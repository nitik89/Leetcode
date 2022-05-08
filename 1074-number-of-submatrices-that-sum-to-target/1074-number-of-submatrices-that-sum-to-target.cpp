class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        //generating the prefix sum type matrix
        for(int i=0;i<row;i++)
        {
            for(int j=1;j<col;j++) matrix[i][j]+=matrix[i][j-1];
        }
        for(int j=0;j<col;j++)
        {
            for(int i=1;i<row;i++) matrix[i][j]+=matrix[i-1][j];
        }
       
        int cnt=0;
              
           for(int i=0;i<col;i++){
            vector<int>sum(row,0);
               
            for(int j=i;j<col;j++){
                unordered_map<int,int>mp;
                mp[0]++;
                for(int k=0;k<row;k++){
                    int sm=matrix[k][j]-(i-1>=0?matrix[k][i-1]:0);
                    // cout<<sm<<" ";
                    if(mp.find(sm-target)!=mp.end()){
                        cnt+=mp[sm-target];
                    }
                    mp[sm]++;
                }
                
                
            }
           }
        return cnt;
    }
};