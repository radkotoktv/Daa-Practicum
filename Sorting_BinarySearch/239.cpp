#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int n = nums.size();
    int i = 0;
    // {val, idx};
    deque<pair<int,int>> dq;
    vector<int> res;

    for(; i < k; ++i){
        // remove worse elements;
        while(!dq.empty() && dq.back().first <= nums[i]){
            dq.pop_back();
        }
        //add current element;
        dq.push_back({nums[i], i});
    }
    res.push_back(dq.front().first);

    for(; i < n; ++i){
        if(i - dq.front().second >= k){
            dq.pop_front();
        }
        // remove worse elements;
        while(!dq.empty() && dq.back().first <= nums[i]){
            dq.pop_back();
        }
        //add current element;
        dq.push_back({nums[i], i});

        res.push_back(dq.front().first);
    }
    return res;
}


int main(){
    vector<int> test = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result = maxSlidingWindow(test, 3);

    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }

}