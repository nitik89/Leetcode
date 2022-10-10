class Solution {
public:
    string breakPalindrome(string pal) {
        int size=pal.size();
        if(size==1){
            return "";
        }
        int count=0;
        for(int i=0;i<size/2;i++){
            if(pal[i]-'a'>0){
                pal[i]='a';
                count++;
                break;
            }
        }
        if(count==0){
            pal[pal.size()-1]='b';
        }
        return pal;
    
    }
};