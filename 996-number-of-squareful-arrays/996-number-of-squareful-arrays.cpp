class Solution {
public:
    bool isSq(long double x)
{
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        return (sr * sr == x);
    }
    
    return false;
}
 
    int res;
    void getAns(vector<int>&nums,unordered_set<int>&vec,int prev){
        // cout<<vec.size()<<" "<<prev<<"\n";
        if(vec.size()==nums.size()){
            res++;
            return;
        }
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
          if(mp.count(nums[i])>0){
              continue;
          }
            if(prev==-1&&vec.count(i)==0){
                vec.insert(i);
                mp[nums[i]]++;
                getAns(nums,vec,i);
                vec.erase(i);
                   cnt++;
            }
            else if(prev!=-1&&i!=prev&&isSq(nums[prev]+nums[i])&&vec.count(i)==0){
                vec.insert(i);
                mp[nums[i]]++;
                getAns(nums,vec,i);
                vec.erase(i);
                  cnt++;
            }
          
        }
        
    }
    int numSquarefulPerms(vector<int>& nums) {
        res=0;
        
        unordered_set<int>vec;
        // sort(nums.begin(),nums.end());
        getAns(nums,vec,-1);
        return res;
    }
};