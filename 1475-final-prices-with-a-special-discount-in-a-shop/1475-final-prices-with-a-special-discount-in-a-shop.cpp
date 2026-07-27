class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> output(prices.size());

        for (int i = 0; i < prices.size(); i++)
        {
            int price = prices[i];

            if (i != prices.size()-1)
            {
                for (int j = i+1; j < prices.size();j++)
                {
                    if (prices[j] <= price)
                    {
                        price -= prices[j];
                        break;
                    }
                }   
            }

            output[i] = price;
        }

        return output;
    }
};