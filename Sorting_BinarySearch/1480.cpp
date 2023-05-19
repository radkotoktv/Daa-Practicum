#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums){
    vector<int> res = {};
    res.push_back(nums[0]);
    for(size_t i = 1; i < nums.size(); ++i){
        res.push_back(res[i - 1] + nums[i]);
    }
    return res;
}

int main(){
    vector<int> temp = {1, 2, 3, 4};
    vector<int> res = runningSum(temp);

    for(size_t i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
}