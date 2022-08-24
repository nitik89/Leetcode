class Solution {
public:
    
//     int getAns(vector<int>&obs,int curr,int i){
//         if(i == obs.size()-1){
//             return 0;
//         }
//         if(dp[i][curr]!=-1){
//             return dp[i][curr];
//         }
//         int mn=1e9;
//         if(obs[i+1]==curr){
//             if(curr-1>=1&&obs[i]!=curr-1){
//                 mn=min(mn,1+getAns(obs,curr-1,i+1));
//             }
//             if(curr+1<=3&&obs[i]!=curr+1){
//                 mn=min(mn,1+getAns(obs,curr+1,i+1));
//             }
//             if(curr+2<=3&&obs[i]!=curr+2){
//                 mn=min(mn,1+getAns(obs,curr+2,i+1));
//             }
//             if(curr-2>=1&&obs[i]!=curr-2){
//                 mn=min(mn,1+getAns(obs,curr-2,i+1));
//             }
//         }
//         else{
//             //move in the same
//             mn=min(mn,getAns(obs,curr,i+1));
//         }
//         return dp[i][curr]=mn;
        
//     }
    int minSideJumps(vector<int>& obs) {
        int n=obs.size()-1;
        vector<vector<int>>dp(n+1,vector<int>(4,1e9));
        // memset(dp,1e9,sizeof dp);
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n][2]=0;
        dp[n][3]=0;
        // cout<<dp[n][0]<<" "<<dp[n][1]<<" "<<dp[n][2]<<" "<<dp[n][3]<<"\n";
        // cout<<n-1<<"\n";
        for(int i=n-1;i>=0;i--){
            // cout<<obs[i]<<" ";
            
            for(int curr=1;curr<=3;curr++){
                int mn=1e9;
          if(obs[i+1]==curr){
            if(curr-1>=1&&obs[i]!=curr-1){
                mn=min(mn,1+dp[i+1][curr-1]);
            }
            if(curr+1<=3&&obs[i]!=curr+1){
               
                mn=min(mn,1+dp[i+1][curr+1]);
            }
            if(curr+2<=3&&obs[i]!=curr+2){
                mn=min(mn,1+dp[i+1][curr+2]);
            }
            if(curr-2>=1&&obs[i]!=curr-2){
                mn=min(mn,1+dp[i+1][curr-2]);
            }
        }
        else{
            //move in the same
            
            if(obs[i]!=curr){
                
            mn=min(mn,dp[i+1][curr]);
            }
            else {
                // cout<<i<<" "<<curr<<" "<<mn<<"\n";
                dp[i][curr]=1e9;
            }
        }
                // cout<<mn<<" ";
                 
                dp[i][curr]=mn;
            }
            // cout<<"\n";
        }
       
        return min({dp[0][1]+1,dp[0][2],dp[0][3]+1});
    }
};