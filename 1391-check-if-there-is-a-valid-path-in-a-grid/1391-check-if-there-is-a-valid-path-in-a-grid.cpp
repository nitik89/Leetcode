class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int findPar(int x){
        if(par[x]==x){
            return x;
        }
        int y=findPar(par[x]);
        par[x]=y;
        return y;
    }
    void _union(int x,int y){
        int x1=findPar(x);
        int y1=findPar(y);
        // cout<<x<<" "<<y<<"\n";
        if(x1!=y1){
        if(rank[x1]>rank[y1]){
            par[y1]=x1;
            
        }
        else if(rank[x1]<rank[y1]){
            par[x1]=y1;
            
        }
        else{
            par[x1]=y1;
            rank[y1]++;
        }
        }
    }
    int getAd(int r,int c,int tc){
        return r*tc+c;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        par.resize(n*m);
        rank.resize(n*m);
        for(int i=0;i<n*m;i++){
            rank[i]=1;
            par[i]=i;
        }
        vector<vector<int>>drx={{},{4,1,6},{},{1,4,6},{},{1,6,4},{}};
        vector<vector<int>>drl={{},{},{2,3,4},{},{},{2,3,4},{2,3,4}};

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int x=grid[i][j];
                if(i-1>=0){
                    for(int k=0;k<drl[x].size();k++){
                        int y=grid[i-1][j];
                        if(y==drl[x][k]){
                            // cout<<i<<" "<<j<<"\n";
                            _union(getAd(i,j,m),getAd(i-1,j,m));
                        }
                    }
                }
                if(j-1>=0){
                    for(int k=0;k<drx[x].size();k++){
                        int y=grid[i][j-1];
                        if(y==drx[x][k]){
                            _union(getAd(i,j,m),getAd(i,j-1,m));
                        }
                    }
                }
            }
        }
        int a=findPar(0);
        int b=findPar(n*m-1);
        // cout<<a<<" "<<b<<"\n";
        return a==b;
    }
};






