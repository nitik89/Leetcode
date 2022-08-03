class MyCalendar {
public:
    vector<pair<int,int>>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto x:mp){
            int s=x.first;
            int e=x.second;
            if((start>=s&&start<e)||(start<s&&end>s&&(end>=e||end<=e))){
                return false;
            }
        }
        mp.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */