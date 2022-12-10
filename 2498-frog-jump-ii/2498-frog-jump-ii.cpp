class Solution {
public:
    int maxJump(vector<int>& s) {
        int mx=s[1]-s[0];
        for(int i=2;i<s.size();i++){
            mx=max(mx,s[i]-s[i-2]);
        }
        return mx;
    }
};