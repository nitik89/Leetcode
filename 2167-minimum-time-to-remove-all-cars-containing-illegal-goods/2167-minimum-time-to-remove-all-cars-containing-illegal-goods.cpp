class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        
       vector<int>left(n,0);
        vector<int>right(n,0);
        if(s[0]=='1') left[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='1') {
                left[i]=min(left[i-1]+2,i+1);
            }//total cost removal when removing the i elements from the left side of the array
            else {
                left[i]=left[i-1];
            }
        }
        if(s[n-1]=='1') right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1'){
                right[i]=min(right[i+1]+2,n-i);
            }//total cost removal when removing the i elements from the left side of the array
            else{ 
                right[i]=right[i+1];
            }
        }
        int ans=min(left[n-1],right[0]);
        for(int i=0;i<=n-2;i++){
            
            ans=min(left[i]+right[i+1],ans);
        }
        
        return ans;
        
    }
};