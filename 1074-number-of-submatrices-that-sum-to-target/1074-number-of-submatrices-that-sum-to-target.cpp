class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        //hashing and prefix sum 
        //calculate prefix sum -> in O(N4) -> calculate sum of all submatrices
        //if sum==target count++;
        int row=matrix.size(),col=matrix[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=1;j<col;j++) matrix[i][j]+=matrix[i][j-1];
        }
        for(int j=0;j<col;j++)
        {
            for(int i=1;i<row;i++) matrix[i][j]+=matrix[i-1][j];
        }
        
        int count=0;
        
        for(int sti=0;sti<row;sti++)
        {
            for(int stj=0;stj<col;stj++)
            {
                for(int endi=sti;endi<row;endi++)
                {
                    for(int endj=stj;endj<col;endj++)
                    {
                        int sum=matrix[endi][endj];
                        if(stj>0) sum-=matrix[endi][stj-1];
                        if(sti>0) sum-=matrix[sti-1][endj];
                        if(sti>0 && stj>0) sum+=matrix[sti-1][stj-1];
                        
                        if(sum==target) count++;
                    }
                }
            }
        }
        
        return count;
        
    }
};