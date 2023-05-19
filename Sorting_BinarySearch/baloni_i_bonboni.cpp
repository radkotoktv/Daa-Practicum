#include <iostream>
#include <algorithm>

using namespace std;

int balloons[100000];
int candy[100000];

int main(){ //elliot za kontrolno
    int n, m;
    scanf("%d%d", &n, &m);

    for(size_t i = 0; i < n; ++i){
        scanf("%d", &balloons[i]);
    }

    for(size_t i = 0; i < n; ++i){
        scanf("%d", &candy[i]);
    }

    // az imam obshto m balona;
    // na den i iska A[i] balona;
    // na den i trqbva da mu dam B[i] bonbona za vseki lipsvasht balon;

    //lubo shte go kachi iei;
}