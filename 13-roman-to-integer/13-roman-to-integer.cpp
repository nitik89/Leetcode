class Solution {
public:
    int getAns(char c){
        if (c=='I') return 1;
		else if (c=='V') return 5;
		else if (c=='X') return 10;
		else if (c=='L') return 50;
		else if (c=='C') return 100;
		else if (c=='D') return 500;
		else if (c=='M') return 1000;
		else return 0;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int temp=0;
            if(i<s.size()-1){
                temp=getAns(s[i]);
                int next=getAns(s[i+1]);
                if(next>temp){
                    temp=next-temp;
                    i++;
                }
                
            }
            else {
                temp=getAns(s[i]);
            }
            ans+=temp;
        }
        return ans;
    }
};