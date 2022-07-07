#define ll long long 
class Solution {
public:
    ll distinctNames(vector<string>& ideas) {
        unordered_map<string,ll>mp;
        unordered_map<char,ll>first;
        vector<vector<ll>>vec(26,vector<ll>(26,0));
        for(auto x:ideas){
            mp[x]=1;
            
        }
        ll cnt=0;
        for(ll i=0;i<ideas.size();i++){
            char old=ideas[i][0];
            for(char j='a';j<='z';j++){
                
                string str=ideas[i];
                str[0]=j;
                if(mp.count(str)==0){
                 
                    vec[old - 'a'][j - 'a']++;
                
                
            }
        }
        }
        // int cnt=0;
        for(ll i=0;i<26;i++){
            // cout<<char(i+'a')<<" ";
            for(ll j=0;j<26;j++){
            // cout<<vec[i][j]<<" ";
                if(i==j){
                    continue;
                }
                else if(vec[i][j]>0){
                cnt+=vec[i][j]*vec[j][i];
                }
            }
            // cout<<"\n";
            
        }
        
    
        return cnt;
    }
};