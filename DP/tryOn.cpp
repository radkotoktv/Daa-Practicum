#include <iostream>

using namespace std;

int dp[2][1005];
int n;
int sq[1005];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &sq[n]);
    }

    //dp[0][i] ako e +;
    //dp[1][i] ako e -;

    dp[0][0] = 0;
    dp[1][0] = 0;
    for(int i = 1; i < n; i++){
        if(sq[i] - sq[i - 1] >= 0){
            dp[0][i] = dp[1][i - 1] + 1;
            dp[1][i] = dp[1][i - 1];
            cout << "dp[" << 1 << "][" << i << "] = " << dp[0][i] << endl;
        }
        else{
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[0][i - 1] + 1;
            cout << "dp[" << 0 << "][" << i << "] = " << dp[0][i] << endl;
        }
    }   

    printf("%d" , max(dp[0][n - 1] + 1, dp[1][n - 1] + 1));
}