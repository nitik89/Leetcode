class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,int>mp;
        for(auto x:words){
            mp[x]++;
        }
        string ans="";
        int res=0;
        for(int i=0;i<s.size();i++){
            ans+=s[i];
            res+=mp[ans];
        }
        return res;
    }
};