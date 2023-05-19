#include <iostream>
#include <vector>

using namespace std;

class Student{
public:
    string name;
    int fn;
    int points;

    bool operator < (const Student& other){
        if(this->points < other.points) return true;
        if(this->points == other.points) return this->fn < other.fn;
        return false;
    }
};

Student students[100000];

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(size_t i = 0; i < n; ++i){
        Student temp;
        scanf("%s %d %d", &temp.name, &temp.fn, &temp.points);
        students[i] = temp;
    }

    for(size_t i = 0; i < n; ++i){
        cout << students[i].name << " " << students[i].fn << " " << students[i].points << endl;
    }

    


    // N i Q - broi studenti i vuprosi koito shte si zadade
    // N na broi reda - string S (ime na student) + int FN + int tochki
    // Q reda - int tochki za 3ka;
}