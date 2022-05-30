class Solution {
public:
    
    int divide(int dividend, int divisor) {
        int s=1;
        if(dividend==INT_MAX && (divisor==1)) return INT_MAX;
        if(dividend==INT_MIN && (divisor==1)) return INT_MIN;
         if(dividend==INT_MAX && (divisor==-1)) return INT_MIN+1;
        if(dividend==INT_MIN && (divisor==-1)) return INT_MAX;
        if(dividend>0&&divisor<0||dividend<0&&divisor>0){
            s=-1;
        }
        
        long  n1 = labs(dividend), n2 = labs(divisor);
        // cout<<n1<<" "<<n2<<"\n";
        long cnt=0;
      while(n2<=n1){
          long  sv=n2;
          
          long  fact=1;
         while(sv<<1 <= n1){
             sv=sv<<1;
             fact=fact<<1;
         }
         n1-=sv;
          cnt+=fact;
          
      }
        return cnt*s;
    }
};