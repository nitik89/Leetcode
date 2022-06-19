class Solution {
public:
  
    int minimumNumbers(int num, int k) {
        if(num==0){
            return 0;
        }
        for(int i=1;i<=10;i++){
            int val=i*k;
            if(val%10==num%10 && val<=num){
                return i;
            }
        }
        return -1;
    }
};