#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(pair<int, int>& plant1, pair<int, int>& plant2){
    return plant1.second == plant2.second ? plant1.first > plant2.first : plant1.second > plant2.second;
}

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime){
    vector<pair<int, int>> plants;
    for(int i = 0; i < plantTime.size(); i++){
        plants.push_back({plantTime[i], growTime[i]});
    }

    sort(plants.begin(), plants.end(), cmp);

    int daysPassed = 0;
    int daysNeeded = 0;

    for(int i = 0; i < plants.size(); i++){
        daysPassed += plants[i].first;
        daysNeeded = max(daysNeeded, daysPassed + plants[i].second);
    }

    return daysNeeded;
}

int main(){
    vector<int> plantTime = {1, 4, 3};
    vector<int> growTime = {2, 3, 1};

    cout << earliestFullBloom(plantTime, growTime);
}