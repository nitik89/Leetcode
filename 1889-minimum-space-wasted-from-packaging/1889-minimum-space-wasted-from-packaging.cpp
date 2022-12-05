class Solution
{
    public:
        int minWastedSpace(vector<int> &p, vector<vector< int>> &boxes)
        {
            sort(p.begin(), p.end());
            int n = p.size();
            long long ans = 1e18;
            vector<long long> pre(n, 0);
            int mod=1e9+7;
            sort(p.begin(), p.end());
            pre[0] = p[0];
            for (int i = 1; i < n; i++)
            {
                pre[i] = pre[i - 1] + p[i];
            }
            // for(auto x:pre){
            //     cout<<x<<" ";
            // }
            int m = boxes.size();
            for (int i = 0; i < m; i++)
            {
                sort(boxes[i].begin(), boxes[i].end());
                long long sum = 0, prev = 0, res = 0;
                for (int j = 0; j < boxes[i].size(); j++)
                {
                    auto x = upper_bound(p.begin(), p.end(), boxes[i][j]);
                    if (x != p.begin())
                    {
                        x--;
                        long long idx = x - p.begin();
                        res+= ((long long)(idx - prev + 1) * boxes[i][j]) - (pre[idx] - sum);
                        // cout<<idx<<"\n";
                         sum = pre[idx];
                        prev = idx + 1;
                       
                    }
                }
                if (prev == n)
                {
                    ans = min(ans, res);
                }
            }
        
            return ans==1e18?-1:ans%mod;
        }
};