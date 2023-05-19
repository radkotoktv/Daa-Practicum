#include <iostream>
#include <algorithm>
using namespace std;

int n;
int m;
int arr[1000];

bool kadan(int k){
    int sum = 0;
    int maxSum = 0;
    for(size_t i = 0; i < n; ++i){
        sum += arr[i] + (i + 1)*k;
        maxSum = max(maxSum, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum >= m;
}

int main(){



    //------------------------------------------------------------------------
    //int sum = 0; - tekushtata suma;
    //int maxSum = 0; - maksimalnata suma do momenta;
    //------------------------------------------------------------------------
    //za primera:
    //sum = 10;
    //maxSum = max(maxSum, sum);
    //posle sum = 6;
    //maxSum = max(maxSum, sum); // max(10, 6) = 10; => maxSum = 10;
    //sum = 15;
    //maxSum = max(maxSum, sum);
    //------------------------------------------------------------------------
}