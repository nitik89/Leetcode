class Solution {
public:
    int countAsterisks(string s) {
        int start=0;
        int cnt=0,ans=0;
        for(auto x:s){
            if(start==0){
                if(x=='*'){
                    ans++;
                }
            }
            if(x=='|'){
                if(start==0){
                    start=1;
                }
                else{
                    start=0;
                }
            }
        }
        return ans;
    }
};