class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        unordered_map<long double,long long>mp;
        long long ans=0;
        for(int i=0;i<rec.size();i++){
            long double x=rec[i][0];
            long double y=rec[i][1];
            ans+=mp[x/y];
            mp[x/y]++;
        }
        return ans;
    }
};