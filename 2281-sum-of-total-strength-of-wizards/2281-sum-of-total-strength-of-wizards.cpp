class Solution {
public:
    int totalStrength(vector<int>& st) {
        int N=st.size();
        int MOD=1e9+7;
     vector<int> stack;
        vector<int> left(N,-1);
        vector<long long> prefix(N + 1, 0L);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = (prefix[i] + st[i]) % MOD;
    }
     
    vector<long long> prefix_sum(N + 2, 0L);
    for (int i = 0; i <= N; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + prefix[i]) % MOD;
    }
        
    for (int i = 0; i < N; ++i) {
        while (!stack.empty() && st[stack.back()] >= st[i]) {
            stack.pop_back();
        }
        left[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }
    
    // first index on the right <= current st
    vector<int> right(N, N);
    stack.clear();
    for (int i = N - 1; i >= 0; --i) {
        while (!stack.empty() && st[stack.back()] > st[i]) {
            stack.pop_back();
        }
        right[i] = stack.empty() ? N : stack.back();
        stack.push_back(i);
    }
    
        int sum=0;
        for(int i=0;i<N;i++){
            sum=sum+((((i-left[i])*(prefix_sum[right[i]+1]-prefix_sum[i+1]))%MOD+2*MOD-((prefix_sum[i+1]-prefix_sum[left[i]+1])*(right[i]-i))%MOD)*st[i]%MOD)%MOD;
            sum=sum%MOD;
        }
       return sum%MOD;
    }
};