#include <iostream>

using namespace std;

int cabel[1000000];
int n;
int k;

bool OK(int x){
    int numberOfCabels = 0;
    for(size_t i = 0; i < n; ++i){
        numberOfCabels += cabel[i]/x;
    }

    return numberOfCabels >= k;
}

int main(){
    //sysadmin zadacha
    int rightBound = 1;
    
    //int arr1[] = {11, 42}; // imame 11 kabela i iskame da gi narejem na 42 ednakvi. Tursim max duljinata na tezi ednakvi.
    //int arr2[] = {33, 17, 42, 13, 7, 5, 23, 20, 1, 18, 6};
    
    int left = 0;
    int right = 10;
    int maxLength = 0;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(OK(mid)){
            left = mid + 1;
            maxLength = max(maxLength, mid);
        }
        else {
            right = mid - 1;
        }
    }
    cout << maxLength;

}