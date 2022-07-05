class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        st.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
         auto it = st.begin();
    
    vector<int> vec ={*it,*it};
    // int end=*it,st=*it;
    it++;
     vector<vector<int>>ans;
    while(it != st.end()){
           if(*it==vec[1]+1){
               vec[1]=*it;
           }
        else{
            ans.push_back(vec);
            vec={*it,*it};
            
        }
        it++;
        }
        ans.push_back(vec);
       
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */