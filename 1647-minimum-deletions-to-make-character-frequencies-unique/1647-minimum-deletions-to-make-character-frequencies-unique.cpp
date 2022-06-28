class Solution {
public:
    int minDeletions(string s) {
       vector<int>mp(26,0);
        for(auto x:s){
            mp[x-'a']++;
        }
      
       
        vector<int>stk;
       
        //     stk.push_back(x.first);
        // }
        //cout<<stk.size();
        for(auto x:mp){
            if(x>0){
            stk.push_back(x);
            }
        }
        int count=0;
        sort(stk.begin(),stk.end());
        //reverse(stk.begin(),stk.end());
      // for(auto x:stk){
      //       cout<<x<<" ";
      //   }
       for(int i=stk.size()-1;i>=0;i--){
           for(int j=i-1;j>=0;j--){
              if(stk[i]==stk[j]&&stk[i]>0){
                  stk[j]--;
                  count++;
              }
               
           }
       }
      
        // for(auto x:mp){
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        return count;
        
    }
};