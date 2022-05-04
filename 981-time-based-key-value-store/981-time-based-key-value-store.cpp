class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        // vector<pair<string,int>>vec=mp[key];
        int s=0,e=mp[key].size()-1;
        string ans="";
        while(s<=e){
            int mid=(s+e)>>1;
            if(mp[key][mid].second==timestamp){
                return mp[key][mid].first;
            }
            if(mp[key][mid].second<timestamp){
                ans=mp[key][mid].first;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */