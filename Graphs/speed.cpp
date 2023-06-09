#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<pair<int, int>, int> f1, pair<pair<int, int>, int> f2){
    return f1.second < f2.second;
}

struct Edge{
    int from;
    int to;
    int w;
};

int n, m;
Edge edges[10001];
int parent[10001];
int height[10001];

void init(){
    for(int i = 0; i < m; i++){
        height[i] = 0;
        parent[i] = i;
    }
}

int findSet(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findSet(parent[node]);
}

void unionSets(int r1, int r2){
    if(height[r1] > height[r2]){
        swap(r1, r2);
    }
    else if(height[r1] == height[r2]){
        height[r1]++;
    }
    parent[r2] = r1;
}

int main(){
    scanf("%d%d", &n, &m);

    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].w);
    }

    sort(edges, edges + m, cmp);
    
    int low = 30001;
    int high = 0;
    for(int i = 0; i < m; i++){
        init();
        int components = m;
        for(int j = i; j < m; j++){
            int r1 = findSet(r1);
            int r2 = findSet(r1);

            if(r1 != r2){
                unionSets(r1, r2);
                m--;
                if(components == 1){
                    int curLow = edges[i].second;
                    int curHigh = high;

                    if(curHigh - curLow < high - low){
                        low = curLow;
                        high = curHigh;
                    }
                }
            }
        }
    }
    printf("%d%d", low, high);

    return 0;
}