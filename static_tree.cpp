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
 * @Date: 2021-06-26 15:19:07
 * @LastEditTime: 2021-06-26 15:19:07
 * @LastEditors: Chenjun Ding
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct node{
    int weight;
    vector<int> child;
}Node[maxn];


bool cmp(int a,int b){
    return Node[a].weight > Node[b].weight;
}
int n,m,s;
int Path[maxn];
void DFS(int index,int numNode,int sum){
    if(sum>s) return;
    if(sum==s){
        if(Node[index].child.size()!=0) return;
        for(int i=0;i<numNode;i++){
            printf("%d",Node[Path[i]].weight);
            if(i<numNode-1) printf(" ");
            else printf("\n");
        }
        return ;
    }
    for(int i=0;i<Node[index].child.size();i++){
        int child = Node[index].child[i];
        Path[numNode] = child;
        DFS(child,numNode+1,sum+Node[child].weight);
    }
    
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&Node[i].weight);
    }
    for(int i=0;i<m;i++){
        int id,k,child;
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(),Node[id].child.end(),cmp);
    }
    Path[0] = 0;
    DFS(0,1,Node[0].weight);
}