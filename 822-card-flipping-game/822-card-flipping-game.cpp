class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int>st;
for(int i=0;i<fronts.size();i++){
    if(fronts[i]==backs[i]){
            st.insert(fronts[i]);
    }
        
        }
        int ans=INT_MAX;
        for(int i=0;i<fronts.size();i++){
            if(st.find(backs[i])==st.end()){
                ans=min(ans,backs[i]);
            }
            if(st.find(fronts[i])==st.end()){
                ans=min(ans,fronts[i]);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};