class Solution
{
    public:
        void dij(int src, vector<vector<vector< int >>> &grp, vector< long long >&vec)
        {
            priority_queue<vector < long long >, vector< vector< long long >>, greater<vector< long long>>> pq;
            vec[src] = 0;
            pq.push({ 0,
                src });
            while (!pq.empty())
            {
                auto x = pq.top();
                pq.pop();
                if (x[0] > vec[x[1]])
                {
                    continue;
                }
                for (auto &y: grp[x[1]])
                {
                    if (x[0] + y[1] < vec[y[0]])
                    {

                        vec[y[0]] = x[0] + y[1];
                        pq.push({ vec[y[0]],
                            y[0] });
                    }
                }
            }
        }
    long long minimumWeight(int n, vector<vector < int>> &ed, int src1, int src2, int dest)
    {
        vector<vector<vector< int>>> vec1(n);
        vector<vector<vector< int>>> vec2(n);
        for (int i = 0; i < ed.size(); i++)
        {
            vec1[ed[i][0]].push_back({ ed[i][1],
                ed[i][2] });
            vec2[ed[i][1]].push_back({ ed[i][0],
                ed[i][2] });
        }
        vector < long long > sr1(n, 1e18);
        vector < long long > sr2(n, 1e18);
        vector < long long > des(n, 1e18);
        dij(src1, vec1, sr1);
        dij(src2, vec1, sr2);
        dij(dest, vec2, des);
        long long ans = LONG_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, sr1[i] + sr2[i] + des[i]);
        }
        return ans >= 1e18 ? -1 : ans;
    }
};