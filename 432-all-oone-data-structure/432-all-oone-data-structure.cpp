class AllOne {
public:
    set<pair<int,string>>st;
    unordered_map<string,int>mp;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(mp.count(key)){
            int x=mp[key];
            st.erase({x,key});
        }
        mp[key]++;
        int v=mp[key];
        st.insert({v,key});
    }
    
    void dec(string key) {
         if(mp.count(key)){
            int x=mp[key];
            st.erase({x,key});
        }
        mp[key]--;
        if(mp[key]==0){
            mp.erase(key);
        }
        else{
            st.insert({mp[key],key});
        }
    }
    
    string getMaxKey() {
        if(st.size()>0){
           auto x=st.rbegin();
            return x->second;
        }
        return "";
    }
    
    string getMinKey() {
         if(st.size()>0){
           auto x=st.begin();
            return x->second;
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */