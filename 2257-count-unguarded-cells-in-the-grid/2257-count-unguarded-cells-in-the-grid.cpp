class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>>vec(m,(vector<int>(n,0)));
        for(int i=0;i<g.size();i++){
            vec[g[i][0]][g[i][1]]=2;
        }
        for(int i=0;i<w.size();i++){
            vec[w[i][0]][w[i][1]]=3;
        }
        for(int i=0;i<g.size();i++){
            int x=g[i][0];
            int y=g[i][1];
            
            for(int k=x-1;k>=0;k--){
                if(vec[k][y]==3||vec[k][y]==2){
                    break;
                }
                else{
                    vec[k][y]=1;
                }
                
            }
            for(int k=x+1;k<m;k++){
                if(vec[k][y]==3||vec[k][y]==2){
                    break;
                }
                else{
                    vec[k][y]=1;
                }
                
            }
            for(int k=y+1;k<n;k++){
                if(vec[x][k]==3||vec[x][k]==2){
                    break;
                }
                else{
                    vec[x][k]=1;
                }
                
            }
            for(int k=y-1;k>=0;k--){
                if(vec[x][k]==3||vec[x][k]==2){
                    break;
                }
                else{
                    vec[x][k]=1;
                }
                
            }
        }
         int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j]==0){
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};