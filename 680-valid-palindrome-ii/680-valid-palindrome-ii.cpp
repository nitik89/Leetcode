class Solution {
public:
    bool getAns1(string s){
          int i=0,j=s.size()-1,count=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
            if(s[i+1]==s[j]){
                i++;
                count++;
            }
            else if(s[i]==s[j-1]){
                j--;
                count++;
            }
            else{
                return false;
            }
            if(count>1){
                return false;
            }
            }
            
        }
        return true;
    }
    bool getAns2(string s){
          int i=0,j=s.size()-1,count=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
            if(s[i]==s[j-1]){
                j--;
                count++;
            }
            else if(s[i+1]==s[j]){
                i++;
                count++;
            }
            else{
                return false;
            }
            if(count>1){
                return false;
            }
            }
            
        }
        return true;
    }
    bool validPalindrome(string s) {
     return getAns1(s)||getAns2(s);
    }
};