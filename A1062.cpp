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
 * @Date: 2021-07-05 22:52:52
 * @LastEditTime: 2021-07-05 22:56:38
 * @LastEditors: Chenjun Ding
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
struct Student{
    char name[10];
    int de,cai,sum;
    int flag;
}student[100010];
bool cmp(Student a,Student b){
    if(a.flag!=b.flag){
        return a.flag<b.flag;
    }
    if(a.sum!=b.sum){
        return a.sum>b.sum;
    }
    if(a.de!=b.de){
        return a.de>b.de;
    }
    return strcmp(a.name,b.name)<0;
}
int main(){
    int n,l,h;
    scanf("%d%d%d",&n,&l,&h);
    int m = n;
    for(int i=0;i<n;i++){
        scanf("%s%d%d",student[i].name,&student[i].de,&student[i].cai);
        student[i].sum = student[i].de + student[i].cai;
        if(student[i].de<l || student[i].cai<l){
            student[i].flag = 5;
            m--;
        }
        else if(student[i].de>=h && student[i].cai>=h){
            student[i].flag = 1;
        }else if(student[i].de>=h && student[i].cai<h){
            student[i].flag = 2;
        }else if(student[i].de>=student[i].cai){
            student[i].flag = 3;
        }else{
            student[i].flag = 4;
        }
    }
    sort(student,student+n,cmp);
    printf("%d\n",m);
    for(int i=0;i<m;i++){
        printf("%s %d %d\n",student[i].name,student[i].de,student[i].cai);
    }
}