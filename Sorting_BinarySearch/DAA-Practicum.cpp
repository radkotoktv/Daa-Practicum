#include <iostream>

int partition(int* arr, int start, int end){
    int pIndex = start;

    for(std::size_t i = start; i < end; ++i){
        if(arr[i] <= arr[end]){
            std::swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    std::swap(arr[pIndex], arr[end]);

    return pIndex;
}

void quickSort(int* arr, int start, int end){
    if(!arr || start >= end)
        return;

    int pIndex = partition(arr, start, end);
    quickSort(arr, start, pIndex -1);
    quickSort(arr, pIndex + 1, end);
}

int main(){
    int arr[6] = {2, 3, 5, 6, 12, 8};
    quickSort(arr, 0, 5);

    for(int a : arr){
        std::cout << a << " ";
    }
}