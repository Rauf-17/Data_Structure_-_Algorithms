
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item item1, Item item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

int knapsack01(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (items[i - 1].weight <= w)
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (const Item& item : items) {
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += static_cast<double>(item.value) / item.weight * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int choice;
    cout << "Enter your choice:"<<endl;
    cout << "1. 0/1 Knapsack"<<endl;;
    cout << "2. Fractional Knapsack"<<endl;;
    cout << "3. Neither"<<endl;;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1 || choice == 2) {
        int n;
        cout << "Enter the number of items: ";
        cin >> n;

        int capacity;
        cout << "Enter the knapsack capacity: ";
        cin >> capacity;


        vector<Item> items(n);
        cout << "Enter the weight and value of each item:\n";
        for (int i = 0; i < n; i++) {
            cout << "Item " << i + 1 << "'s Weight: ";
            cin >> items[i].weight;
            cout<< "Item " << i + 1 << "'s Value: ";
            cin  >> items[i].value;
        }


        if (choice == 1) {
            int maxProfit = knapsack01(items, capacity);
            cout << "Maximum profit for 0/1 Knapsack: " << maxProfit << endl;
        } else if (choice == 2) {
            double maxProfit = fractionalKnapsack(items, capacity);
            cout << "Maximum profit Fractional Knapsack: " << maxProfit << endl;
        }
    } else {
        cout << "None Selected & Exiting Program!" << endl;
    }

    return 0;
}
