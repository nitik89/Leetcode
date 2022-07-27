class Solution {
public:
    bool canChoose(vector<vector<int>>& grp, vector<int>& nums) {
        int r=0,c=0;
        int i=0;
        bool fl=true;
        while(i<nums.size()){
            
            if(nums[i]==grp[r][c]){
             // cout<<nums[i]<<" ";
                int j=i;
                int m=r;
                while(i<nums.size()&&c<grp[m].size()&&nums[i]==grp[m][c]){
                    c++;
                    i++;
                }
                // cout<<r<<" "<<c<<" "<<i<<"\n";
                
                if(c==grp[m].size()){
                    r++;
                    c=0;
                    i--;
                    
                }
                else{
                    // cout<<r<<" "<<c<<"\n";
                    // cout<<i<<" "<<r<<" "<<c<<"\n";
                    c=0;
                    i=j;
                    r=m;
                }
                
                
            }
            if(r==grp.size()){
                return true;
            }
            
           
            i++;
        }
         // cout<<r<<" ";
        return r==grp.size();
    }
};