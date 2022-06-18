class WordFilter {
public:
    unordered_map<string,int>mp;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string str=words[i];
            for(int j=0;j<=str.size();j++){
                string temp=str.substr(0,j);
                for(int k=str.size()-1;k>=0;k--){
                    string t=str.substr(k,str.size()+1-k);
                    // cout<<t<<" ";
                    mp[temp+" "+t]=i;
                    
                }
                // cout<<"\n";
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if(mp.find(prefix+" "+suffix)==mp.end()){
            return -1;
        }
        return mp[prefix+" "+suffix];
        // return 0;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */