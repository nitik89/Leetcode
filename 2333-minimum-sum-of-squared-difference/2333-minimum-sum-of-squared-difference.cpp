class Solution {
public:
    struct cmp {
    bool operator()(int const& p1, int const& p2)
    {
       
        return abs(p1) < abs(p2);
    }
};
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
        
//        priority_queue<int, vector<int>, cmp> pq;
//         for(auto x:nums1){
//             pq.push(x);
//         }
//         // int sum=0;
//         while(!pq.empty()&&total!=0){
//             int x=pq.top();
//             pq.pop();
//             if(x<0){
//                x++; 
//                 pq.push(x);
//                  total--;
//             }
            
//             else if(x>0){
//                 x--;
//                 pq.push(x);
//                  total--;
//             }
           
//         }
//         long long sum=0;
//         while(!pq.empty()){
//             long long x=pq.top();
//             // cout<<x<<" ";
//             sum+=(long long)x*x;
//             pq.pop();
//         }
        // return sum;
        
    }
};