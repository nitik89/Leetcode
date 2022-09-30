class Solution {
public:
    unordered_map<int,int>mp;
    int n;
    Solution(int n, vector<int>& blc) {
        this->n=n;
       set<int>st; 
      for(auto x:blc){
          st.insert(x);
      }
        int idx=n-blc.size();
        this->n=idx;
        int temp=idx;
        for(auto x:blc){
            if(x<temp){
                while(st.count(idx)){
                    idx++;
                }
                mp[x]=idx++;
            }
        }
        
    }
    
    int pick() {
        int size=n;
        // cout<<size<<" ";
       int ans=rand()%size;
        if(mp.count(ans)){
            return mp[ans];
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */