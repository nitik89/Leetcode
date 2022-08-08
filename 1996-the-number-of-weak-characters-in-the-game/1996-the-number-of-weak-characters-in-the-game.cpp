class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
       sort(prop.begin(),prop.end(),[&](vector<int>&a,vector<int>&b){
           if(a[0]==b[0]){
               return a[1]>b[1];
           }
          return a[0]<b[0]; 
       }); 
        
      stack<pair<int,int>>st;
        int cnt=0;
      for(int i=0;i<prop.size();i++){
           // cout<<prop[i][0]<<" "<<prop[i][1]<<"\n";
          while(!st.empty()&&st.top().second<prop[i][1]&&st.top().first<prop[i][0]){
            
                   cnt++;
              
             
              st.pop();
          }
          st.push({prop[i][0],prop[i][1]});
      }
        return cnt;
    }
};