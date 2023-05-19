#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int coinsSpent = 0;

    int i = 0;
    while(i < costs.size() && coinsSpent <= coins){
        coinsSpent += costs[i];
        i++;
    }
    if(coinsSpent <= coins) return i;
    else return i - 1;
}

int main(){
    vector<int> costs = {1, 6, 3, 1, 2, 5};
    int coins = 20;

    cout << maxIceCream(costs, coins);
    
}