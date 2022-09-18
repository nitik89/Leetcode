auto __speed_up = [](){
    ios::sync_with_stdio(0);    
    cin.tie(0);
    return 0;
}();

class Solution {
public:
  
    int getAns(int n){
        if(n==1){
            return 1;
        }
        int x=getAns(n/2);
        int high=(n<<1);
        
        int v=__builtin_popcount(n);
        if(v%2==0){
            return 2*x;
        }
        else{
            return 2*x+1;
        }
        
    }
    int minimumOneBitOperations(int n) {
        if(n==0){
            return 0;
        }
        return getAns(n);
    }
};