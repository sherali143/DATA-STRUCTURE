#include<iostream>
using namespace std;
int max(int arr[4]){
    int *ptr1;
    int *max = arr;
    for(int i = 0 ; i < 4 ; i++){
        if (*max < arr[i]){
            *max  = arr[i];
        }
    }
    return *max;
}
int main(){
    int arr[4] = {1,2,3,4};
    for (int i = -10000 ; i < 10000 ; i++){
        while (i > max(arr) and i > 0){
            if (i < max(arr)+2){
                cout<< i;
                
                break;
                i = i - 1;
            }
        
        }
    }
}

