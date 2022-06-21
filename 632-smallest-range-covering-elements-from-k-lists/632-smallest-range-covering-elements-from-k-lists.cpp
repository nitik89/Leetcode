class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int mx=INT_MIN;
     for(int i=0;i<nums.size();i++){
         for(int j=0;j<1;j++){
             // vec.push_back({i,j});
             pq.push({nums[i][j],i,j});
             mx=max(nums[i][j],mx);
         }
     }
        
        int range=INT_MAX;
        int l=-1,r=-1;
        while(true){
           vector<int>vec= pq.top();
            pq.pop();
           if(mx-vec[0]<range){
               range=(mx-vec[0]);
               r=mx;
               l=vec[0];
           }
           int i=vec[1],j=vec[2];
            if(j+1<nums[i].size()){
                pq.push({nums[i][j+1],i,j+1});
                mx=max(nums[i][j+1],mx);
            }
            else{
                break;
            }
        }
       
        return {l,r};
    }
};