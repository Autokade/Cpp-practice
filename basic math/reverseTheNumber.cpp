class Solution {
public:
    int reverse(int x) {
        int revNumber = 0;  
        if(x>0){ 
        while(x>0){
            int lastDigit  = x%10;
             if (revNumber > INT_MAX / 10 || (revNumber == INT_MAX / 10 && lastDigit > 7)) return 0;
            if (revNumber < INT_MIN / 10 || (revNumber == INT_MIN / 10 && lastDigit < -8)) return 0;
            revNumber = (revNumber*10)+lastDigit;
            x = x/10;
        }  
        }
        else{
            while(x!=0){
                int lastDigit = x%10;
                 if (revNumber > INT_MAX / 10 || (revNumber == INT_MAX / 10 && lastDigit > 7)) return 0;
            if (revNumber < INT_MIN / 10 || (revNumber == INT_MIN / 10 && lastDigit < -8)) return 0;
                revNumber = (revNumber*10) + lastDigit;
                x = x/10;
                revNumber = (revNumber);
                
            }
        }
        return revNumber;
    }
};