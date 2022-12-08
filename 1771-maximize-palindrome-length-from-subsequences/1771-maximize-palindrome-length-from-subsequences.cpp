class Solution {
public:
    int dp[2001][2001][2];
    int s;
    int getAns(string &str,int i,int j,bool check){
        if(i>j) return 0;
        if(i==j) return 1;
        int k=0;
        if(dp[i][j][check]!=-1) return dp[i][j][check];
        if(str[i]==str[j]) {
            
            if(i<s&&j>=s){
            int a=2+getAns(str,i+1,j-1,true); 
                k=max(k,a);
            }
            else{
                if(check){
                    int a=2+getAns(str,i+1,j-1,true); 
                    k=max(k,a);
                }
            }
            
            
        }
        else{
        int x=max(getAns(str,i+1,j,check),getAns(str,i,j-1,check));
        k=max(k,x);
        }
        return dp[i][j][check]=k;
    }
    int longestPalindrome(string w1, string w2) {
        memset(dp,-1,sizeof dp);
        string str=w1+w2;
        s=w1.size();
        int res= getAns(str,0,str.size()-1,false);
        return res==1?0:res;
    }
};