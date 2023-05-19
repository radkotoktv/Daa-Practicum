#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int minutes[10005];
vector<pair<int, int>> graph[10005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> spis;
bool used[10005];
int opt[10005];
const int inf = 1e9;
int parent[10001];
vector<int> path;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &minutes[i]);
    }

    int s, e, w;
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &s, &e, &w);
        graph[s].push_back({e, w});
    }

    fill(opt, opt + 10005, inf);

    opt[1] = 0;
    parent[1] = 0;
    
    spis.push({0, 1});
    while(!spis.empty()){
        int node = spis.top().second;
        used[node] = true;
        spis.pop();
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i].first;
            if(!used[next]){
                int curPath = opt[node] + graph[node][i].second;
                if(curPath % minutes[next] && next != n){
                    int x = curPath / minutes[next];
                    curPath = (x + 1) * minutes[next];
                }

                if(curPath < opt[next]){
                    parent[next] = node;
                    opt[next] = curPath;
                    spis.push({opt[next], next});
                }
                
            }
        }
    }

    path.push_back(n);
    int temp = parent[n];
    while(parent[temp] != 0){
        path.push_back(temp);
        temp = parent[temp];
    }
    path.push_back(temp);

    if(opt[n] == inf){
        printf("-1");
    }
    else {
        printf("%d\n", opt[n]);
        printf("%d\n", path.size());
        while(!path.empty()){
            printf("%d ", path.back());
            path.pop_back();
        }
    }

}