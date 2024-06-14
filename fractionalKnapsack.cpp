#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item i1, Item i2) {
    double ratio1 = (double)i1.value / i1.weight;
    double ratio2 = (double)i2.value / i2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(vector<Item> items, int capacity, int &steps) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (int i = 0; i < items.size(); i++) {
        if (capacity - items[i].weight >= 0) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            double fraction = (double)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            capacity = 0;
        }
        steps++;
        if (capacity == 0)
            break;
    }
    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> items[i].weight >> items[i].value;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;
    int steps = 0;
    double maxValue = fractionalKnapsack(items, capacity, steps);
    cout << "Maximum value we can obtain = " << maxValue << endl;
    cout << "Number of steps executed: " << steps << endl;
    return 0;
}