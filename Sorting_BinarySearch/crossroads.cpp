#include <iostream>
#include <algorithm>

using namespace std;

struct Crossroad{
    int xPos;
    int yPos;
};

struct Tree{
    int xPos;
    int yPos;
};

int n, m;
Crossroad crossroads[500005];
Tree trees[500005];
int minX[500005];
int minY[500005];
int minInside[500005];
int q;

bool cmpCrossX(Crossroad c1, Crossroad c2){
    return c1.xPos == c2.xPos ? c1.yPos < c2.yPos : c1.xPos < c2.xPos;
}

bool cmpCrossY(Crossroad c1, Crossroad c2){
    return c1.yPos == c2.yPos ? c1.xPos < c2.xPos : c1.yPos < c2.yPos;
}

int binarySearchX(int x){
    int l = 0;
    int r = n - 1;
    int mid;
    while(l < r){
        if(r - l == 1){
            return abs(crossroads[r].xPos - x) > abs(x - crossroads[l].xPos) ? abs(x - crossroads[l].xPos) : abs(crossroads[r].xPos - x);
        }
        mid = l + (r - l) / 2;
        if(crossroads[mid].xPos > x){
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return abs(crossroads[l].xPos - x);
}

int binarySearchY(int y){
    int l = 0;
    int r = n - 1;
    int mid;
    while(l < r){
        if(r - l == 1){
            return abs(crossroads[r].yPos - y) > abs(y - crossroads[l].yPos) ? abs(y - crossroads[l].yPos) : abs(crossroads[r].yPos - y);
        }
        mid = l + (r - l) / 2;
        if(crossroads[mid].yPos > y){
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return abs(crossroads[l].yPos - y);
}

int getFirstBigger(int* arr, int x) {
    int index = m;
    int left = 0;
    int right = m - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] <= x)
            left = mid + 1;
        else {
            index = mid;
            right = mid - 1;
        }
    }
    return index;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &crossroads[i].xPos, &crossroads[i].yPos);
    }

    for(int i = 0; i < m; i++){
        scanf("%d%d", &trees[i].xPos, &trees[i].yPos);
    }

    //--------------------------------------------

    sort(crossroads, crossroads + n, cmpCrossX);

    for(int i = 0; i < m; i++){
        minX[i] = binarySearchX(trees[i].xPos);
    }

    sort(crossroads, crossroads + n, cmpCrossY);

    for(int i = 0; i < m; i++){
        minY[i] = binarySearchY(trees[i].yPos);
        minInside[i] = min(minX[i], minY[i]);
    }

    sort(minInside, minInside + m);

    //----------------------------------------------------

    int temp;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &temp);
        printf("%d ", getFirstBigger(minInside, temp / 2));
    }

}