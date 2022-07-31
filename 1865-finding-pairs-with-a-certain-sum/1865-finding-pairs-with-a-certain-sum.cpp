class FindSumPairs {
public:
    unordered_map<int,int>mp;
    // vector<int>vec1;
    unordered_map<int,int>idx;
    unordered_map<int,int>mp1;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // vec1=nums1;
        // vec2=num2;
        int i=0;
        for(auto x:nums2){
            idx[i++]=x;
            mp[x]++;
            
        }
        for(auto x:nums1){
            mp1[x]++;
        }
    }
    
    
    void add(int index, int val) {
        int v=idx[index];
        mp[v]--;
        int sm=v+val;
        mp[sm]++;
        idx[index]=sm;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto x:mp1){
            cnt+=x.second*mp[tot-x.first];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */