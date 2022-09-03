class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int n=mat.size();
        int ans=0;
        for(int b=1;b<(1<<mat[0].size());b++){
            vector<vector<int>>temp=mat;
            int v=__builtin_popcount(b);
            if(v==cols){
            for(int j=0;j<mat[0].size();j++){
                if((b&(1<<j))){
                for(int i=0;i<mat.size();i++){
                    temp[i][j]=0;
                }
                }
            }
                int cnt=0;
                for(int i=0;i<mat.size();i++){
                    int br=0;
                    for(int j=0;j<mat[0].size();j++){
                        if(temp[i][j]==1){
                            br=1;
                            break;
                        }
                    }
                    if(br==0){
                        cnt++;
                    }
                }
                ans=max(cnt,ans);
                }
        }
        return ans;
    }
};