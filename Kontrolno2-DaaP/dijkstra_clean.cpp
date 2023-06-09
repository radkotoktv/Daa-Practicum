#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> graph[10005];
bool used[10005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> spis;
int dist[10005];

int main(){
    scanf("%d", &n);
    fill(dist, dist + n, 99999);
    dist[1] = 0;

    int start, end, w;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &start, &end, &w);
        graph[start].push_back({end, w});
    }

    //Dijkstra start

    spis.push({0, 1});
    while(!spis.empty()){
        int node = spis.top().second;
        spis.pop();
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i].first;
            if(!used[next]){
                if(dist[node] + graph[node][i].second < dist[next]){
                    dist[next] = dist[node] + graph[node][i].second;
                    spis.push({dist[next], next});
                }
            }
        }
    }

    //Dijkstra end

    cout << dist[4];
}

/*
10
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