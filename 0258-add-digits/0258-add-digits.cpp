class Solution {
public:
    int addDigits(int num) {
        std::string res = std::to_string(num);

        while (res.size() > 1)
        {
            int num = 0;
            for (int i = 0; i < res.size(); i++)
            {
                num += (int)(res[i]) - '0';
            }
            
            res = std::to_string(num);
        } 

        return std::stoi(res);
    }
};