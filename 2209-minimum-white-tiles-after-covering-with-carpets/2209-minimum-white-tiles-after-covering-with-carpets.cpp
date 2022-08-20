class Solution {
public:
    int dp[1001][1001];
    int getAns(int i,string &floor,vector<int>&pre,int num,int len){
        if(i>=floor.size()||num==0){
            return 0;
        }
        if(dp[i][num]!=-1){
            return dp[i][num];
        }
        int mx=INT_MIN;
        
           int calc=((i+len-1>=floor.size())?pre[floor.size()-1]:pre[i+len-1])-(i-1>=0?pre[i-1]:0);
            mx=max(mx,calc+getAns(i+len,floor,pre,num-1,len));
        
        mx=max(mx,getAns(i+1,floor,pre,num,len));
        return dp[i][num]=mx;
    }
    int minimumWhiteTiles(string floor, int num, int len) {
        int n=floor.size();
        vector<int>pre(n,0);
        pre[0]=(floor[0] - '0');
        int cnt=pre[0];
        
        for(int i=1;i<floor.size();i++){
            pre[i]=pre[i-1]+(floor[i] - '0');
            
        }
        memset(dp,-1,sizeof dp);
        
       return pre[pre.size()-1]-getAns(0,floor,pre,num,len);
    }
};