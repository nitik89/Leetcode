class Solution {
public:
    
    vector<int>prefix;
    int dp[31][31];
    int getAns(int l,int r,vector<int>&stones,int k){
        
        if(l>r){
            return 0;
        }
        if(r-l+1<k){
            return 0;
        }
        if(r-l+1==k){
            return dp[l][r]=prefix[r+1]-prefix[l];
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        
        int sum=INT_MAX;
        for(int i=l;i<r;i+=(k-1)){
            int lft=getAns(l,i,stones,k);
            int rgt=getAns(i+1,r,stones,k);
            sum=min(lft+rgt,sum);
        }
        //getting the min cost from sub parts 
        
        //now the whole array can act like it so
        if((r-l)%(k-1)==0){
            sum+=prefix[r+1]-prefix[l];
        }
        return dp[l][r]=sum;
        
        
        
    }
    int mergeStones(vector<int>& stones, int k) {
        
        int n=stones.size();
        if((n-1)%(k-1)!=0){
            return -1;
        }
        prefix.resize(n+1,0);
        prefix[1]=stones[0];
        for(int i=2;i<prefix.size();i++){
            prefix[i]=prefix[i-1]+stones[i-1];
        }
        memset(dp,-1,sizeof dp);
        return getAns(0,n-1,stones,k);
        
    }
};