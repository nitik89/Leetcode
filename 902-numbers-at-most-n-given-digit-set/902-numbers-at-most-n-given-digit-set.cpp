class Solution {
public:

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
       int cnt=0;
        int x=digits.size();
        string str=to_string(n);
        for(int i=1;i<str.size();i++){
            cnt+=pow(x,i);
        }
        for(int i=0;i<str.size();i++){
            bool hasprev=false;
            for(auto &v:digits){
                if(v[0]<str[i]){
                    cnt+=pow(x,str.size()-i-1);
                }
                else if(v[0]==str[i]){
                    hasprev=true;
                }
            }
            if(!hasprev){
                return cnt;
            }
        }
        return cnt+1;
    }
};