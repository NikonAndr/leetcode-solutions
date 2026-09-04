class Solution {
public:
    bool isPalindrome(int x) {
        int power = 0;
        int num = x;
        bool negative = x < 0 ? true : false;
        vector<int> digits;

        while (num >= 1 || num <= -1)
        {
            num /= 10;
            power++;
        }
        
        for (int i = 0; i < power; i++)
        {
            digits.push_back((int)(x / pow(10, power - i - 1)));
            x -= digits[i] * pow(10, power - i - 1);
        }

        if (negative)
        {
            for (int i = 1; i < digits.size(); i++)
            {
                digits[i] = abs(digits[i]);
            }
        }

        
        for (int i = 0; i < digits.size() / 2; i++)
        {
            if (digits[i] != digits[digits.size() - 1 - i])
            {
                return false;
            }
        }

        if (digits.size() == 1 && negative)
        {
            return false;
        }

        return true;
    }
};