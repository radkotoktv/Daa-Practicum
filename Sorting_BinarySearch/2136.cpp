#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime){
    vector<pair<int,int>> result = {};

    int size = plantTime.size();
    for(size_t i = 0; i < size; ++i)
        result.push_back({growTime[i], plantTime[i]});

    sort(result.begin(), result.end(), greater <pair<int, int>>());

    int daysPassed = 0;
    int maxDays = result[0].second;

    for(size_t i = 0; i < result.size(); ++i){
        daysPassed += result[i].second;
        maxDays = max(maxDays, daysPassed + result[i].first);
    }

    return maxDays;
}

int main(){
    vector<int> plantTime = {1, 4, 3};
    vector<int> growTime = {2, 3, 1};
    cout << earliestFullBloom(plantTime, growTime);
}