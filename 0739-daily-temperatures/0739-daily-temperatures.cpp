class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> stack;

        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
            {
                int index = stack.top();
                stack.pop();
                answer[index] = i - index;
            }
            stack.push(i);
        }

        return answer;
    }
};