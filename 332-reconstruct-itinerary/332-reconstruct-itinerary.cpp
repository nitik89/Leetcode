class Solution {
public:
    unordered_map<string,multiset<string>>mp;
    vector<string>ans;
    unordered_set<string>check;
    
    void getAns(string str){
        
        while(mp[str].size()>0){
        string dst = *mp[str].begin();
        mp[str].erase(mp[str].begin());
        getAns(dst);
        }
        ans.push_back(str);
    }
    vector<string> findItinerary(vector<vector<string>>& tick) {
        for(int i=0;i<tick.size();i++){
            mp[tick[i][0]].insert(tick[i][1]);
        }
        
        getAns("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};