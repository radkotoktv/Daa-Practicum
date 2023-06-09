#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> graph[1005];
vector<int> topSort;

bool OK(int maxTemp){
    
}

int main(){
    scanf("%d%d", &n, &m);

    int start, end, temp;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &start, &end, &temp);
        graph[end].push_back({start, temp});
    }

    int l = 1;
    int r = 9999999;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(OK(mid)){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

}