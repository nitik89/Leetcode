class Solution {
public:
    int hammingWeight(uint32_t n) {
    long long wei=1,cnt=0;
       while(wei<=4294967296){
           int val=n&wei;
           if(val){
               cnt++;
           }
           wei=wei<<1;
       }
        return cnt;
    }
};