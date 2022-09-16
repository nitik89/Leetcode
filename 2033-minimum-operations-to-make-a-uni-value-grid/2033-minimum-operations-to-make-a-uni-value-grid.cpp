class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       vector<int>vec;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        // cout<<vec.size()<<" ";
        int med=(ceil((double)vec.size()/2))-1;
        int v=vec[med];
        // cout<<ceil(vec.size()/2)<<" ";
        
        
        int cnt=0;
        for(int i=0;i<vec.size();i++){
            if((vec[i] - v)%x!=0){
                return -1;
            }
            cnt+=abs(vec[i] - v)/x;
        }
        return cnt;
    }
};