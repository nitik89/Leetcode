class Encrypter {
public:
    map<char,string>mp1;
    map<string,set<char>>mp2;
    vector<string>d;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dict) {
        for(int i=0;i<keys.size();i++){
            mp1[keys[i]]=values[i];
        }
        for(int i=0;i<values.size();i++){
            mp2[values[i]].insert(keys[i]);
        }
        for(auto x:dict){
            d.push_back(x);
        }
    }
    
    string encrypt(string word1) {
        string ans="";
        for(int i=0;i<word1.size();i++){
            if(mp1.find(word1[i])==mp1.end()){
                return "";
            }
            ans+=mp1[word1[i]];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        int cnt=0;
       for(auto x:d){
           string temp="";
           for(int i=0;i<x.size();i++){
               if(mp1.find(x[i])!=mp1.end()){
               temp+=mp1[x[i]];
               }
               else{
                   temp="";
                   break;
               }
           }
           
           if(temp==word2){
               // cout<<temp<<" ";
               cnt++;
           }
       }
        return cnt;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */