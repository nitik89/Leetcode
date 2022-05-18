// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_map<char,int>mp;
        for(auto x:str){
            mp[x]++;
        }
        int cnt=mp.size();
        mp.clear();
        int i=0,j=0,mn=INT_MAX;
        int count=0;
        while(i<str.size()){
            mp[str[i]]++;
            if(mp[str[i]]==1){
                count++;
            }
            if(count==cnt){
                while(j<i&&count==cnt){
                    if(cnt==count){
                        mn=min(mn,i-j+1);
                    }
                    mp[str[j]]--;
                    if(mp[str[j]]==0){
                        count--;
                    }
                    j++;
                }
                if(cnt==count){
                        mn=min(mn,i-j+1);
                    }
            }
            i++;
        }
        return mn;
        
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends