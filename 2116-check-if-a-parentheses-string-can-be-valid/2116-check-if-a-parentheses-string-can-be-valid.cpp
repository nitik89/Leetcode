class Solution {
public:
    bool canBeValid(string s, string lock) {
      int bal=0;
      int flip=0;
        if(s.size()%2!=0){
            return false;
        }
      for(int i=0;i<s.size();i++){
          if(lock[i]=='0'){
              flip++;
          }
          else {
              if(s[i] == '('){
                     bal++;
                  }
                  else{
                          bal--;
                  }
          }
          if(bal+flip<0){
                  return false;
          }
      }
        bal=0;
        flip=0;
        
        for(int i=s.size()-1;i>=0;i--){
             if(lock[i]=='0'){
              flip++;
          }
          else {
              if(s[i] == ')'){
                     bal++;
                  }
                  else{
                          bal--;
                  }
          }
          if(bal+flip<0){
                  return false;
          }
        }
        return true;
    }
};