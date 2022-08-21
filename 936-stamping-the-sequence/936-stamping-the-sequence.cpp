class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
      int t=target.size();
      int s=stamp.size();
      vector<int>ans;
        bool ihave=true;
        int cnt=0;
      while(cnt<t){
          //check all the subseq and if found we will make that subseq as ?
          int p=cnt;
          for(int i=0;i<=t-s;i++){
              string str="";
              bool found=true;
              bool hasit=true;
              int idx=0;
              for(int j=0;j<s;j++){
                  if(target[i+j]=='?'){
                      
                      continue;
                  }
                  else if(target[i+j]!=stamp[j]){
                      found=false;
                      break;
                  }
                 
                  
                 
                }
              if(found){
                 
                int prev=cnt;
                  for(int k=0;k<s;k++){
                      if(target[k+i]!='?'){
                      target[k+i]='?';
                          cnt++;
                      }
                  }
                  if(cnt>prev){
                       ans.push_back(i);
                      break;
                  }
                  
                 
              }
             
          }
          if(cnt==p){
              break;
          }
      }
        for(auto x:target){
            if(x!='?'){
                return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};