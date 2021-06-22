#include<bits/stdc++.h>
using namespace std;
struct Node{
    char ch;
    int next;
}node[100010];
int main(){
    int a,b,n;
    cin>>a>>b>>n;
    for(int i=0;i<n;i++){
        int idx,next;
        char c;
        cin>>idx>>c>>next;
        node[idx].ch = c;
        node[idx].next = next;
    }
    set<int> s;
    while(a!=-1){
        s.insert(a);
        a = node[a].next;
    }
    while(b!=-1){
        set<int>::iterator it = s.find(b);
        if(it!=s.end()){
            cout<<*it<<endl;
            return 0;
        }
        b = node[b].next;
    }
    
    cout<<"-1"<<endl;
}
