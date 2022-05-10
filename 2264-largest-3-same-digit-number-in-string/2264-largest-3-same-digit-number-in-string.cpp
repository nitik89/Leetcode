class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=0;i<num.size()-2;i++){
            string str=num.substr(i,3);
            char a=str[0];
            char b=str[1];
            char c=str[2];
            if(a==b&&b==c){
                if(str>ans){
                    ans=str;
                }
            }
        }
        return ans;
    }
};