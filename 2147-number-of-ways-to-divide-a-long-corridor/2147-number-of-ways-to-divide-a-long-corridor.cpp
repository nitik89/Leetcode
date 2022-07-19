class Solution {
public:
    int numberOfWays(string cor) {
        int cnt=0;
        int mod=1e9+7;
        for(auto x:cor){
            if(x=='S'){
                cnt=cnt%mod+1;
            }
        }
        
        if(cnt%2!=0||cnt==0){
            return 0;
        }
        cnt=cnt/2;
        
        int grp=0,curr=0,plant=0;
        long long ans=1;
        for(int i=0;i<cor.size();i++){
            if(cor[i]=='S'){
                curr++;
            }
            if(curr==2){
                // cout<<"ues";
                // cout<<i<<" ";
                curr=0;
                grp++;
                if(grp==cnt){
                    // cout<<ans<<" ";
                return ans;
                }
                i++;
                while(i<cor.size()&&cor[i]=='P'){
                    i++;
                    plant++;
                }
                // cout<<plant<<" ";
                i--;
                ans=((ans%mod)*(plant+1)%mod)%mod;
                ans=ans%mod;
                plant=0;
                
            }
            
        }
        // cout<<"ans";
        return ans%mod;
        
    }
};