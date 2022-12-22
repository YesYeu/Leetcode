#include <vector>

class Solution {
 public:
  typedef struct Profit {
    int left;
    int right;
    int sum;
    Profit() : left(0), right(0), sum(0) {}
  } t_profit;

  int maxProfit(std::vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    std::vector<int> inc = prices;
    for (int i = 1; i < inc.size(); i++) inc[i] = prices[i] - prices[i - 1];

    t_profit rightended;
    t_profit max_profit;
    max_profit.sum = inc[1];
    max_profit.left = 1;
    max_profit.right = 1;
    rightended.sum = inc[1];
    rightended.left = 1;
    rightended.right = 1;
    for (int i = 2; i < inc.size(); i++) {
      if (inc[i] > 0) {
        if (rightended.sum <= 0) {
          rightended.sum = inc[i];
          rightended.left = i;
        } else
          rightended.sum += inc[i];
      } else if (rightended.sum <= 0) {
        rightended.sum = inc[i];
        rightended.left = i;
      } else {
        rightended.sum += inc[i];
      }

      if (max_profit.sum < rightended.sum) {
        max_profit.left = rightended.left;
        max_profit.right = i;
        max_profit.sum = rightended.sum;
      }
    }

    if (max_profit.sum < 0) max_profit.sum = 0;
    return max_profit.sum;
  }
};