class Solution {
public:
    bool getAns(vector<vector<int>>&st,int mask){
        int n=st.size();
        for(int i=0;i<n;i++){
            if((mask&(1<<i))){
            for(int j=0;j<n;j++){
                if(i==j||st[i][j]==2) continue;
                if((mask&(1<<j)) && st[i][j]==0) return false;
                if(!(mask&(1<<j)) && st[i][j]==1) return false;
            }
            }
        }
        // cout<<k<<" ";
        return true;
    }
    int maximumGood(vector<vector<int>>&st) {
        int ans=INT_MIN;
        for(int i=0;i<(1<<st.size());i++){
            
            // cout<<mask<<" ";
            if(getAns(st,i)){
                ans=max(ans,__builtin_popcount(i));
            }
        }
        return ans;
    }
};