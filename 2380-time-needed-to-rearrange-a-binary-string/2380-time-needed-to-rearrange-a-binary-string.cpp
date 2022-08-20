class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int j=0;
        while(true){
            int cnt=0;
        for(int i=0;i<s.size();i++){
        
            if(i+1<s.size()){
                if(s[i]=='0'&&s[i+1]=='1'){
                    
                    swap(s[i],s[i+1]);
                    i++;
                    cnt++;
                }
            }
        }
            if(cnt==0){
                return j;
            }
            else{
                j++;
            }
        }
        return j;
    }
};