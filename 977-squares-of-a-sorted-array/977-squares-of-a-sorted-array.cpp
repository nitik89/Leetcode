class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                j=i;
                break;
            }
        }
        vector<int>pos;
        vector<int>neg;
        if(j==-1){
            j=nums.size();
        }
        for(int i=j-1;i>=0;i--){
            neg.push_back(nums[i]*nums[i]);
        }
        for(int i=j;i<nums.size();i++){
            pos.push_back(nums[i]*nums[i]);
        }
        int i=0;
        j=0;
        vector<int>ans;
        while(i<pos.size()&&j<neg.size()){
            if(pos[i]>neg[j]){
                ans.push_back(neg[j]);
                j++;
            }
            else{
                ans.push_back(pos[i]);
                i++;
            }
        }
        while(i<pos.size()){
           ans.push_back(pos[i]);
            i++;
        }
         while(j<neg.size()){
           ans.push_back(neg[j]);
            j++;
        }
        return ans;
      
        
    }
};