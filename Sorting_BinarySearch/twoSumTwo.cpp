#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while(l < r && numbers[l] + numbers[r] != target){
        if(numbers[l] + numbers[r] > target){
            r--;
        }
        else {
            l++;
        }
    }
    return {l + 1, r + 1};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    for(int i = 0; i < twoSum(nums, target).size(); i++){
        cout << twoSum(nums, target)[i] << " ";
    }
}