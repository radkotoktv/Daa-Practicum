#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
std::map<string, int> myMap;
int n;

int main(){
    scanf("%d", &n);
    string father, son;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &father, &son);
        myMap[father] = i;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", myMap[i]);
    }
}