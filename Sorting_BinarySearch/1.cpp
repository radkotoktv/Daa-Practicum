#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {};
    
    sort(nums.begin(), nums.end());
    int j = nums.size();
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] + nums[j] > target){
            i--;
            j--;
        }
        else if(nums[i] + nums[j] < target){
            continue;
        }
        else if(nums[i] + nums[j] == target && result.empty()) {
            result.push_back(i);
            result.push_back(j);
        };
    }
    return result;
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = twoSum(nums, 9);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
}