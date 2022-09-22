class Solution {
public:
    int getAns(vector<int>&vec1,vector<int>&vec2){
        unordered_map<long long,int>mp;
        int count=0;
        for(int i=0;i<vec1.size();i++){
            for(int j=i+1;j<vec1.size();j++){
                long long pr=(long long)vec1[i]*(long long)vec1[j];
                mp[pr]++;
            }
        }
        for(int i=0;i<vec2.size();i++){
            long long sq=(long long)vec2[i]*(long long)vec2[i];
            count+=mp[sq];
        }
        return count;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
       return getAns(nums1,nums2)+getAns(nums2,nums1);
    }
};