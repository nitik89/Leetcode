class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while(k){
            int x=pq.top();
            pq.pop();
            pq.push(x+1);
            k--;
        }
        long long res=1,mod=1e9+7;
        while(!pq.empty()){
            res=((res%mod)*(pq.top()%mod))%mod;
            pq.pop();
        }
        return res;
    }
};