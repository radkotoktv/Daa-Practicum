#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int numbers[1000000];

bool f(int mid){
    int maxLength = 0;
    int curLength = 0;
    for(int i = 0; i < n; i++){
        if(mid <= numbers[i]){
            curLength++;
        }
        else {
            maxLength = max(maxLength, curLength);
            curLength = 0;
        }
    }

    return maxLength == k;
}

int main(){
    scanf("%d%d", &n, &k);
    int biggest = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
        biggest = max(biggest, numbers[i]);
    }

    int l = 1;
    int r = biggest;
    int res = 1;
    int mid;

    while(l <= r){
        mid = l + (r - l) / 2;
        if(f(mid)){
            l = mid + 1;
            res = max(res, mid);
        }    
        else {
            r = mid - 1;
        }
    }

    printf("%d\n", res);
}