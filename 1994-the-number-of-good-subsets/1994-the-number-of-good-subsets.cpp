class Solution
{
    public:
        int mod = 1e9 + 7;
    int dp[31][(1<<11)+1];//we gave identity to the prime factors not by value but by the index so we optimized the space using this method
    long long getAns(vector<int> &nums, vector<int> &bm, int mask, vector< int > &count, int i)
    {
        if (i >= 31)
        {
            return mask == 0 ? 0 : 1;
        }
        if(dp[i][mask]!=-1){
            return dp[i][mask];
        }
        if (count[i] == 0 || bm[i] == 0) //include exclude approach
        {
            return getAns(nums, bm, mask, count, i + 1);
        }
        long long res = 0;
        if ((mask &bm[i]) == 0) //if the factor does not exists already which is the mask which tells the whole story then we will be including this number into our answer
        {
            res = res % mod + (getAns(nums, bm, (mask | (bm[i])), count, i + 1) % mod *count[i] % mod) % mod;
        }//the answer is formed by multiplying the count which denotes the set formation 
        res = res % mod + getAns(nums, bm, mask, count, i + 1);
        return dp[i][mask]=res % mod;
    }
    int numberOfGoodSubsets(vector<int> &nums)
    {
        memset(dp,-1,sizeof dp);
        vector<int> primes = { 2,
            3,
            5,
            7,
            11,
            13,
            17,
            19,
            23,
            29
        };
        int n = nums.size();
        vector<int> bm(31);
        vector<int> count(31, 0);
        for (int i = 2; i < 31; i++)
        {
            int mask = 0;
            int no = i;
            for (int j = 0; j < primes.size(); j++)
            {
                if (no % primes[j] == 0)
                {
                    int v = no / primes[j];
                    if (v % primes[j] == 0)
                    {
                        mask = 0;
                        break;
                    }
                    mask = mask | (1 << j);
                }
            }
            bm[i] = mask % mod; //precomputing the mask of the factors of a number
        }

        for (auto x: nums)
        {
            count[x]++;
        }

        long long ans = getAns(nums, bm, 0, count, 2);
        ans = ans % mod;
       	// cout<<ans<<" ";
        int p=1;
        for(int i=0;i<count[1];i++){
            p=(p*2)%mod;
            p=p%mod;  //we do not calculate for the ones expicilty but we calc pow of 2 of count of ones and then multiplied it with the answer
        }
        long long save = p*ans;
        return save%mod;
    }
};