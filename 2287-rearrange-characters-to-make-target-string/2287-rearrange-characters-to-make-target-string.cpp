class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int>mp;
        unordered_map<char,int>temp;
        int cnt=0;
        for(auto x:target){
            mp[x]++;
        }
        vector<int>vec(26,0);
        for(int i=0;i<s.size();i++){
          vec[s[i]-'a']++;
        }
        int mn=INT_MAX;
        for(auto x:target){
            if(mp[x]>0){
                mn=min(mn,vec[x - 'a']/mp[x]);
            }
        }
        return mn;
    }
};