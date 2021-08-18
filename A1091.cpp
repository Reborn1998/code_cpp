#include<bits/stdc++.h>
using namespace std;
int n,m,l,t;
int sum=0;
struct Node{
	int x,y,z;
}node;
int pixel[1290][130][61];
bool inq[1290][130][61]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int x,int y,int z){
	if(x>=n||x<0||y>=m ||y<0 ||z>=l||z<0 ) return false;
	if(pixel[x][y][z]==0||inq[x][y][z]) return false;
	return true;
}
int BFS(int x,int y,int z){
	int tot = 0;
	queue<Node> q;
	node.x=x;node.y=y;node.z=z;
	q.push(node);
	inq[x][y][z]=true;
	while(!q.empty()){
		
		Node temp = q.front();
		q.pop();
		tot++;
		for(int i =0;i<6;i++){
			node.x = temp.x+X[i];node.y = temp.y+Y[i];node.z = temp.z+Z[i];
			if(judge(node.x,node.y,node.z)){
				inq[node.x][node.y][node.z]=true;
				q.push(node);
			}	
		}
	}
	if(tot>=t) return tot;
	return 0;

}
int main(){
	scanf("%d%d%d%d",&n,&m,&l,&t);
	for(int z=0;z<l;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				scanf("%d",&pixel[x][y][z]);
			}
		}
	}
	int ans=0;
	for(int z=0;z<l;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(pixel[x][y][z]==1&&!inq[x][y][z]){
					ans+=BFS(x,y,z);		
				}
			}
		}
	}
	printf("%d",ans);
} 
