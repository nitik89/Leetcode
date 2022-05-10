class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_map<char,int> mp ;
    
    int i=0,j =0 , ans=0,n=s.size() ;
    
    while(j<n)
    {
        if(mp.find(s[j])==mp.end()){ mp[s[j]] = j ; j++;}
        else 
        {
           i = max(i,  mp[s[j]]+1) ;
            mp[s[j]] = j ;j++;
        }
        ans = max(ans,j-i) ;
    }
    return ans ;
    
    }
};