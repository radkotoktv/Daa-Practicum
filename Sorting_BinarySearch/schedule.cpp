#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int start, duration;
    vector<pair<int, int>> events;;
    while(scanf("%d%d", &start, &duration) != EOF){
        events.push_back({start, duration});
    }

}