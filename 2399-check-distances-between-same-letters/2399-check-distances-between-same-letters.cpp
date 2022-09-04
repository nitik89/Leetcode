class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i] - 'a'].push_back(i);
        }
        for(auto x:mp){
            vector<int>vec=x.second;
            int dis=distance[x.first];
            for(int i=1;i<vec.size();i++){
                if(vec[i]-vec[i-1]-1!=dis){
                    return false;
                }
            }
        }
        return true;
    }

};