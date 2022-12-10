class Solution {
public:
    int longestAwesome(string s) {
        vector<int>mp(1024,s.size());
        mp[0]=-1;
        int curr=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            curr=curr^(1<<(s[i] - '0'));
            ans=max(ans,i-mp[curr]);
            int len=0;
            for(int j=0;j<10;j++){
               
                len=max(len,i-mp[curr^(1<<j)]);
                
            }
            
            if(mp[curr]==s.size()){
                mp[curr]=i;
            }
            
            ans=max(ans,len);
        }
        return ans;
    }
};