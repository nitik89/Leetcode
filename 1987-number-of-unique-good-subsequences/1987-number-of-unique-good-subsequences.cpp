class Solution {
public:
    int numberOfUniqueGoodSubsequences(string bin) {
        int zero=0,one=0;
        int ac=0,mod=1e9+7;
        for(int i=0;i<bin.size();i++){
            if(bin[i]=='0'){
                ac=1;
                zero=(zero+one)%mod;
            }
            else{
                one=(one+zero+1)%mod;
            }
        }
        return (zero+one+ac)%mod;
    }
};