#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<pair<int, int>> graph[300005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> spis;
bool used[300005];
int opt[300005];
int parent[300005];
vector<int> res;

int main(){
    scanf("%d", &m);

    fill(opt, opt + 300005, 99999999);
    opt[1] = 0;

    int s, e, t;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &s, &e, &t);
        graph[s].push_back({e, t});
    }

    parent[1] = 0;
    spis.push({0, 1});
    while(!spis.empty()){
        int node = spis.top().second;
        used[node] = true;
        spis.pop();
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i].first;
            if(!used[next]){
                if(opt[node] + graph[node][i].second < opt[next]){
                    parent[next] = node;
                    opt[next] = opt[node] + graph[node][i].second;
                    spis.push({opt[next], next});
                }
            }
        }
    }

    int temp = parent[5];
    res.push_back(5);
    while(parent[temp] != 0){
        res.push_back(temp);
        temp = parent[temp];
    }
    res.push_back(temp);

    while(!res.empty()){
        printf("%d ", res.back());
        res.pop_back();
    }

}

/*
6
1 3 4
1 2 3
3 6 6
3 5 8
3 4 2
4 5 4
*/