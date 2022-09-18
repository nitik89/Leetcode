class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        const uint64_t MOD=184467440737091;
     unordered_map<uint64_t,int>mp;
        for(int i=0;i<words.size();i++){
            uint64_t s=0;
            for(int j=0;j<words[i].size();j++){
                s=(131313*s+(words[i][j] - 96))%MOD;
                mp[s]++;
            }
        }
        vector<int>ans(words.size(),0);
        for(int i=0;i<words.size();i++){
            uint64_t s=0;
            int cnt=0;
            for(int j=0;j<words[i].size();j++){
                s = (131313 * s + (words[i][j] - 96)) % MOD;
                cnt+=mp[s];
            }
            ans[i]+=cnt;
        }
        return ans;
        
    }
};