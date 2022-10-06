class Solution {
public:
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>vec(n,vector<int>(m));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]==0){
                    matrix[i][j]=0;
                    sum=0;
                }
                else{
                sum+=matrix[i][j];
                }
                vec[i][j]=sum;
            }
            // vec.push_back(sum);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            sort(vec[i].begin(),vec[i].end());
            for(int j=0;j<m;j++){
                // cout<<vec[i][j]<<" ";
                int calc=vec[i][j]*(m-j);
                ans=max(ans,calc);
            }
            // cout<<"\n";
        }
        // return largestRectangleArea(vec);
        return ans;
        
    }
};






