int dp[101][101][27][101];
class Solution
{
    public:

        int getAns(string &s, int k, int i, int prev, int len)
        {
            if (k < 0) return INT_MAX / 2;
            if (i >= s.size()) return 0;
            int sv=dp[k][i][prev][len];
            if(sv!=-1){
                return sv;
            }
            int ans = 0;
            if ((s[i] - 'a') == prev)
            {
                // cout<<i<<" "<<len<<"\n";
                int c = (len == 1 || len == 9 || len == 99);
                ans = c + getAns(s, k, i + 1, prev, len + 1);
            }
            else
            {
                // cout<<i<<" ";
                ans = min(1 + getAns(s, k, i + 1, (s[i] - 'a'), 1),
                    getAns(s, k - 1, i + 1, prev, len));
            }
            return dp[k][i][prev][len]=ans;
        }
    int getLengthOfOptimalCompression(string s, int k)
    {
        memset(dp,-1,sizeof dp);
        // cout<<(s[i] - 'a')<<" ";
        return getAns(s, k, 0, 26, 0);
        // return 1;
    }
};