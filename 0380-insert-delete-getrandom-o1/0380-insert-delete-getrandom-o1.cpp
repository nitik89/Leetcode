class RandomizedSet {
public:
     unordered_map<int,int>mp;
    vector<int>vec;
    int size=0;
    RandomizedSet() {
       mp.clear();
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            
            return false;
        }
        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){return false;}
        
        
        if(vec.size()>1){
        int idx=mp[val];
        swap(vec[idx],vec[vec.size()-1]);
         mp[vec[idx]]=idx;
        }
        mp.erase(val);
        vec.pop_back();
       
       
        return true;
    }
    
    int getRandom() {
         int random_index = rand() % vec.size();
        return vec[random_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */