#include <iostream>

using namespace std;

int Partition(int arr[] , int p , int q){
    int i = p - 1 ;
    int pivot = arr[q];

    for(int j = p ; j < q ; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    i++;
    swap(arr[i] , arr[q]);
    return i ;
}
void QuickSort(int arr[] , int p , int q){
    if(p<q){
        int pivot = Partition(arr , p , q);
        QuickSort(arr , p , pivot-1);
        QuickSort(arr , pivot+1 , q);
    }
};
int main(){
    int arr[6] = {3 , 4 , 1 , 9  , 1 , 5};
    QuickSort(arr , 0 , 5);
    for(int i = 0  ; i < 6 ; i++){
        cout << arr[i] << " " ;
    }
}