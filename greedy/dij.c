#include <stdio.h>
#define max 25
#define inf 9999
float w[max][max] = {0.0};
struct edge{
    int src;
    int dest;
    float weight;
};
struct edge el[max];
void dijkstras(int n,int start,int end){
    float cost[n][n],distance[n];
    int pre[n];
    int visited[n];
    int i,j,next;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(w[i][j]==0.0){
                cost[i][j] = inf;
            }
            else{
                cost[i][j] = w[i][j];
            }
        }
    }
    for(i=0;i<n;i++){
        distance[i] = cost[start][i];
        pre[i] = start;
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    int count = 0;

    while(count<n-1){
        int min = inf;
        for(i=0;i<n;i++){
            if(distance[i]<(min)&&!(visited[i])){
                min = distance[i];
                next = i;
            }
        }
        visited[next] = 1;
        for(i=0;i<n;i++){
            if(!visited[i]){
                if(min+cost[next][i]<distance[i]){
                    distance[i] = min+cost[next][i];
                    pre[i] = next;
                }
            }
        }
        count++;
    }
   for (i = 0; i < n; i++){
   if (i != start) {
     printf("\nDistance from source to %d: %f", i, distance[i]);
   }
}
    printf("\nDISTANCE OF %d to %d is %f\n",start,end,distance[end]);
}
void main(){
    int i,j,n,e,src,dest,weight,start,end;

    printf("\nENTER THE NUMBER OF VERTICES :");
    scanf("%d",&n);
    printf("\nENTER THE NUMBER OF EDGES :");
    scanf("%d",&e);

    printf("\nENTER THE EDGE LIST AND WEIGHT :");
    for(i=0;i<e;i++){
        scanf("%d %d %f",&el[i].src,&el[i].dest,&el[i].weight);
        src = el[i].src;
        dest = el[i].dest;
        weight = el[i].weight;
        w[src][dest] = weight;
    }

    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%.1f\t",w[i][j]);
        }
    }
    printf("\nenter the start and end node :");
    scanf("%d %d",&start,&end);
    dijkstras(n,start,end);

}
