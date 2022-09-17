class Solution {
public:
    bool isPal(string &str,int i,int j){
        // int i=0,j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string str=words[i];
            reverse(str.begin(),str.end());
          mp[str]=i;
        }
        vector<vector<int>>ans;
        if(mp.find("")!=mp.end()){
            for(int i=0;i<n;i++){
                if(i!=mp[""]&&isPal(words[i],0,words[i].size()-1)){
                ans.push_back({i,mp[""]});
                ans.push_back({mp[""],i});
                }
            }
            mp.erase("");
        }
        
        for(int i=0;i<n;i++){

            string str=words[i];
            for(int j=0;j<words[i].size();j++){
                
                
               
                
               if (isPal(words[i], j, words[i].size() - 1))
				{
					string right = words[i].substr(0,j);
					if (mp.find(right) != end(mp) && mp[right] != i)
					{
						ans.push_back(vector<int> {i, mp[right]});
					}
				}
				
				if (isPal(words[i], 0, j - 1))
				{
					string left = words[i].substr(j);
					if (mp.find(left) != end(mp) && mp[left] != i)
					{
						ans.push_back(vector<int> {mp[left], i});
					}
				}
               
            }
        }
        return ans;
    }
    
};