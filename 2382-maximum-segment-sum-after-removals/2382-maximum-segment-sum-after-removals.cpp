class Solution {
public:
    long long mx;
    vector<int>par;
    vector<long long>sum;
    int find(int i){
        if(par[i]==i){
            return i;
        }
        int x=find(par[i]);
        return x;
    }
    void _union(int i,int j){
        int x=find(i);
        int y=find(j);
        if(par[x]!=par[y]){
            par[x]=y;
            sum[y]+=sum[x];
            mx=max(mx,sum[y]);
        }
        
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& q) {
        // reverse(q.begin(),q.end());
        int n=q.size();
        vector<int>vis(n,0);
        vector<long long>ans(n);
        par.resize(n);
        sum.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sum[i]=nums[i];
        }
        //we will make the max sum as the answer
        mx=0;
        for(int i=n-1;i>=0;i--){
            int idx=q[i];
            vis[idx]=1;
            ans[i]=mx;
            // cout<<mx<<" "<<idx<<"\n";
            mx=max(mx,(long long)nums[idx]);
            
            if(idx-1>=0&&vis[idx-1]){
                _union(idx-1,idx);
            }
            if(idx+1<n&&vis[idx+1]){
                _union(idx,idx+1);
            }
        }
        return ans;
    }
};





