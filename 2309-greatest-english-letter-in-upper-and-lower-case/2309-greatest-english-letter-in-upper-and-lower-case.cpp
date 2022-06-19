class Solution {
public:
    string greatestLetter(string s) {
        vector<int>up(26,0);
        vector<int>lower(26,0);
        for(auto x:s){
            if(islower(x)){
                lower[x - 'a']++;
            }
            if(isupper(x)){
                up[x - 'A']++;
            }
        }
        int ans=-1;
        for(int i=0;i<26;i++){
            if(up[i]>=1&&lower[i]>=1){
                ans=i;
            }
        }
        if(ans==-1){
            return "";
        }
        string t="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
       string an="";
        an+=t[ans];
        return an;
    }
};