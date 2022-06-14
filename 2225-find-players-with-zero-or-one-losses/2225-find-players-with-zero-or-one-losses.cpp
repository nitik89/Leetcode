class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>>mp;
        for(int i=0;i<matches.size();i++)
        {
            if(mp.find(matches[i][0])==mp.end())
                mp.insert({matches[i][0], {1, 0}});
            else
                mp[matches[i][0]].first++;
            if(mp.find(matches[i][1])==mp.end())
                mp.insert({matches[i][1], {0, 1}});
            else
                mp[matches[i][1]].second++;
        }
        vector<int>v1;
        vector<int>v2;
        for (auto const& x : mp)
        {
            if(x.second.second==1)
                v1.push_back(x.first);
            if(x.second.second==0)
                v2.push_back(x.first);
        }
        vector<vector<int>>v;
        v.push_back(v2);
        v.push_back(v1);
        return v;
        
    }
};