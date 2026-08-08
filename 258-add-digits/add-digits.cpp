class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;

        while(num>=10){
            int sum = 0 , p = num;
            while(p){
                int ld = p %10;
                sum += ld;
                p/=10;
            }
            num = sum;
        }
        return num;
    }
};