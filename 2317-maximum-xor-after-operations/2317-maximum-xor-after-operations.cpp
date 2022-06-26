class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        long long bit=1;
        long long ans=0;
        vector<int>bits(32,0);
        for(int i=0;i<32;i++){
            int br=0;
            for(auto x:nums){
                if((x&bit) >=1){
                    br=1;
                    break;
                }
            }
            if(br==1){
                bits[i]=1;
            }
            else{
                bits[i]=0;
            }
            bit=bit<<1;
            
        }
        
    
        for(int i=0;i<32;i++){
           ans+=(long long)pow(2,i)*bits[i];
        }
        return ans;
    }
};