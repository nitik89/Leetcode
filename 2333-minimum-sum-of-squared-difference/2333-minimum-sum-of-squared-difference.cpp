class Solution {
public:
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
     int total=k1+k2;
     for(int i=0;i<n;i++){
         nums1[i]=nums1[i]-nums2[i];
     }
        
        unordered_map<long long,long long>mp;
        int mx=INT_MIN;
        for(auto x:nums1){
            mp[abs(x)]++;
            mx=max(mx,abs(x));
        }
        while(mx>0&&total>0){
            
            int cnt=mp[mx];
            
            if(total>=cnt){
                mp.erase(mx);
                mx--;
                mp[mx]+=cnt;
                total-=cnt;
            }
            else{
                mp[mx-1]+=total;
                mp[mx]-=total;
                total=0;
            }
        }
        long long ans=0;
        for(auto x:mp){
            ans+=(x.first)*(x.first)*(x.second);
        }
        return ans;
        

        
    }
};