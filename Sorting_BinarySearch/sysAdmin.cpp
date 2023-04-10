#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> cables;

bool OK(int mid){
    int numberOfCables = 0;
    for(int i = 0; i < n; i++){
        if(cables[i] >= mid){
            numberOfCables += cables[i] / mid;
        }
    }
    return numberOfCables >= k;
}

int main(){
    scanf("%d%d", &n, &k);
    int temp;
    int rightBound = 1;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        cables.push_back(temp);
        rightBound = max(rightBound, temp);
    }

    sort(cables.begin(), cables.end());

    int l = 1;
    int r = rightBound;
    int maxLength = 0;

    while(l <= r){
        int mid = l + (r - l) / 2;
        if(OK(mid)){
            l = mid + 1;
            maxLength = max(mid, maxLength);
        }
        else {
            r = mid - 1;
        }
    }
    printf("%d", maxLength);
}