class Solution {
public:
    int dp[(1<<15)];
    int getAns(string &tr,vector<vector<int>>&vec,int all,int mask){
        if(mask==all){
            return 0;
        }
        if(dp[mask]!=-1){
            return dp[mask];
        }
        
        int ans=1e6;
        for(auto x:vec){
            vector<int>v=x;
            
            int nm=mask;
            for(int i=0;i<tr.size();i++){
                if((nm&(1<<i))==0 && v[tr[i] - 'a']){
                    nm=nm|(1<<i);
                    v[tr[i] - 'a']--;
                }
            }
            if(nm!=mask){
                
                ans=min(ans,1+getAns(tr,vec,all,nm));
            }
            
        }
        return dp[mask]=ans;
    }
    int minStickers(vector<string>& st, string tr) {
        memset(dp,-1,sizeof dp);
        int n=st.size();
        int m=tr.size();
        vector<vector<int>>vec(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            string str=st[i];
            for(auto x:str){
                vec[i][x - 'a']++;
            }
        }
        int allmask=(1<<m)-1;
        int s=getAns(tr,vec,allmask,0);
        return s==1e6?-1:s;
    }
};