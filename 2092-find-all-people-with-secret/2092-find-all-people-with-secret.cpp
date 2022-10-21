class Solution
{
    public:
        vector<int> par;
    vector<int> rank;
    int find(int x)
    {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    void _union(int x, int y)
    {
        par[find(x)] = find(y);
    }
    vector<int> findAllPeople(int n, vector<vector < int>> &met, int f)
    {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 1;
        }
        _union(0, f);

        map<int, vector<pair<int, int>>> mp;

        for (auto x: met)
        {
            mp[x[2]].push_back({ x[0],
                x[1] });
        }
        vector<int> ans;

        for (auto i: mp)
        {
            set<int> st;
            for (auto &[a, b]: i.second)
            {
                int x1 = find(a);
                int x2 = find(b);

                _union(a, b);
                st.insert(a);
                st.insert(b);
            }
            for (auto x: st)
            {
                if (find(x) != find(0))
                {

                    par[x] = x;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (find(i) == find(0))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};