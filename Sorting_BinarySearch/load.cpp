#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, l;
vector<int> stations;

bool OK(int mid){
    int refuels = 0;
    int distance = stations[0];
    int gas = mid;
    for(int i = 1; i < n; i++){
        if(mid < distance) return false;
        gas -= distance;
        distance = stations[i] - distance;
        if(distance > mid){
            refuels++;
            gas = mid;
        }
    } 
    return refuels <= k;
}

int main(){
    scanf("%d%d%d", &n, &k, &l);
    int station;
    for(int i = 0; i < n; i++){
        scanf("%d", &station);
        stations.push_back(station);
    }
    stations.push_back(l);

    sort(stations.begin(), stations.end());

    int left = 1;
    int right = l;
    int best = l;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(OK(mid)){
            left = mid + 1;
            best = min(best, mid);
        }
        else {
            right = mid - 1;
        }
    }
    printf("%d", best);
}