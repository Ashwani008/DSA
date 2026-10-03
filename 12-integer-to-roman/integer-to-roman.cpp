class Solution {
public:
    string intToRoman(int num) {
        vector<string> romSym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> romVal = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5,4, 1};
        string ans  ="";
        while (num > 0){
            for(int i =0; i<romSym.size(); i++){
                if(romVal[i] <= num){
                    ans += romSym[i];
                    num = num - romVal[i];
                    break;
                }
            }
        }
        return ans;
    }
};