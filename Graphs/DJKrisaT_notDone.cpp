#include <iostream>
#include <vector>
#include <queue>

using namespace std;

<<<<<<< HEAD
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
=======
struct Edge{
    int to;
    int time;
    int price;
};

int n, m, k;
vector<Edge> graph[100005];
bool used[100005];
int dist[100005];

bool OK(int maxPrice){
    fill(used, used + n + 1, false);
    fill(dist, dist + n + 1, 9999999);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> spis;

    spis.push({0, 1});
    dist[1] = 0;
    while(!spis.empty()){
        int top = spis.top().second;
        int curTime = spis.top().first;
        used[top] = true;
        spis.pop();
        for(int i = 0; i < graph[top].size(); i++){
            int vtime = graph[top][i].time;
            int vprice = graph[top][i].price;
            int vto = graph[top][i].to;
            if(!used[vto] && vprice <= maxPrice && (curTime + vtime < dist[vto])){
                dist[vto] = curTime + vtime;
                spis.push({dist[vto], vto});
>>>>>>> 5eaee1b91d360df3624f12298291c5f620e1552b
            }
        }
    }

<<<<<<< HEAD
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
=======
    return dist[n] <= k;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);

    int start, end, price, time;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%d", &start, &end, &price, &time);
        graph[start].push_back({end, price, time});
    }

    int l = 1;
    int r = 1000000;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(OK(mid)){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    if (r == 1000000) {
        printf("-1\n");
    }
    else {
        printf("%d\n", l);
    }

}
>>>>>>> 5eaee1b91d360df3624f12298291c5f620e1552b
