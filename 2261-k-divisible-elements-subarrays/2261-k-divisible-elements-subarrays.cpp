class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
       set<string>mp;
        int ans=0;
       for(int i=0;i<nums.size();i++){
           int count=0;
           string str="";
           for(int j=i;j<nums.size();j++){
              str+=(to_string(nums[j])+",");
               if(nums[j]%p==0){
                   count++;
                   if(count<=k){
                       
                       if(mp.find(str)==mp.end()){
                           ans++;
                           mp.insert(str);
                       }
                   }
               }
               else if(count<=k){
                   if(mp.find(str)==mp.end()){
                           ans++;
                           mp.insert(str);
                       }
               }
            
           }
       }
       
        return ans;
    }
};