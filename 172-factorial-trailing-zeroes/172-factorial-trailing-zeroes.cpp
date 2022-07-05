class Solution {
public:
    int trailingZeroes(int n) {
        int m=n;
        int sum=0;
        int val=5;
        int cnt=1;
        while(n>0){
            sum+=(n/5);
            n=n/5;
        }

        return sum;
    }
};