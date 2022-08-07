class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<int,int>mp1;
        
        while(n)
        {
            mp1[n%10]++;
            n=n/10;
        }
        for(int i=0;i<32;i++)
        {
            map<int,int>mp2;
            
            long long p=pow(2,i);
            while(p)
            {
                mp2[p%10]++;
                p=p/10;
                
                
            }
            if(mp1==mp2)
            {
                return true;
            }
        }
        return false;
    }
};