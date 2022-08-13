#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define N 12
#define max(a, b) (((a) > (b)) ? (a) : (b))



int main(){
    //버블정렬
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1])
                SWAP(arr[j], arr[j+1], temp);
        }
    }

    //선택정렬
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);
    }

    //삽입정렬
    for(int i=1; i<n; i++){
        int key = arr[i];
        for(int j=i-1; j>=0 && list[j]>key; j--){
            list[j+1] = list[j];
        }
        list[j+1] = key; //반복문에서 1빼고 나왔으니까 j+1
    }

    //쉘 정렬
    for(int h=5; h>=1; h-=2){
        for(int i=h; i<=N-1; i++){
            int currentElement = A[i];
            int j=i;
            while(j>=h && A[j-h] > currentElement){
                A[j] = A[j-h];
                j -= h;
            }
            A[j] = currentElement;
        }
    }
















    for(int h=5; h>=1; h-=2;){
        for(int i=h; i<n; i++){
            int cur = A[i];
            int j=i;
            while(j>=h && cur < A[j-h]){
                A[j-h] = A[j];
                j -=h;
            }
            A[j] = cur;
        }
    }
}