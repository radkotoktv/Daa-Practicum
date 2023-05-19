#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> nums = {8, 6, 4, 2, 1};
    sort(nums.begin(), nums.end());
    for(size_t i = 0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
}