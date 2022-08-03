class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        
        vector<int>curr(items.size());
        vector<int>price(items.size());
        int mx=INT_MIN;
        for(int i=0;i<items.size();i++){
            curr[i]=max(mx,items[i][1]);
            mx=max(curr[i],mx);
            price[i]=items[i][0];
        }
        vector<int>ans;
        for(auto x:queries){
            int idx=upper_bound(price.begin(),price.end(),x)-price.begin();
             if(idx-1>=0){
         ans.push_back(curr[idx-1]);
             }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};