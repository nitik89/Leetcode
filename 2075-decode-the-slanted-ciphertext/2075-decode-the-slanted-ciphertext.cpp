
class Solution {
public:
    string decodeCiphertext(string eT, int rows) {
        int n=eT.size();   
        int size=(n/rows);
        // cout<<n<<" ";
        int curr=0;
        map<int,string>mp;
        for(int i=0;i<rows;i++){
            curr+=i;
            int off=size*i+i;
            while(curr<size*(i+1)){
                mp[curr-off]+=eT[curr];
                curr++;
            }
        }
        string ans="";
        for(auto x:mp){
            // cout<<x.first<<" ";
          ans+=x.second;
        }
        int j=ans.size()-1;
        while(j>=0&&ans[j]==' '){
            j--;
        }
        
        return ans.substr(0,j+1);
        
    }
};