class Solution {
public:
    int rev(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
 
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            int x=rev(i);
            int sum=x+i;
            if(num==sum){
                return true;
            }
        }
        return false;
    }
};