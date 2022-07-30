class Solution {
public:
    int findTheLongestSubstring(string s) {
        //set up the mask
        int mask=0;
        unordered_map<char,int>mp;
        mp['a']=1;
        mp['e']=2;
        mp['i']=4;
        mp['o']=8;
        mp['u']=16;
        unordered_map<int,int>msk;
        msk[0]=-1;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])>0){
                mask^=mp[s[i]];
            }
            if(msk.count(mask)){
                 ans=max(ans,i-msk[mask]);
            }
            if(msk.count(mask)==0){
            msk[mask]=i;
            }
            
          }
        return ans;
    }
};