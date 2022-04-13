class Solution {
public:
    int count;
    int find(int i,vector<int>&par){
        if(par[i]==i){
            return i;
        }
       int temp=find(par[i],par);
        par[i]=temp;
        return temp;
    }
    void _union(int i,int j,vector<int>&par,vector<int>&rank){
        int x=find(i,par);
        int y=find(j,par);
        if(x!=y){
            if(rank[x]>rank[y]){
                par[y]=x;
            }
            else if(rank[x]<rank[y]){
                par[x]=y;
            }
            else{
                par[x]=y;
                rank[y]++;
            }
        }
       
        else{//if par is same means cycle is there so increase the count
            count++;
        }
        
    }
    int regionsBySlashes(vector<string>& grid) {
        //we will make a (n+1)*(n+1) matrix of points
        int n=grid.size();
        int dots=n+1;
       vector<int>par(dots*dots); 
        vector<int>rank(dots*dots);
       
        count=1;//initally one point could be there
        
        for(int i=0;i<dots*dots;i++){
            par[i]=i;
            rank[i]=1;
        }
       
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                if(i==0||j==0||i==dots-1||j==dots-1){ 
    //the corner points need to be merged with the 0
                    int cellno=i*dots+j;//calculating the cellno
                    
                    if(cellno!=0){
                    _union(0,cellno,par,rank);
                    }
                }
            }
        }
       
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]=='/'){
                    // "/"   like 0,0 we have this one so 0,1 and 1,0 will be joined
                     int cellno1=i*dots+j+1;
                     int cellno2=(i+1)*dots+j;
                    
                    _union(cellno1,cellno2,par,rank);
                }
                else if(grid[i][j]=='\\'){
                    //and this point 0,0 and 1,1 will be joined merging them by union
                      int cellno1=i*dots+j;
                     int cellno2=(i+1)*dots+j+1;
                    _union(cellno1,cellno2,par,rank);
                }
            }
        }
        //  for(int i=0;i<dots*dots;i++){
        //    cout<<rank[i]<<" ";
        // }
       
        return count;
        
        
    }
};