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
 * @Date: 2021-07-28 10:10:31
 * @LastEditTime: 2021-07-28 10:10:32
 * @LastEditors: Chenjun Ding
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
int flag[128]= {0};
int main(){
   string a,b;
   getline(cin,a);
   getline(cin,b);
   for(int i=0;i<b.size();i++){
       flag[b[i]] = 1;
   }
   for(int i=0;i<a.size();i++){
       if(flag[a[i]]==0){
           cout<<a[i];
       }
   }
}