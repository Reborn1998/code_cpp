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
 * @Date: 2021-07-24 21:23:44
 * @LastEditTime: 2021-07-25 10:51:50
 * @LastEditors: Chenjun Ding
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct Car{
    char id[10];
    int time;
    char status[4];
}car[maxn],tcar[maxn];
int hms2s(int h,int m,int s){
    return 60*60*h+60*m+s;
}
void s2hms(int sum,int& h,int& m,int& s){
    h = sum/3600;
    m = (sum%3600)/60;
    s = (sum%3600%60);
}

bool cmp(Car a,Car b){
    if(strcmp(a.id,b.id)){
        return strcmp(a.id,b.id)<0;
    }
    return a.time<b.time;
}
bool cmp2(Car a,Car b){
    return a.time<b.time;
}
map<string,int> parkTime;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    int h,m,s;
    char state[4];
    int num=0;
    for(int i=0;i<n;i++){
        scanf("%s %d:%d:%d %s",car[i].id,&h,&m,&s,car[i].status);  
        car[i].time = hms2s(h,m,s);
    }
    sort(car,car+n,cmp);
    int maxTime=-1;
    for(int i=0;i<n-1;i++){
        if(!strcmp(car[i].id,car[i+1].id)
        && !strcmp(car[i].status,"in")
        && !strcmp(car[i+1].status,"out")){
            tcar[num++] = car[i];
            tcar[num++] = car[i+1];
            int inTime = car[i+1].time - car[i].time;
            if(parkTime.count(car[i].id)==0){
                parkTime[car[i].id] = 0;
            }
            parkTime[car[i].id] += inTime;
            maxTime = max(maxTime,parkTime[car[i].id]);
        }
    }
    sort(tcar,tcar+num,cmp2);
    int now=0,numCar=0;
    for(int i=0;i<k;i++){
        scanf("%d:%d:%d",&h,&m,&s);
        int t = hms2s(h,m,s);
        while(now<num && tcar[now].time<=t){
            if(!strcmp(tcar[now].status,"in")){
                numCar++;
            }else{
                numCar--;
            }
            now++;
        }
        printf("%d\n",numCar);
    }
    map<string,int>::iterator it;
    for(it=parkTime.begin();it!=parkTime.end();it++){
        if(it->second==maxTime){
            printf("%s ",it->first.c_str());
        }
    }
    s2hms(maxTime,h,m,s);
    printf("%d:%d:%d",h,m,s);
}