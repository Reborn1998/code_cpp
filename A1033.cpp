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
 * @Date: 2021-07-04 13:29:30
 * @LastEditTime: 2021-07-12 14:30:26
 * @LastEditors: Chenjun Ding
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
struct Station{
    double price;
    double distance;
}station[502];
bool cmp(Station a,Station b){
    return a.distance<b.distance;
}
bool cmp2(Station a,Station b){
    return a.price<b.price;
}
int main(){
    double c,D,d;
    int n;
    scanf("%lf%lf%lf%d",&c,&D,&d,&n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&station[i].price,&station[i].distance);
    }
	station[n].price=0;
    station[n].distance = D;
    sort(station,station+n,cmp);
    if(station[0].distance!=0){
        printf("The maximum travel distance = %.2f",0.0);
        return 0;
    }
    
    double maxd = c*d;
    int idx=0;
    double minc = 9999999999;
    vector<int> index;
    index.push_back(0);
    double mind=station[0].price;
    for(int i=1;i<n;i++){	
        if(station[i].distance-station[index[index.size()-1]].distance<=maxd){
            if(station[i].price<station[index[index.size()-1]].price){
                index.push_back(i);
                continue;
            }
            if(station[i].price<minc){
                idx = i;
                minc = station[i].price; 
            }
            if(i==n-1){
            	if(D-station[index[index.size()-1]].distance<=maxd) break;
                index.push_back(idx);
                break; 
            }
        }else if(i>index[index.size()-1]+1){
        	
            index.push_back(idx);
            i = idx;
            minc = 999999999999;
            
            continue;
        }
       	if(station[i].distance-station[i-1].distance>maxd){
            printf("The maximum travel distance = %.2f",station[i-1].distance+maxd);
            return 0;
        }
    }
    if(D-station[n-1].distance>maxd){
        printf("The maximum travel distance = %.2f",station[n-1].distance+maxd);
        return 0;
    }

    index.push_back(n);
    double sum = 0;
    double residue = 0;
    double total = 0;
    for(int i=0;i<index.size()-1;i++){
        if(station[index[i]].price>station[index[i+1]].price){
            total = (station[index[i+1]].distance-station[index[i]].distance)/d;
            total -= residue;
            total = total<0?0:total;
            sum += total*station[index[i]].price; 
            residue = 0;         
        }else{
            total = c-residue;
            sum += total*station[index[i]].price;
            residue = c - (station[index[i+1]].distance-station[index[i]].distance)/d;
        }
    }
    printf("%.2f",sum);
}


