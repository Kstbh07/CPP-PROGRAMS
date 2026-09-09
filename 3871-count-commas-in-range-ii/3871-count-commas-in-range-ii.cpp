class Solution {
public:
    long long countCommas(long long n) {
         long long ans=0;
        long long base=1000;
        int comma=1;

        while(base<=n){
             long long next = base * 1000 - 1;
            long long count = min(n, next) - base + 1;
            ans+=count*comma;
            base*=1000;
            comma++;
        }
        return ans;
    }
};