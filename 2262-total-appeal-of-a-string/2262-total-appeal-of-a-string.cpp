class Solution {
public:
    long long appealSum(string s) {
        long long prev[26];
        int mod=1e9+7;
        memset(prev,-1,sizeof prev);
        long long cnt=0,save=0;
        for(int i=0;i<s.size();i++){
            int pre=prev[s[i] - 'a'];
            int diff=0;
            if(pre!=-1){
                // cout<<pre<<" ";
            diff=(i-pre-1)%mod;
            }
            else{
                diff=(i)%mod;
            }
            // cout<<diff<<" "<<cnt<<" "<<save<<"\n";
            long long temp=cnt;
            cnt+=(save%mod+diff%mod+1)%mod;
             save=save%mod+diff%mod+1;
            // cout<<cnt<<" "<<save<<"\n";
            prev[s[i] - 'a']=i;
            // cout<<cnt<<" ";
        }
        return cnt;
    }
};