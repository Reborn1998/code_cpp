#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y;
}node;
int matrix[100][100];
bool inq[100][100] = {false};
int n,m;
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};
bool judge(int x,int y){
	if(x>=n || x<0 || y>=m || y<0) return false;
	if(matrix[x][y]==0 || inq[x][y]) return false;
	return true;
}
void BFS(int x,int y){
	queue<Node> q;
	node.x = x;
	node.y = y;
	q.push(node);
	inq[x][y] = true; //第一个节点也要标记 
	while(!q.empty()){
		Node temp = q.front();
		q.pop(); 
		for(int i=0;i<4;i++){
			int newX = temp.x+X[i];
			int newY = temp.y+Y[i];
			if(judge(newX,newY)){
				Node newnode;
				newnode.x = newX;
				newnode.y = newY;
				q.push(newnode);
				inq[newX][newY] = true;
			}
		}
	}
}
int main(){

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==1 && !inq[i][j]){
				cnt++;
				BFS(i,j);
			}
		}
	}
	printf("%d",cnt);
} 
