class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(!n) return 0;
        
        int i=0, j=i+1;
        int ans=0;
        while(j<n){
            for(int k=i; k<j; k++){
                if(s[j]==s[k]){
                    ans=max(ans, j-i);
                    i=k+1;
                    break;
                }
            }
            j++;
        }
        ans=max(ans, j-i);
        return ans;
    }
};