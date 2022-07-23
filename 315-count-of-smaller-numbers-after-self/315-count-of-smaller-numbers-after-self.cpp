

class Solution {
public:
   
  
   void mergeSort(vector<pair<int,int>>&nums,vector<int>&res,int lo,int hi){
        if(lo>=hi){
            return;
        }
      
        
        int mid=lo+(hi-lo)/2;;
       mergeSort(nums,res,lo,mid);
        mergeSort(nums,res,mid+1,hi);
         
       int i=lo,j=mid+1;
        int count=0;
        vector<pair<int,int>>ans;
        while(i<=mid&&j<=hi){
            if(nums[i].first>nums[j].first){
              count++;
                ans.push_back(nums[j]);
                j++;
            }
            else{
                  res[nums[i].second]+=count;
                ans.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid){
            res[nums[i].second]+=count;
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=hi){
            ans.push_back(nums[j]);
                j++;
        }
        i=lo;
        for(auto x:ans){
            nums[i++]=x;
        }
       
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<int>temp;
        
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        // temp.push_back(nums[n-1]);
      mergeSort(vec,ans,0,n-1);
        // for(auto x:vec){
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        return ans;
    }
};