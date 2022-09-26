class Solution {
public:
    int find(int x,vector<int>&par){
        if(par[x]==x){
            return x;
        }
        int temp=find(par[x],par);
        par[x]=temp;
        return temp;
    }
    void _union(int x,int y,vector<int>&par,vector<int>&rank){
        int lx=find(x,par);
        int ly=find(y,par);
        if(rank[lx]>rank[ly]){
            par[ly]=lx;
        }
        else if(rank[lx]<rank[ly]){
            par[lx]=ly;
        }
        else{
            par[lx]=ly;
            rank[ly]++;
        }
    }
    bool equationsPossible(vector<string>& eq) {
      vector<int>par(26);
        vector<int>rank(26,0);
        for(int i=0;i<26;i++){
            par[i]=i;
        }
        
        for(int i=0;i<eq.size();i++){
            if(eq[i][1]=='='){
                _union((eq[i][0]-'a'),(eq[i][3]-'a'),par,rank);
            }
        }
          for(int i=0;i<eq.size();i++){
            if(eq[i][1]=='!'){
                int parx=find(eq[i][0]-'a',par);
                int pary=find(eq[i][3]-'a',par);
                if(parx==pary){
                    return false;
                }
            }
        }
        return true;
        
        
    }
};