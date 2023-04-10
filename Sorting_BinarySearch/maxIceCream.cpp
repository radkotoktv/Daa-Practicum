#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int sum = 0;
    for(int i = 0; i < costs.size(); i++){
        if(coins >= costs[i]){
            sum++;
            coins -= costs[i];
        }
    }

    return sum;
}

int main(){
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    cout << maxIceCream(costs, coins);
}