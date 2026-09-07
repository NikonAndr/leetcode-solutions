class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        bool skip = false;

        for (int i = 0; i < s.size(); i++)
        {
            char letter = s[i];

            bool last = (i == s.size() - 1) ? true : false;

            if (skip)
            {
                skip = false;
                continue;
            }

            switch (letter)
            {
                case 'M':
                    result+=1000;
                    break;
                case 'D':
                    result+=500;
                    break;
                case 'C':
                    if (!last && (s[i+1] == 'D' || s[i+1] == 'M'))
                    {
                        skip = true;
                        if (s[i+1] == 'D')
                        {
                            result += 400;
                            break;
                        }
                        else
                        {
                            result += 900;
                            break;
                        }
                    }

                    result += 100;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'X':
                    if (!last && (s[i+1] == 'L' || s[i+1] == 'C'))
                    {
                        skip = true;
                        if (s[i+1] == 'L')
                        {
                            result += 40;
                            break;
                        }
                        else
                        {
                            result += 90;
                            break;
                        }
                    }

                    result += 10;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'I':
                    if (!last && (s[i+1] == 'V' || s[i+1] == 'X'))
                    {
                        skip = true;
                        if (s[i+1] == 'V')
                        {
                            result += 4;
                            break;
                        }
                        else
                        {
                            result += 9;
                            break;
                        }
                    }

                    result += 1;
                    break;
            }
        }
        return result;
    }
};