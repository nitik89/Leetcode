class Solution {
public:
    int countPrimes(int n) 
    {
       vector<bool> prime(n+1,true);
        prime[0]= prime[1] = false;
        
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i])
            {
                int t=2*i;
                while(t<=n){
                    prime[t]=false;
                    t+=i;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(prime[i])
            {
                count++;
            }
        }
        return count;  
   }
};
