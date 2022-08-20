class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& rt, int vf, int mp, int md) {
        vector<pair<int,int>>vec;
        for(auto x:rt){
            int i=x[0];
            int rat=x[1];
            int vf1=x[2];
            int p=x[3];
            int d=x[4];
            if((vf==0||vf1==vf)&&(p<=mp&&d<=md)){
                vec.push_back({i,rat});
            }
        }
        sort(vec.begin(),vec.end(),[&](pair<int,int>&a,pair<int,int>&b){
            if(a.second==b.second){
               return a.first>b.first;
            }
            return a.second>b.second;
        });
        vector<int>ans;
        for(auto x:vec){
            ans.push_back(x.first);
        }
        return ans;
    }
};