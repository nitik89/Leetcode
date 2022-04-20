class RandomizedCollection {
public:
    unordered_map<int,set<int>>mp;
    vector<int>vec;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag=false;
        // cout<<mp[val].size()<<" "<<val<<"\n";
        if(mp.find(val)==mp.end()||mp[val].size()==0){
            // cout<<val<<" ";
            flag=true;
        }
        // cout<<val<<" ";
        vec.push_back(val);
        
        mp[val].insert(vec.size()-1);
        return flag;
    
    }
    bool remove(int val) {
        //for removal remove at 2 places that is mp and vec
        bool flag=true;
        if(mp[val].size()==0){
            // cout<<val<<" ";
            return false;
        }
        if(mp.find(val)==mp.end()){
            return false;
        }
        // cout<<val<<" "<<vec.size()<<"\n";
        int idx=*mp[val].rbegin();
        
        mp[val].erase(idx);
       
        if(vec.size()>1){
        // cout<<vec[vec.size()-1]<<" "<<idx<<"\n";
        int v=vec[idx];
        vec[idx]=vec[vec.size()-1];
        
        mp[vec[idx]].erase(vec.size()-1);
            if(v!=vec[idx]){
        mp[vec[idx]].insert(idx);
            }
        }
        
        vec.pop_back();
        // cout<<val<<" "<<vec.size()<<"\n";
        return flag;
    }
    
    int getRandom() {
        int k=vec.size();
        if(k==0){
            return -1;
        }
        int idx=rand()%k;
        return vec[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */