class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s!="1"){
            
            if(s[s.size()-1]=='1'){
                int carry=1;
                for(int i=s.size()-1;i>=0;i--){
                    if(s[i]=='1'&&carry){
                        carry=1;
                        s[i]='0';
                    }
                    else if(s[i]=='0'&&carry){
                        carry=0;
                        s[i]='1';
                    }
                    
                }
                if(carry){
                    s='1'+s;
                }
                ans++;
            }
            else{
                s.pop_back();
                ans++;
            }
        }
        return ans;
    }
};