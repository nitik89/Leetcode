class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt=0;
        int n=s.size();
        for(auto x:s){
            if(x==letter){
                cnt++;
            }
        }
        // cout<<(cnt/n)<<" ";
        return (cnt*100)/n;
    }
};