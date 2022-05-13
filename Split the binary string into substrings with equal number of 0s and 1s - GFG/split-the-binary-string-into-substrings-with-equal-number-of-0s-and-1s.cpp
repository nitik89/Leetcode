// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int one=0,zero=0;
        int count=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
                zero++;
            }
            else{
                one++;
            }
            if(one==zero){
                one=0;
                zero=0;
                count++;
            }
        }
        if(one!=0||zero!=0){
            return -1;
        }
        return count==0?-1:count;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends