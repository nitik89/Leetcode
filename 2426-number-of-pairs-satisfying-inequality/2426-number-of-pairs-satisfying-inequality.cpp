class MaxSegmentTree {
 public:
  long long n;
  vector<long long> tree;
  MaxSegmentTree(long long n_) : n(n_) {
    long long size = (long long)(ceil(log2(n)));
    size = (2 * pow(2, size)) - 1;
    tree = vector<long long>(size);
  }
  
  long long max_value() { return tree[0]; }

  long long query(int l, int r) { return query_util(0, l, r, 0, n - 1); }

  long long query_util(int i, int qL, int qR, int l, int r) {
    if (l >= qL && r <= qR) return tree[i];
    if (l > qR || r < qL) return 0;

    long long m = (l + r) / 2;
    return query_util(2 * i + 1, qL, qR, l, m)+ query_util(2 * i + 2, qL, qR, m + 1, r);
  }

  void update(int i) { update_util(0, 0, n - 1, i); }
  void update_util(int i, int l, int r, int pos) {
    if (pos < l || pos > r) return;
    if (l == r) {
      tree[i]++;
      return;
    }

    int m = (l + r) / 2;
    update_util(2 * i + 1, l, m, pos);
    update_util(2 * i + 2, m + 1, r, pos);
    tree[i] = tree[2 * i + 1]+tree[2 * i + 2];
  }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        MaxSegmentTree tree(1e5 + 1);
        long long ans=0;
        for(int i=nums1.size()-1;i>=0;i--){
             ans+= tree.query(nums1[i]-nums2[i]+30000,80000);
            tree.update(nums1[i]-nums2[i]+diff+30000);
        }
        return ans;
    }
};