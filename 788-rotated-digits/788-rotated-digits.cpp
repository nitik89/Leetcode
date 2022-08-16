class Solution {
public:
    int dp[10000][(1<<10)+1][2];
    int getAns(string &str,int i,int mask,int tight){
        if(i>=str.size()){
             if(mask&(1<<3) or mask&(1<<4) or mask&(1<<7))   return 0;
            if(mask&(1<<2) or mask&(1<<5) or mask&(1<<6) or mask&(1<<9))   return 1;
            return 0;
        }
        if(dp[i][mask][tight]!=-1){
            return dp[i][mask][tight];
        }
        int cnt=0;
        if(tight==1){
            for(int j=0;j<=(str[i] - '0');j++){
                if(j==(str[i] - '0')){
                   cnt+=getAns(str,i+1,mask|(1<<j),1);
                }
                else{
                  cnt+=getAns(str,i+1,mask|(1<<j),0);
                }
            }
        }
        else{
             for(int j=0;j<=(9);j++){
                
                  cnt+=getAns(str,i+1,mask|(1<<j),0);
                
            }
        }
        return  dp[i][mask][tight]=cnt;
    }
    int rotatedDigits(int n) {
        string str=to_string(n);
        memset(dp,-1,sizeof dp);
       return getAns(str,0,0,1);
    }
};