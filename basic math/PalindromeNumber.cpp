class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        int revNumber = 0;
        if(x<0){
            return false;}
        while (x>0){
            
            int lastDigit = x%10;
             if (revNumber > INT_MAX / 10 || (revNumber == INT_MAX / 10 && lastDigit > 7)) return false;
            revNumber = (revNumber*10) + lastDigit;
            x = x/10;
        }
        return revNumber == original;
        
    }
};