#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, p;
int socks[100420];

bool f(int mid){
    int pairs = 0;
    for(int i = 0; i < n- 1; i++){
        if(socks[i + 1] - socks[i] <= mid){
            pairs++;
            i++;
        }
    }
    return pairs >= p;
}

int main(){
    scanf("%d%d", &n, &p);
    int biggestSock;
    for(int i = 0; i < n; i++){
        scanf("%d", &socks[i]);
        biggestSock = max(biggestSock, socks[i]);
    }

    sort(socks, socks + n);

    int l = 1;
    int r = biggestSock;
    int res = biggestSock;
    int mid;

    while (l <= r){
        mid = l + (r - l) / 2;
        if(f(mid)){
            r = mid - 1;
            res = min(res, mid);
        }
        else {
            l = mid + 1;
        }
    }

    printf("%d", res);
}