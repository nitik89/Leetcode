class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==" "){
            return 1;
        }
       vector<int>count(300,0);
        int st=0,en=0;
        int ans=0;
        while(st<s.size()){
            
            count[s[st]]++;
            while(en<s.size()&&count[s[st]]!=1){
                count[s[en]]--;
                en++;
            }
            ans=max(st-en+1,ans);
            
           st++; 
        }
        return ans;
        
    }
};