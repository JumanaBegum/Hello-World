#include <stdio.h>
#define max 25
#define inf 9999

int nv,ne,nes;
int graph[max][max];

struct edge{
    int src;
    int dest;
    int weight;
};

struct edge el[max];

void prims(){
    int visited[nv];
    int nes = 0;
    int i,j,x,y,min;
    int tcost = 0;

    for(i=0;i<nv;i++){
        visited[i] = 0;
    }
    visited[0] = 1;//choosing random vertex and assigning to one;
    x = 0;
    y = 0;

    while(nes<nv-1){
        min = inf;
        for(i=0;i<nv;i++){
            if(visited[i]){
                    for(j=0;j<nv;j++){
                        if(!visited[j]&&graph[i][j]){
                            if(min>graph[i][j]){
                                min = graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }

            }
        }
            visited[y] = 1;
            printf("%d->%d : %d\n",x,y,graph[x][y]);
            tcost += graph[x][y];
            nes++;
    }
    printf("\nTHE TOTAL COST OF MINIMUM SPANNING TREE : %d",tcost);

}
void main(){
    int i,j,src,dest;

    printf("\nNO OF VERTICES :");
    scanf("%d",&nv);

    printf("\nNO OF EDGES :");
    scanf("%d",&ne);

    printf("\nENTER THE EDGE SOURCE,DESTINATION AND THE WEIGHT :");
    for(i=0;i<ne;i++){
        scanf("%d %d %d",&el[i].src,&el[i].dest,&el[i].weight);
        src = el[i].src;
        dest = el[i].dest;
        graph[src][dest] = el[i].weight;
        graph[dest][src] = el[i].weight;
    }

    printf("\nADJACENCY MATRIX :");
    for(i=0;i<nv;i++){
        printf("\n");
        for(j=0;j<nv;j++){
            printf("%d\t",graph[i][j]);
        }
    }
    printf("\nMINIMUM SPANNING TREE :\n");
    prims();
}
