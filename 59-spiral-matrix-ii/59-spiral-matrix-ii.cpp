class Solution {
public:
    vector<vector<int>> generateMatrix(int q) {
        vector<vector<int>> vec( q , vector<int> (q, 0));
          int i=0,j=0,m=vec.size()-1,n=vec[0].size()-1;
        int nm=0;
          while(i<=m&&j<=n){
        int k=j;
        while(k<=n){
            vec[i][k]=++nm;
            k++;
        }
        
        i++;
        int f=i;
        while(f<=m){
        vec[f][n]=++nm;
            f++;
        }
        n--;
        if(i<=m){
        int g=n;
        while(g>=j){
            vec[m][g]=++nm;
            g--;
        }
        
        m--;
        }
            if(j<=n){
        int p=m;
        while(p>=i){
            vec[p][j]=++nm;
            p--;
        }
            
        j++;
            }
        
        }
        return vec;
    }
};