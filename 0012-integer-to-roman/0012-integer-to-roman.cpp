class Solution {
public:
    string intToRoman(int num) {
        int temp=num;
        int th=temp/1000;
        
        temp=temp%1000;
       
        int hd=temp/100;
       
        temp=temp%100;
        
        int ten=temp/10;
        temp=temp%10;
        int one=temp;
        // cout<<th<<" "<<hd<<" "<<ten<<" "<<one<<"\n";
        
        string ans="";
        if(th==1){
            ans+="M";
        }
         if(th==2){
            ans+="MM";
        }
         if(th==3){
            ans+="MMM";
        }
        
         if(hd==1){
            ans+="C";
        }
         if(hd==2){
            ans+="CC";
        }
         if(hd==3){
            ans+="CCC";
        }
          if(hd==4){
            ans+="CD";
        }
         if(hd==5){
            ans+="D";
        }
         if(hd==6){
            ans+="DC";
        }
         if(hd==7){
            ans+="DCC";
        }
         if(hd==8){
            ans+="DCCC";
        }
         if(hd==9){
            ans+="CM";
        }
        
        
         if(ten==1){
            ans+="X";
        }
         if(ten==2){
            ans+="XX";
        }
         if(ten==3){
            ans+="XXX";
        }
         if(ten==4){
            ans+="XL";
        }
         if(ten==5){
            ans+="L";
        }
         if(ten==6){
            ans+="LX";
        }
         if(ten==7){
            ans+="LXX";
        }
         if(ten==8){
            ans+="LXXX";
        }
         if(ten==9){
            ans+="XC";
        }
        
        if(one==1){
            ans+="I";
        }
        if(one==2){
            ans+="II";
        }
        if(one==3){
            ans+="III";
        }
        if(one==4){
            ans+="IV";
        }
        if(one==5){
            ans+="V";
        }
        if(one==6){
            ans+="VI";
        }
        if(one==7){
            ans+="VII";
        }
        if(one==8){
            ans+="VIII";
        }
        if(one==9){
            ans+="IX";
        }
        
        return ans;
        
    }
};