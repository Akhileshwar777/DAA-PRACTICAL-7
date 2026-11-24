
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {

    // Initialize DP array
    vector<int> dp(amount + 1, amount + 1);

    // Base case
    dp[0] = 0;

    // Fill DP array
    for (int i = 1; i <= amount; i++) {

        for (int coin : coins) {

            if (coin <= i) {
                dp[i] = min(dp[i],
                            1 + dp[i - coin]);
            }
        }
    }

    // Check if solution exists
    if (dp[amount] == amount + 1)
        return -1;

    return dp[amount];
}

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Minimum coins required: "
         << coinChange(coins, amount);

    return 0;
}
