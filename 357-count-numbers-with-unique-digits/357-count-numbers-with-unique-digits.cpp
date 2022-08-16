class Solution {
public:
    int fact(int n)
{
    if (n <= 1)
        return 1;
    return n*fact(n-1);
}
 
int perm(int n, int r)
{
    return fact(n)/fact(n-r);
}
    int countNumbersWithUniqueDigits(int n) {
        int cnt=0;
        
        for(int i=1;i<=n+1;i++){
            cnt+=9*perm(9,n-i);
        }
        return cnt+1;
    }
};