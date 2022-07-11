class Solution {
public:
    int ans=0;
    vector<int>dp;
    int getAns(int curr,vector<vector<int>>&grp,string& s){
        
        
        //i need 2 best ans len
        int mx1=0,mx2=0;
        if(dp[curr]!=-1){
            return dp[curr];
        }
        for(auto x:grp[curr]){
            int val=getAns(x,grp,s);
            if(s[curr]!=s[x]){
                if(val>mx1){
                    mx2=mx1;
                    mx1=val;
                    
                }
                else if(val>mx2){
                    mx2=val;
                }
            }
        }
        ans=max(ans,mx1+mx2+1);
        return max(mx1,mx2)+1;
        
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>>grp(n);
        dp.resize(n,-1);
        for(int i=1;i<parent.size();i++){
            grp[parent[i]].push_back(i);
        }
        getAns(0,grp,s);
        return ans;
    }
};