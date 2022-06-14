class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int,int>mp;
        for(auto x:mat){
            mp[x[1]]++;
        }
        vector<vector<int>>vec(2);
        for(auto x:mat){
            if(mp.count(x[0])==0){
                vec[0].push_back(x[0]);
                mp[x[0]]+=2;
            }
        }
    for(auto x:mp){
        if(x.second==1){
            vec[1].push_back(x.first);
        }
    }
        sort(vec[0].begin(),vec[0].end());
        return vec;
        
    }
};