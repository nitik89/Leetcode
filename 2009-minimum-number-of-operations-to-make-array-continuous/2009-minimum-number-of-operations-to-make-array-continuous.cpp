class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        set<int>st;
        int n=nums.size();
        for(auto x:nums){
            st.insert(x);
        }
        vector<int>vec;
        for(auto x:st){
            vec.push_back(x);
        }
        
        sort(vec.begin(),vec.end());
        int ans=INT_MAX;
        for(int i=0;i<vec.size();i++){
            int curr=vec[i];
            int end=vec[i]+n-1;
            int idx=upper_bound(vec.begin(),vec.end(),end)-vec.begin();//to check the elemets in the current set 
            int ele=idx-i;
            // cout<<idx<<" "<<end<<"\n";
            ans=min(ans,n-ele);
        }
        
        // cout<<cnt<<" ";
        return ans==INT_MAX?0:ans;
    }
};