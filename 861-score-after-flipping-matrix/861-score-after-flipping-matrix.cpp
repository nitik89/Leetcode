class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            int on=0,ch=1;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0&&on==0){
                    ch=0;
                    break;
                }
                else if(grid[i][j]){
                    on++;
                }
            }
            if(!ch){
                //flip in this case
                for(int j=0;j<m;j++){
                    grid[i][j]=(1-grid[i][j]);
                }
            }
        }
        //columnwise check
        for(int j=0;j<m;j++){
            int one=0,zero=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]){
                    one++;
                }
                else{
                    zero++;
                }
            }
            if(zero>one){
                for(int i=0;i<n;i++){
                    grid[i][j]=(1-grid[i][j]);
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int n=0;
            int sf=0;
            for(int j=m-1;j>=0;j--){
               n|=((grid[i][j]<<sf));
                sf++;
            }
            sum+=n;
        }
        
        return sum;
        
    }
};



