class Solution {
public:
    int largestVariance(string s) {
        //kadane's on the strings
        int ans=0;
        for(char i='a';i<='z';i++){
            
            for(char j='a';j<='z';j++){
                if(i!=j){
                    int cnt1=0,cnt2=0,diff=INT_MIN,fl=0,fl1=0,has=0;
                for(int k=0;k<s.size();k++){
                   if(s[k]==i){
                       cnt1++;
                      
                   } 
                   if(s[k]==j){
                       
                       cnt2++;
                        }
                  int d=cnt1-cnt2;
                    if(d<0){
                        
                        cnt1=0;
                        cnt2=0;
                        has=1;
                        
                        
                       
                    }
                    
                    if(cnt1&&cnt2){
                         // cout<<i<<" "<<j<<" "<<cnt1<<" "<<cnt2<<"\n";
                    diff=max(d,diff);
                    }
                    else if(has){
                         // cout<<i<<" "<<j<<" "<<cnt1<<" "<<cnt2<<"\n";
                    diff=max(d-1,diff);
                    }
                }
                     ans=max(ans,diff);
                }
               
            }
        }
        return ans;
    }
};