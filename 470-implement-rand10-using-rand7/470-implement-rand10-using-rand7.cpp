// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        
        int i=1;
        int sum=0;
        while(i<=10){
            sum+=rand7();
            i++;
        }
        return (sum%10)+1;
    }
};