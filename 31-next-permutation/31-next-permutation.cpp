class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        int i=n-1;
        int j=n;
        while(i>=0&&nums[i]>=nums[i+1]){
            i--;  //find the break point ie 1 2 3 5 4 find where 3 lies
            
        }
        //5 4 3 2 1 to avoid this base case
        if(i>=0){
            while(nums[j]<=nums[i]){ //find an index smaller than the i th index
                j--;
            }
            swap(nums[i],nums[j]);
        }
        // cout<<i<<" "<<j<<"\n";
        //now swap them to generate 
        //generate a smaller version reverse the in between i+1 and till the last index
        reverse(nums,i+1,n);
        
    }
    void reverse(vector<int>&nums,int i,int j){
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};