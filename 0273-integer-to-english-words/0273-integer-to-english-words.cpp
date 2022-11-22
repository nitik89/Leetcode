class Solution {
public:
     string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string getAns(int n){
       if(n >= 1000000000) return getAns(n/1000000000) + " Billion" + getAns(n%1000000000);   
        else if(n >= 1000000) return getAns(n/1000000) + " Million" + getAns(n%1000000);
        else if(n >= 1000)    return getAns(n/1000) + " Thousand" + getAns(n%1000);
        else if(n >= 100)     return getAns(n/100) + " Hundred" + getAns(n%100);
        else if(n >= 20)      return " " + tens[n/10] + getAns(n%10);
        else if(n >= 1)       return " " + digits[n];
        return "";
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
       return getAns(num).substr(1);
    }
};