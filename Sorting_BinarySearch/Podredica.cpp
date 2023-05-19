#include <iostream>
using namespace std;

int n;
int k;
int numbers[1000000];

bool OK(int arg){
    
}

int main(){
    scanf("%d, %d", &n, &k);

    for(size_t i = 0; i < n; ++i){
        scanf("%d", &numbers[i]);
    }

    int left = 0;
    int right = 1000000;
    int mid;
    while(left < right){
        mid = left + (right - left) / 2;
        if(OK(mid)){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

}