class Solution {
public:
    int isValid(vector<string>&pizza,int sr,int sc,int er,int ec){
        for(int i=sr;i<er;i++){
            for(int j=sc;j<ec;j++){
                if(pizza[i][j]=='A'){
                    return 1;
                }
            }
        }
        return false;
    }
    int dp[51][51][11];
    int mod=1e9+7;
    int getAns(vector<string>&pizza,int i,int j,int cuts,int k){
        
        //horizontal ith row pe cut maro
        if(i>pizza.size()||j>pizza[0].size()){
            
            return 0;
        }
        if(k==1){
            return isValid(pizza,i,j,pizza.size(),pizza[0].size());
        }
        int cnt=0;
        if(dp[i][j][cuts]!=-1){
            return dp[i][j][cuts];
        }
        for(int row=i;row<pizza.size();row++){
            //does exits 
            if(isValid(pizza,i,j,row+1,pizza[0].size())){
                if(cuts+1==k-1){
                    
                    if(isValid(pizza,row+1,j,pizza.size(),pizza[0].size())){
                        cnt=cnt%mod+1;
                    }
                    
                }
                else{
            cnt=cnt%mod+getAns(pizza,row+1,j,cuts+1,k);
                }
            }
        }
        
        //vertical cuts
        for(int col=j;col<pizza[0].size();col++){
           
             if(isValid(pizza,i,j,pizza.size(),col+1)){
                
                  if(cuts+1==k-1){
                      
                     if(isValid(pizza,i,col+1,pizza.size(),pizza[0].size())){
                         // cout<<i<<" "<<col+1<<"\n";
                        cnt=cnt%mod+1;
                    }
                     
                    
                }
                 else{
            cnt=cnt%mod+getAns(pizza,i,col+1,cuts+1,k);
                 }
             }
        }
                return dp[i][j][cuts]=cnt%mod;
    }
    
    int ways(vector<string>& pizza, int k) {
        //2 types of cuts horizontal and vertical
        //unoptimized code
        memset(dp,-1,sizeof dp);
       return getAns(pizza,0,0,0,k);
    }
};