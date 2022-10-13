class Solution {
public:
    
    void fun(vector<int>&vec,int i,int sum,vector<int>&res){
        if(i==vec.size()){
            res.push_back(sum);
            return;
        }
        fun(vec,i+1,sum,res);
        fun(vec,i+1,sum+vec[i],res);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
       vector<int>vec1;
       vector<int>vec2;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            vec1.push_back(nums[i]);
        }
        for(int i=n/2;i<n;i++){
            vec2.push_back(nums[i]);
        }
        vector<int>res1;
        vector<int>res2;
        
        fun(vec1,0,0,res1);
        fun(vec2,0,0,res2);
       
        sort(res2.begin(),res2.end());
        
        int res=INT_MAX;
        for(auto x:res1){
            auto it=lower_bound(res2.begin(),res2.end(),goal-x);
            res=min(res,abs(goal-x));
            if(it!=res2.end()){
                int val=x+*it;
                res=min(res,abs(goal-val));
            }
            if(it!=res2.begin()){
                it--;
                int val=x+*it;
                res=min(res,abs(goal-val));
                
            }
        }
        return res;
    }
};







