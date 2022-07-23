class NumberContainers {
public:
    
    unordered_map<int,multiset<int>>mp;
    unordered_map<int,int>mp1;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       if(mp1.count(index)==0){
           mp1[index]=number;
           mp[number].insert(index);
       }
        else{
            int n=mp1[index];
            mp[n].erase(index);
            if(mp[n].size()==0){
                mp.erase(n);
            }
            mp1[index]=number;
            mp[number].insert(index);
        }
    }
    
    int find(int number) {
       if(mp.count(number)==0){
           return -1;
       }
        return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */