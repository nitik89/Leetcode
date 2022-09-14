class Solution {
public:
    vector<int>seg;
   void update_util(int i, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
      seg[i] = max(val, seg[i]);
      return;
    }

    int m = (l + r) / 2;
    update_util(2 * i + 1, l, m, pos, val);
    update_util(2 * i + 2, m + 1, r, pos, val);
    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
  }
   int query_util(int i, int qL, int qR, int l, int r) {
    if (l >= qL && r <= qR) {
        // cout<<i<<" "<<seg[i]<<"\n";
        return seg[i];
    }
    if (l > qR || r < qL) return INT_MIN;

    int m = (l + r) / 2;
    return max(query_util(2 * i + 1, qL, qR, l, m), query_util(2 * i + 2, qL, qR, m + 1, r));
  }
    int lengthOfLIS(vector<int>& nums, int k) {
        // int n=nums.size();
        // seg.resize(4*100000,0);
        int n=1e5+1;
        int size = (int)(ceil(log2(n)));
    size = (2 * pow(2, size)) - 1;
        seg.resize(size,0);
        int ans=0;
         for (int i : nums) {
      int lower = max(0, i - k);
      int cur = 1 + query_util(0,lower, i - 1,0,n-1);
             ans=max(cur,ans);
     update_util(0,0,n-1,i,cur);
    }
       
        return ans;
    }
};