/***********************************************************
* You can use all the programs on  www.c-program-example.com
* for personal and learning purposes. For permissions to use the
* programs for commercial purposes,
* contact info@c-program-example.com
* To find more C programs, do visit www.c-program-example.com
* and browse!
*
*                      Happy Coding
***********************************************************/

#include <stdio.h>
int a[20][20];
int q[20];
int visited[20];
int n;
int i;
int j;
int f=0;
int r=-1;
void bfs(int v){
	for(i=1;i<=n;i++){
		if(a[v][i] && !visited[i]){
			q[++r]=i;
		}
	}
	if(f<=r){
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
int main(){
    int v;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        q[i]=0;
        visited[i]=0;
    }
    printf("\n Enter graph data in matrix form:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    bfs(v);
    for(i=1;i<=n;i++){
        if(visited[i]){
            printf("%d\t",i);
        }
        else{
            printf("\n Bfs is not possible");
        }
    }
}