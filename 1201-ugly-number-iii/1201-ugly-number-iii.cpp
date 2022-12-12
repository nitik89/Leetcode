class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long s=0,e=2e9;
        int ans=-1;
        while(s<=e){
             int mid = s + (e - s) / 2;
            if(count(mid,a,b,c)>=n){ //check count of the current answer and check whether it is in the range or not i'e there are atleast n numbers or not
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int count(long long n,long long a,long long b,long long c){
        int cnt=(n/a)+(n/b)+(n/c)-(n/lcm(a,b))-(n/lcm(c,b))-(n/lcm(c,a))+(n/(lcm(a,lcm(b,c))));
        return cnt;
    }
    long long lcm(long long a,long long b){
        long long l=(a*b)/__gcd(a,b);
        return l;
    }
    
};