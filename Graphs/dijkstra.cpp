#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int opt[10001];
const int inf = 999999;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> spis;
vector<pair<int, int>> graph[10001];
bool used[10001];
int n;

void init(){
    scanf("%d", &n);
    int start, end, weight;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &start, &end, &weight);
        graph[start].push_back({end, weight});
        graph[end].push_back({start, weight});
    }

    fill(opt, opt + 1001, inf);
    opt[1] = 0;
}

int main(){
    init();

    spis.push({0, 1});
    while(!spis.empty()){
        int node = spis.top().second;
        used[node] = true;
        spis.pop();
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i].first;
            if(!used[next]){
                if(opt[node] + graph[node][i].second < opt[next]){
                    opt[next] = opt[node] + graph[node][i].second;
                    spis.push({opt[next], next});
                }
            }
        }
    }

    printf("%d", opt[8]);
}

/*
1 2 1
1 3 2
3 6 3
3 7 1
6 8 3
5 8 4
2 5 7
2 4 6
1 4 5
1 7 8
*/