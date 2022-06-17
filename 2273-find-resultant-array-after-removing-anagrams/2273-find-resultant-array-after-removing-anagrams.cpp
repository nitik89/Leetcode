class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<int,int>mp;
        vector<string>ans;
       for(int i=0;i<words.size();i++){
           
           if(mp.find(i)==mp.end()){
           unordered_map<char,int>mp1;
           
           for(auto x:words[i]){
               mp1[x]++;
           }
           for(int j=i;j<words.size();j++){
               unordered_map<char,int>mp2;
               for(auto x:words[j]){
                   mp2[x]++;
               }
                if(mp1==mp2){
                   mp[j]=1;
               }
               else{
                   break;
               }
               
           }
              
               ans.push_back(words[i]);
               
           }
       }
        return ans;
    }
};