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
 * @Date: 2021-07-12 14:26:56
 * @LastEditTime: 2021-07-12 14:26:56
 * @LastEditors: Chenjun Ding
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct Student{
    int GE,GI,sum;
    int r,stuID;
    int cho[6];
}stu[40010];
struct School{
    int quota;
    int stuNum;
    int id[40010];
    int lastAdmit;
}sch[110];

bool cmpStu(Student a,Student b) {
    if(a.sum!=b.sum) return a.sum>b.sum;
    return a.GE>b.GE;
}

bool cmpID(int a,int b) {
    return stu[a].stuID<stu[b].stuID;
}

int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++) {
        scanf("%d",&sch[i].quota);
        sch[i].stuNum = 0;
        sch[i].lastAdmit = -1;
    }
    for(int i=0;i<n;i++){
        stu[i].stuID = i;
        scanf("%d%d",&stu[i].GE,&stu[i].GI);
        stu[i].sum = (stu[i].GE + stu[i].GI)/2;
        for(int j=0;j<k;j++) {
            scanf("%d",&stu[i].cho[j]);
        }
    }
    sort(stu,stu+n,cmpStu);
    for(int i=0;i<n;i++) {
        if(i>0 && stu[i].sum ==stu[i-1].sum && stu[i].GE==stu[i-1].GE) {
            stu[i].r = stu[i-1].r;
        }else{
            stu[i].r = i;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int choice = stu[i].cho[j];
            int num = sch[choice].stuNum;
            int last = sch[choice].lastAdmit;
            if(num<sch[choice].quota || (last!=-1 && stu[i].r==stu[last].r)){
                sch[choice].id[num] = i;
                sch[choice].lastAdmit = i;
                sch[choice].stuNum++;
                break;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        if(sch[i].stuNum>0){
            sort(sch[i].id,sch[i].id+sch[i].stuNum,cmpID);
            for(int j=0;j<sch[i].stuNum;j++){
                printf("%d",stu[sch[i].id[j]].stuID);
                if(j<sch[i].stuNum-1){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}