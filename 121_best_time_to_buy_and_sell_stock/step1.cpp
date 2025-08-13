class SolutionPythonMimic {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            min_price = std::min(min_price, prices[i]);
            max_profit = std::max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};


class SolutionWA {
public:
    int maxProfit(vector<int>& prices) {
        int min_price;
        int max_profit;
        for (int price : prices) {
            min_price = std::min(min_price, price);
            max_profit = std::max(max_profit, price - min_price);
        }
        return max_profit;
    }
};


#include <climits>

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int price : prices) {
            min_price = std::min(min_price, price);
            max_profit = std::max(max_profit, price - min_price);
        }
        return max_profit;
    }
};
