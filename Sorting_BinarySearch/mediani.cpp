#include <iostream>
#include <queue>

using namespace std;

int arr[1000000000];

int main(){
    int n;
    scanf("%d", &n);

    priority_queue<int, vector<int>, less<int>> maxPQ; // default heap is maxHeap;
    priority_queue<int, vector<int>, greater<int>> minPQ; // minHeap;
    for(size_t i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

}