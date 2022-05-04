class TimeMap {
    unordered_map<string, vector<pair<string, int>>> umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {        
        umap[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        int start = 0, end = umap[key].size() - 1;
        string ans = "";
        while(start<=end){
            int mid = start + (end - start) / 2;
            if(umap[key][mid].second == timestamp) return umap[key][mid].first;
            else if(umap[key][mid].second < timestamp) {
                ans = umap[key][mid].first;
                start = mid + 1;  
            } 
            else end = mid-1;
        }
        return ans;
    }
};