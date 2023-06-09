#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int schedules[10005];
vector<pair<int, int>> graph[10005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> spis;
int dist[10005];
int parent[10005];
vector<int> path;

int main(){
    scanf("%d%d", &n, &m);
    fill(dist, dist + n + 1, 99999999);
    dist[1] = 0;

    parent[1] = 0;
    for(int i = 2; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= n; i++){
        scanf("%d", &schedules[i]);
    }

    int start, end, w;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &start, &end, &w);
        graph[start].push_back({end, w});
    }

    spis.push({0, 1});
    while(!spis.empty()){
        int node = spis.top().second;
        spis.pop();
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i].first;
            int current = dist[node] + graph[node][i].second;
            if(current < dist[next]){
                int curPath = dist[node] + graph[node][i].second;
                if(curPath % schedules[next] && next != n){
                    int x = curPath / schedules[next];
                    curPath = (x + 1) * schedules[next];
                }

                if(curPath < dist[next]){
                    parent[next] = node;
                    dist[next] = curPath;
                    spis.push({dist[next], next});
                }
            }
        }
    }

    if(dist[n] == 99999999){
        printf("-1");
        return 0;
    }

    printf("%d\n", dist[n]);
    
    path.push_back(n);
    while(parent[n] != 0){
        path.push_back(parent[n]);
        n = parent[n];
    }

    printf("%d\n", path.size());

    for(int i = path.size() - 1; i >= 0; i--){
        printf("%d ", path[i]);
    }
}