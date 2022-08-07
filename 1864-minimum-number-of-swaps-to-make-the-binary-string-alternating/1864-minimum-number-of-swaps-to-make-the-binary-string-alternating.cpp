class Solution {
public:
    int minSwaps(string s) {
        int swap=0;
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0&&s[i]=='1'){
                swap++;
            }
           else if(i%2!=0&&s[i]=='0'){
                swap++;
            }
            if(s[i]=='1'){
                cnt1++;
            }
            else if(s[i]=='0'){
                cnt2++;
            }
            
        }
        // cout<<cnt1<<" "<<cnt2<<"\n";
        if(cnt1!=cnt2){
            if(cnt1+1==cnt2||cnt2+1==cnt1){
                
            }
            else{
                return -1;
            }
            
        }
        int swap2=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0&&s[i]=='0'){
                swap2++;
            }
            else if(i%2!=0&&s[i]=='1'){
                swap2++;
            }
            
        }
        // cout<<swap<<" "<<swap2<<"\n";
        if(swap2%2!=0){
            return swap/2; 
        }
        if(swap%2!=0){
            return swap2/2;
        }
        return min(((swap)/2),((swap2)/2));
    }
};