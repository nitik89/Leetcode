class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans=INT_MIN;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<m;i++){
            vector<int>sum(n,0);
            for(int j=i;j<m;j++){
                
                for(int k=0;k<n;k++){
                    sum[k]+=matrix[k][j];
                }
                
                set<int>sums;
                sums.insert(0);
                int csum=0;
                for(auto x:sum){
                    csum+=x;
                    auto it=sums.lower_bound(csum-k);
                    if(it!=sums.end()){
                        ans=max(ans,csum-*it);
                    }
                    sums.insert(csum);
                }
            }
        }
        return ans;
    }
};