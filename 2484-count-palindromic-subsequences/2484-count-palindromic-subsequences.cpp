class Solution
{
    public:
        int mod = 1e9 + 7;
    int dp[10001][6][11][11];
    int getAns(string &s, int idx, int i, int first, int second)
    {
        
        if (idx >= s.size())
        {
            // cout<<i<<" "<<first<<" "<<second<<"\n";
            return i==5;
        }
        if(dp[idx][i][first][second]!=-1){
            return dp[idx][i][first][second];
        }
        int cnt = 0;
        cnt = cnt % mod + getAns(s, idx + 1, i, first,second);
        if (i == 0)
        {
            cnt = cnt % mod + getAns(s, idx + 1, i + 1, s[idx] - '0', second);
        }
        else if (i == 1)
        {
            cnt = cnt % mod + getAns(s, idx + 1, i + 1, first, s[idx] - '0');
        }
        else if (i == 2)
        {
            cnt = cnt % mod + getAns(s, idx + 1, i + 1,first, second);
        }
        else if (i == 3)
        {
            if (s[idx] - '0' == second)
            {
                cnt = cnt % mod + getAns(s, idx + 1, i + 1, first, second);
            }
        }
        else if (i == 4)
        {
            if (s[idx] - '0' == first)
            {
                cnt = cnt % mod + getAns(s, idx + 1, i + 1, first, second);
            }
        }
        return  dp[idx][i][first][second]=cnt % mod;
    }
    int countPalindromes(string s)
    {
        memset(dp,-1,sizeof dp);
        return getAns(s, 0, 0, 10, 10);
    }
};