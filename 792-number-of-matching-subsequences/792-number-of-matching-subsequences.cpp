class Solution {
public:
    int getIt(string a,string&s){
        int i=0,j=0;
        while(i<a.size()&&j<s.size()){
            if(a[i]==s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==a.size()){
            return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt=0;
        unordered_map<string,int>mp;
        for(auto x:words){
            mp[x]++;
        }
        for(auto x:mp){
            if(getIt(x.first,s)){
                cnt+=x.second;
            }
        }
        return cnt;
    }
};