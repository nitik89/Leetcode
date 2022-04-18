class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
     for(int i=0;i<numRows;i++){
         vector<int>vec(i+1);
         vec[0]=1;
         vec[vec.size()-1]=1;
         // cout<<vec.size()<<"\n";
         for(int j=1;j<vec.size()-1;j++){
             
             vec[j]=ans[i-1][j]+ans[i-1][j-1];
         }
         // cout<<"\n";
         ans.push_back(vec);
     }
         return ans;   
    }

};