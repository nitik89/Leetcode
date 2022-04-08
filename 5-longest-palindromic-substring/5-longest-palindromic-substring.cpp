class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
      int mx=INT_MIN;
        int dp[n][n],idx=-1,vid=-1;
        memset(dp,0,sizeof dp);
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=1;
                }
                else if(gap==1){
                    dp[i][j]=(s[i]==s[j])?2:0;
                }
                else {
                if(s[i]==s[j]){
                    if(dp[i+1][j-1]>0){
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                    
                }
                if(mx<dp[i][j]){
                mx=dp[i][j];
                    idx=i;
                    vid=j;
                }
               
            }
        }
       
      
       return s.substr(idx,vid-idx+1);
   
    }
};