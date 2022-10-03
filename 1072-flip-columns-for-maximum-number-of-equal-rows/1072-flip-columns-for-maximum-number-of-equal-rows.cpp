class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
      unordered_map<string,int>mp;
      
        int mx=0;
        for(int i=0;i<mat.size();i++){
            string temp="";
            string ulta="";
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]){
                    temp.push_back('1');
                    ulta.push_back('0');
                }
                else{
                    temp.push_back('0');
                    ulta.push_back('1');
                }
            }
            mp[temp]++;
            mp[ulta]++;
           
        }
        for(auto x:mp){
            mx=max(x.second,mx);
        }
        return mx;
    }
};