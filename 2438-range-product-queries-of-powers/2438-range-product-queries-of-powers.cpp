class Solution
{
    public:
        long long highestPowerof2(int n)
        {
            for (int i = 0; i < 31; i++)
            {
                long long x = pow(2, i);
                if (x >= n)
                {
                    return x;
                }
            }
            return 1;
        }
    vector<int> productQueries(int n, vector<vector < int>> &q)
    {

        vector < long long > vec;
        int mod = 1e9 + 7;
        long long s = highestPowerof2(n);
        long long sum = 0;
       	// cout<<s<<" ";
        while (sum <= n && s >= 1)
        {
           	// cout<<sum<<" ";
            if (sum + s <= n)
            {
                vec.push_back(s);
                sum += s;
            }
            s = s / 2;
        }
       	// cout<<sum<<" ";
        reverse(vec.begin(), vec.end());
        vector<int> ans;
        for (auto x: q)
        {
            int s = x[0];
            int e = x[1];
            long long a = 1;
            for (int i = s; i <= e; i++)
            {
                a *= vec[i] % mod;
                a = a % mod;
            }
            ans.push_back(a);
        }
        return ans;
    }
};