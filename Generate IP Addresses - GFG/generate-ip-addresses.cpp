// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  vector<string>ans;
  void getAns(string str,int p,int idx,string temp){
     
if(p==0){
    if(temp.size()-4==str.size()){
    temp.pop_back();
    ans.push_back(temp);
    return;
}
}
if(str[idx]=='0'){
    getAns(str,p-1,idx+1,temp+"0"+".");
    return;
}
      for(int i=idx;i<str.size();i++){
          
          if(i-idx+1<=3){
          string t=str.substr(idx,i-idx+1);
        // cout<<t<<" ";
          int no=stoi(t);
          if(no<=255){
           getAns(str,p-1,i+1,temp+t+".");
          }
          }
      }
  }
    vector<string> genIp(string &s) {
       getAns(s,4,0,"");
       return ans;
    }

};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}  // } Driver Code Ends