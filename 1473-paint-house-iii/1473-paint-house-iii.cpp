class Solution {
public:
    int dp[101][21][101];
    int getAns(vector<int>&houses,vector<vector<int>>& cost,int m,int n,int target,int curr,int prev,int i){
        // cout<<"h"<<" ";
    if(i>=houses.size()){
        if(curr==target){
            
            return 0;
        }
        else{
            return 1e9;
        }
        
    }
        if(curr>target){
            return 1e9;
        }
        if(dp[curr][prev][i]!=-1){
            return dp[curr][prev][i];
        }
        
       
        if(houses[i]!=0&&prev==houses[i]){
               return dp[curr][prev][i]=getAns(houses,cost,m,n,target,curr,prev,i+1);
        }
        
        else if(houses[i]!=0){
                return dp[curr][prev][i]=getAns(houses,cost,m,n,target,curr+1,houses[i],i+1);
            }
        
        
        if(houses[i]==0){
        int cst=1e9;
            // cout<<cost[i].size()<<" ";
        for(int k=0;k<cost[i].size();k++){
            
                
                cst=min(cst,cost[i][k]+getAns(houses,cost,m,n,target,prev==k+1?curr:curr+1,k+1,i+1));
            
            
        }
            return dp[curr][prev][i]=cst;
        }
        return 1e9;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof dp);
        int val=getAns(houses,cost,m,n,target,0,0,0);
        if(val>=1e9){
            return -1;
        }
        return val;
    }
};