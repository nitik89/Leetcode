class Solution
{
    public:
        int largestOverlap(vector<vector < int>> &img1, vector< vector< int>> &img2) {
           vector<pair<int,int>>vec1;
           vector<pair<int,int>>vec2;
            for(int i=0;i<img1.size();i++){
                for(int j=0;j<img1.size();j++){
                    if(img1[i][j]){
                        vec1.push_back({i,j});
                    }
                    if(img2[i][j]){
                        vec2.push_back({i,j});
                    }
                    
                }
            }
            map<pair<int,int>,int>mp;
            int ans=0;
            for(auto &x:vec1){
                for(auto &y:vec2){
                    int dx=x.first-y.first;
                    int dy=x.second-y.second;
                    mp[{dx,dy}]++;
                    ans=max(ans,mp[{dx,dy}]);
                }
            }
            return ans;
        }
};