class Solution {
public:
    int countVowelPermutation(int n) {
        unordered_map<char,long long>mp;
        int mod=1e9+7;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        for(int k=2;k<=n;k++){
            long long a=0,i=0,o=0,e=0,u=0;
            a=(a%mod+mp['e']%mod+mp['i']%mod+mp['u']%mod)%mod;
            e=(e%mod+mp['a']%mod+mp['i']%mod)%mod;
            i=(i%mod+mp['e']%mod+mp['o']%mod)%mod;
            o=(o%mod+mp['i']%mod)%mod;
            u=(u%mod+mp['i']%mod+mp['o']%mod)%mod;
            
            mp['a']=a%mod;
            mp['e']=e%mod;
            mp['i']=i%mod;
            mp['o']=o%mod;
            mp['u']=u%mod;
            
        }
        long long sum=(mp['a']%mod+mp['e']%mod+mp['i']%mod+mp['o']%mod+mp['u']%mod)%mod;
        return sum;
        
    }
};