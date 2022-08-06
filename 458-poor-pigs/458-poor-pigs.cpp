class Solution {
public:
    int poorPigs(int buckets, int die, int test) {
       int inter=test/die;
        return ceil(log(buckets)/log(inter+1));
    }
};