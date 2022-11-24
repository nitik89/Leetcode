class Solution {
public:
    unordered_set<int>st;
    int x,y,sz;
    Solution(int m, int n) {
        x=m,y=n,sz=m*n;
    }
    
    vector<int> flip() {
        if(st.size()==sz) return {};
        
        int a=rand()%sz;
        while(st.count(a)!=0){
            a++;
            a=a%sz;
        }
        st.insert(a);
        return {a/y,a%y};
    }
    
    void reset() {
        st={};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */