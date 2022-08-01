class StockPrice {
public:
    struct comp {
    bool operator() (const pair <int, int> &lhs, const pair <int , int> &rhs) const {
       return lhs.first>rhs.first;
    }
};
    set<pair<int,int>,greater<pair<int,int>>>mx;
    unordered_map<int,int>mp;
    int time;
    StockPrice() {
        time=0;
    }
    
    void update(int st, int price) {
      time=max(st,time);
        //time vs price
        
        if(mp[st]){
            int prc=mp[st];
            // cout<<prc<<" "<<st<<"\n";
            // cout<<mx.count({prc,st})<<" ";
         
            mx.erase({prc,st});
        }
        
        mp[st]=price;
        mx.insert({price,st});
        // cout<<price<<" "<<st<<" "<<mx.rend()->first<<" "<<mx.rbegin()->first<<"\n";
      
    }
    
    int current() {
        // cout<<time<<" ";
        return mp[time];
    }
    
    int maximum() {
        return mx.begin()->first;
    }
    
    int minimum() {
        
        return mx.rbegin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */