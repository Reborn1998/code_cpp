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
 * @Date: 2021-06-26 14:24:14
 * @LastEditTime: 2021-06-26 14:46:01
 * @LastEditors: Chenjun Ding
 * @Description: 
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
struct Node{
    int x,y;
    int step;
    Node(int a,int b,int c):x(a),y(b),step(c){};
	Node():x(0),y(0),step(0){}; 
}S,T,node;
int n,m;
char maze[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

bool test(int x,int y){
    if(x>n || x<0 || y>m || y<0){
        return false;
    }
    if(inq[x][y]){
        return false;
    }
    if(maze[x][y]=='*') return false;
    return true;
}
int BFS(){
    queue<Node> q;
    q.push(S);
    while(!q.empty()){
        Node temp = q.front();
        q.pop();
        if(temp.x==T.x && temp.y==T.y){
            return temp.step;
        }
        for(int i=0;i<4;i++){
            if(test(temp.x+X[i],temp.y+Y[i])){
                node.x=temp.x+X[i];
                node.y = temp.y+Y[i];
                node.step = temp.step+1;
                q.push(node);
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        getchar();
        for(int j=0;j<m;j++){
            maze[i][j] = getchar();
        }
        maze[i][m+1] = '\0';
    }
    scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
    S.step = 0;
    printf("%d",BFS());
}