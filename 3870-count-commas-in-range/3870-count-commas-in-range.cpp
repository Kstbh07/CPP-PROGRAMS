class Solution {
public:
    int countCommas(int n) {
        
        int demo;
        if(n<1000){
            return 0;
        }else if(n>=1000 && n<=999999){
            demo=n-999;
            return demo;
        }else if(n>=1000000 && n<=999999999){
           int part1 = (999999 - 999) * 1;
            int part2 = (n - 999999) * 2;
            return part1+part2;
        }else {
            
             int part1 = (999999 - 999) * 1;
            int part2 = (999999999- 999999) * 2;
            int part3=(n-999999999)*3;
            return part1+part2+part3;
        }
    }
};