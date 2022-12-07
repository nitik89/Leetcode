class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& f, int s, int k) {
        int mx=2e5+5;
        vector<int>pre(mx,0);
        vector<int>suff(mx,0);
        int curr=0;
        for(int i=0;i<f.size();i++){
            if(f[i][0]==s){
                curr=f[i][1];
            }
            pre[f[i][0]]=f[i][1];
            suff[f[i][0]]=f[i][1];
        }
        for(int i=1;i<mx;i++){
            pre[i]+=pre[i-1];
        }
        for(int i=mx-2;i>=0;i--){
            suff[i]+=suff[i+1];
        }
        
        int i=0,ans=INT_MIN;
        while(i<=k){
            int r=min(mx-1,s+i);
            r=max(0,r);
            int l=max(0,s-k+2*i);
            l=min(mx-1,l);
            
            ans=max(ans,pre[r]-pre[s]+suff[l]-suff[s]);
            i++;
        }
        i=0;
        while(i<=k){
            int l=max(0,s-i);
            l=min(l,mx-1);
            int r=min(mx-1,s+k-2*i);
             r=max(0,r);
            ans=max(ans,pre[r]-pre[s]+suff[l]-suff[s]);
            i++;
        }
        return ans+curr;
        
        
    }
};