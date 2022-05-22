class Solution {
public:

    int largestCombination(vector<int>& can) {
       int n=can.size();
        vector<int>bit(32);
        for(int i=0;i<n;i++){
            int a=0;
            long long b=1;
            while(a<bit.size()){
                int x=b&can[i];
                if(x){
                    bit[a]++;
                }
                a++;
                // cout<<b<<" ";
                b=b<<1;
            }
        }
        int cnt=0;
        for(auto x:bit){
            // cout<<x<<" ";
            cnt=max(cnt,x);
        }
        return cnt;
        // for(auto x:mp){
        //     if()
        // }
        // cout<<set<<" ";
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //      if (can[i] & (unsigned int)(1 << (set - 1))){
        //          cnt++;
        //      }
        // }
        // return cnt;
    }
};