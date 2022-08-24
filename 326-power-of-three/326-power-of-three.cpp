class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        
        float x=(log(n)/log(3));
        // cout<<x<<" ";
        if(ceil(x)==x&&(n==1||n%3==0)){
            return true;
        }
        return false;
    }
};