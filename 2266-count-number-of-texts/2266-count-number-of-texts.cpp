class Solution {
public:
    int mod=1e9+7;
    int dp[100008];
    int getAns(string& str,int idx){
        if(idx>=str.size()){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        char curr=str[idx];
        int cnt=0;
        int ans=0;
        for(int i=idx;i<str.size();i++){
            if(str[i]==curr){
                cnt+=1;
                if((curr=='7'||curr=='9')&&(cnt<=4)){
                    
                   ans=ans%mod+getAns(str,i+1)%mod;
                }
                else if(cnt<=3){
                    // cout<<curr<<" "<<i<<" "<<cnt<<"\n";
                    ans=ans%mod+getAns(str,i+1)%mod;
                }
                else{
                   break; 
                }
            }
            else{
                break;
            }
        }
        return dp[idx]=ans%mod;
    }
    int countTexts(string pk) {
        memset(dp,-1,sizeof dp);
        return getAns(pk,0);
    }
};