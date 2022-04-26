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
    bool _union(int i,int j){
        int x=findPar(i);
        int y=findPar(j);
        if(x==y){
            return false;
        }
        if(rank[x]>rank[y]){
            par[y]=x;
        }
        else if(rank[y]>rank[x]){
            par[x]=y;
        }
        else{
            par[x]=y;
            rank[y]++;
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>>vec;
        par.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
             vec.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
                }
            }
        }
        sort(vec.begin(),vec.end());
        int cnt=0;
        for(auto x:vec){
            int i=x[1];
            int j=x[2];
            if(_union(i,j)){
                cnt+=x[0];
            }
        }
        return cnt;
    }
};