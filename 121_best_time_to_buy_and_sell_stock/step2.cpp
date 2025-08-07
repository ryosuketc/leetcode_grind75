// INT_MAX
#include <climits>

class Solution {
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

// std::numeric_limits<int>::max()
#include <limits>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = std::numeric_limits<int>::max();
        int max_profit = 0;
        for (int price : prices) {
            min_price = std::min(min_price, price);
            max_profit = std::max(max_profit, price - min_price);
        }
        return max_profit;
    }
};
