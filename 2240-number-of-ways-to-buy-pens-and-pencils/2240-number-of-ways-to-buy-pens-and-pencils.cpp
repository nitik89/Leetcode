class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long first=total/cost1;
        long long cnt=(total/cost2)+1;
        
        for(int i=1;i<=first&&total>0;i++){
            
            total-=cost1;
            if(total<0){
                break;
            }
            cnt+=((total/cost2)+1);
        }
      
       
        return cnt;
    }
};