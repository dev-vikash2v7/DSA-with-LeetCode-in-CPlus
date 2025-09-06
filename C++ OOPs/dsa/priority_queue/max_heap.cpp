#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:
    /* data */
    int size = -1;
    int H[50];
public:

int parent(int i){
    return (i-1) / 2;
}

    void insert(int data){

        H[++size] = data;
        shiftUp(size);
    }

    void shiftUp(int i){

        while (i > 0 && H[parent(i)] < H[i])
        {
            swap(H[parent(i)] , H[i]);
            i = parent(i);
        }
    };

    int leftChild(int i ){
        return i * 2 + 1;
    }
    int rightChild(int i ){
        return i * 2 + 2;
    }
    void shiftDown(int i){

        int maxIndex = i ;

        int l  = leftChild(i);
        int r  = rightChild(i);

        if(l<=size && H[maxIndex] < H[l]){
            maxIndex = l;
        }
        if( r<=size && H[maxIndex] < H[r]){
            maxIndex = r;
        }

if(maxIndex != i){
        swap(H[maxIndex] , H[i]);
        shiftDown(maxIndex);

}




    };

     void remove(){
            H[0] = H[size];
            size--;
            shiftDown(0);

    }

    void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;

    if (p > oldp) {
        shiftUp(i);
    }
    else {
        shiftDown(i);
    }
}


    int getMax(){

        return H[0];
    }
     void display(){
            for(int i = 0 ; i <= size ; i++){
                cout << H[i] << " ";
            }
cout <<"\n";
    }
};



int main()
{
    
MaxHeap h;

 h.insert(45);
    h.insert(20);
    h.insert(14);
    h.insert(12);
    h.insert(31);
    h.insert(7);

h.display();

// h.remove();

h.changePriority(4,47);
// h.remove();
// h.remove();

h.display();
    return 0;
}