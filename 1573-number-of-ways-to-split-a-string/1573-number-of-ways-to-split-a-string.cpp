class Solution {
public:
    int numWays(string s) {
        long long sum=0;
        int mod=1e9+7;
        for(auto x:s){
            sum=sum%mod+(x - '0');
        }
        if(sum==0){
            int i=1;
            for(int j=3;j<s.size();j++){
                i=i%mod+(j-1)%mod;
            }
            return i%mod;
        }
        else if(sum%3!=0){
            return 0;
        }
        else{
            
            int v=sum/3;
            int curr=0;
            long long cnt=0;
            for(int i=0;i<s.size();i++){
                if(curr==v){
                    cnt=cnt%mod+1;
                }
                if(s[i]=='1'){
                    curr=curr%mod+1;
                }
            }
            long long cnt2=0;
            curr=0;
            for(int i=s.size()-1;i>=0;i--){
                if(curr==v){
                    cnt2=cnt2%mod+1;
                }
                
                if(s[i]=='1'){
                    curr=curr%mod+1;
                }
            }
            long long mul=((cnt2%mod)*(cnt%mod))%mod;
            return mul%mod;
            
        }
    }
};