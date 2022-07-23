class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& tar) {
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i++)
        {    sort(s[i].begin(),s[i].end());
                mp[s[i]]++;
        }
        int ans=0;
        for(int i=0;i<tar.size();i++)
        {
           
                sort(tar[i].begin(),tar[i].end());
           
              for(int j=0;j<tar[i].size();j++)
              {
                 string x=tar[i];
                  x.erase(x.begin()+j);
                  if(mp.find(x)!=mp.end())
                  {
                      ans++;
                      break;
                  }
              }
        }
        return ans;
        
    }
};