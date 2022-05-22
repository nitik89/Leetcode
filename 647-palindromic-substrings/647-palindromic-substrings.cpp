class Solution {
public:
    int countSubstrings(string s) {
        int dp[s.size()][s.size()];
        memset(dp,0,sizeof dp);
        int cnt=0;
     for(int g=0;g<s.size();g++){
         for(int i=0,j=g;j<s.size();i++,j++){
             if(g==0){
                 dp[i][j]=1;
             }
             else if(g==1){
                 if(s[i]==s[j]){
                 dp[i][j]=1;
                     }
             }
             else{
                 if(s[i]==s[j]){
                 dp[i][j]=dp[i+1][j-1];
                     }
             }
             if(dp[i][j]){
                 cnt++;
             }
         }
     }
        return cnt;
    }
};