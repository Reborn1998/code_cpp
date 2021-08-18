/*
 * _______________#########_______________________ 
 * ______________############_____________________ 
 * ______________#############____________________ 
 * _____________##__###########___________________ 
 * ____________###__######_#####__________________ 
 * ____________###_#######___####_________________ 
 * ___________###__##########_####________________ 
 * __________####__###########_####_______________ 
 * ________#####___###########__#####_____________ 
 * _______######___###_########___#####___________ 
 * _______#####___###___########___######_________ 
 * ______######___###__###########___######_______ 
 * _____######___####_##############__######______ 
 * ____#######__#####################_#######_____ 
 * ____#######__##############################____ 
 * ___#######__######_#################_#######___ 
 * ___#######__######_######_#########___######___ 
 * ___#######____##__######___######_____######___ 
 * ___#######________######____#####_____#####____ 
 * ____######________#####_____#####_____####_____ 
 * _____#####________####______#####_____###______ 
 * ______#####______;###________###______#________ 
 * ________##_______####________####______________ 
 * 
 * @Author: Chenjun Ding
 * @Date: 2021-07-01 16:16:52
 * @LastEditTime: 2021-07-01 16:16:52
 * @LastEditors: Chenjun Ding
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int heap[maxn],n= 10;
void downAdjust(int low,int high){
    int i = low, j = i * 2;
    while(j<=high){
        if(j+1<=high && heap[j+1]>heap[j]){
            j = j + 1;
        }
        if(heap[i]<heap[j]){
            swap(heap[i],heap[j]);
            i = j;
            j = i * 2;
        }else{
            break;
        }
    }
}
void createHeap(){
    for(int i=n/2;i>=1;i--){
        downAdjust(i,n);
    }
}
void deleteHeap(){
    heap[1] = heap[n--];
    downAdjust(1,n);
}

void upAdjust(int low, int high){
    int i = high,j = i/2;
    while(j>=low){
        if(heap[j]<heap[i]){
            swap(heap[i],heap[j]);
            i = j;
            j = i/2;
        }else{
            break;
        }
    }
}
void insert(int x){
    heap[++n] = x;
    upAdjust(1,n);
}
void heapSort(){
    createHeap();
    for(int i=n;i>=1;i--){
        swap(heap[1],heap[i]);
        downAdjust(1,i-1);
    }
}
int main(){

}