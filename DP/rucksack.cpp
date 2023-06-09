#include <iostream>

using namespace std;

struct Item{
    int w;
    int price;
};

int n, t;
Item items[1005];
int dp[1005][1005];

void copyRows(int r1, int r2){
    for(int i = 1; i <= n; i++){
        dp[r1][i] = dp[r2][i];
    }
}


int main(){
    scanf("%d%d", &n, &t);

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &items[i].w, &items[i].price);
        dp[0][i] = 0;
    }


    int curSum = 0;
    int curIndex = 0;
    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= n; j++){
            if(i >= items[j].w && dp[i - items[j].w][0] != 0){
                if(curSum < items[j].price + dp[i - items[j].w][0]){
                    curSum = items[j].price + dp[i - items[j].w][0];
                    curIndex = j;
                }
            }
        }
        if(curSum > dp[i - 1][0]){
            copyRows(i - items[curIndex].w, i);
            dp[i][0] = curSum;
            dp[i][curIndex] = 1;
        }
        else {
            dp[i][0] = dp[i - 1][0];
            copyRows(i, i - 1);
        }
    }

    printf("%d", dp[t][0]);
}

/*
10 5
5 2
7 12
3 1
2 7
3 6
6 8
1 7
2 4
3 17
1 7
*/