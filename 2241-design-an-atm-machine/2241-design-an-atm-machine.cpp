class ATM {
public:
    unordered_map<int,long long>mp;
    vector<int>vec{20,50,100,200,500};
    // priority_queue<pair<int,int>>pq;
    ATM() {
       
    }
    
    void deposit(vector<int> notes) {
       for(int i=0;i<notes.size();i++){
           mp[vec[i]]+=notes[i];
       }
    
        
    }
    
    vector<int> withdraw(int amount) {
        priority_queue<pair<int,int>>temp;
        vector<int>ans(5,0);
        for(int i=vec.size()-1;i>=0;i--){
            long long mxnotes=min((long long)amount/vec[i],mp[vec[i]]);
            if(mp[vec[i]]>=mxnotes&&mp[vec[i]]>0){
                mp[vec[i]]-=mxnotes;
                amount-=vec[i]*mxnotes;
                ans[i]+=mxnotes;
               
            }
           
             
        }
        // cout<<amount<<" ";
        if(amount>0){
            for(int i=vec.size()-1;i>=0;i--){
                mp[vec[i]]+=ans[i];
            }
            return {-1};
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */