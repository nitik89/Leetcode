class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
     vector<vector<int>>vec(8,vector<int>(8,0));
        for(auto x:queens){
            vec[x[0]][x[1]]=1;
        }
        vector<vector<int>>ans;
        vector<vector<int>>dir={{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1},{0,1},{0,-1}};
        for(int i=0;i<dir.size();i++){
            int x=dir[i][0];
            int y=dir[i][1];
            int myx=king[0];
            int myy=king[1];
            while(myx>=0&&myx<8&&myy>=0&&myy<8){
                if(vec[myx][myy]==1){
                    ans.push_back({myx,myy});
                    break;
                }
                myx+=x;
                myy+=y;
                
                
            }
        }
        return ans;
    }
};