class Solution {
public:
    int dp[1001][1001];
    int mod=1e9+7;
    vector<vector<int>>vec;
    int getAns(vector<string>&words,string& target,int i,int j){
        
        if(i == target.size())return 1;
        if(j== words[0].size() || words[0].size() - j < target.size() - i)return 0;
            
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long ans=0;
        int ch=(target[i] - 'a');
        // cout<<j<<" "<<vec.size()<<"\n";
        ans=ans%mod+(long long)vec[j][ch]*(long long)getAns(words,target,i+1,j+1);
        ans=ans%mod+getAns(words,target,i,j+1);
        return dp[i][j]=ans%mod;
    }
    int numWays(vector<string>& words, string target) {
        vec.resize(words[0].size(),(vector<int>(26,0)));
        memset(dp,-1,sizeof dp);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[0].size();j++){
                int idx=(words[i][j] - 'a');
                vec[j][idx]++;
            }
        }
        return getAns(words,target,0,0);
    }
};