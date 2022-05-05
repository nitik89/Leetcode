class Solution {
public:
    vector<int>getLPS(string str){
        int n=str.size();
        vector<int>lps(n,0);
        lps[0]=0;
        int j=0;
        for(int i=1;i<n;i++){
            if(str[j]==str[i]){
                lps[i]=j+1;
                j++;
            }
            else{
                while(j>0&&str[i]!=str[j]){
                    j=lps[j-1];
                }
                if(str[i]==str[j]){
                    lps[i]=(j+1);
                    j++;
                }
                else{
                    lps[i]=0;
                }
            }
        }
        return lps;
    }
    int repeatedStringMatch(string a, string b) {
        
        vector<int>lps=getLPS(b);
        //use a circularly
        
        int i=0,j=0;
        while(j<a.size()+b.size()){
            if(i==b.size()){
                return (j-1)/a.size()+1;
            }
            if(a[j%a.size()]==b[i]){
                i++;
                j++;
            }
            else if(i==0){
                j++;
            }
            else if(i>0){
                i=lps[i-1];
            }
        }
        return -1;
        
        
        
    }
    
};




