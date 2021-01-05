#include <stdio.h>
#define max 25

struct edge{
    int src;
    int dest;
    int weight;
};
struct edge el[max];

struct edge_list{
    struct edge data[max];
    int n;
}spanlist;

int graph[max][max],b[max];
int ne,nv;

int find(int v){
    return b[v];
}

void Union(int n1,int n2){
    int i;
    for(i=0;i<nv;i++){
        if(b[i] == n2){
            b[i] = n1;
        }
    }
}

void kruskal(){
    int i,j,c1,c2;
    struct edge temp;

    //sort
    for(i=0;i<ne;i++){
        for(j=i+1;j<ne;j++){
            if(el[i].weight>el[j].weight){
                temp = el[i];
                el[i] = el[j];
                el[j] = temp;
            }
        }
    }
    printf("\nSORTED EDGE LIST : ");
    for(i=0;i<ne;i++){
        printf("\n%d\t%d\t%d\t",el[i].src,el[i].dest,el[i].weight);
    }

    for(i=0;i<nv;i++){
        b[i] = i;
    }

    spanlist.n = 0;

    for(i=0;i<ne;i++){
        c1 = find(el[i].src);
        c2 = find(el[i].dest);

        if(c1!=c2){
                spanlist.data[spanlist.n] = el[i];
                spanlist.n = (spanlist.n) + 1;
                Union(c1,c2);
        }
    }
}

void main(){
    int i,j,src,dest,tcost = 0;
    printf("\nNO OF VERTICES :");
    scanf("%d",&nv);

    printf("\nNO OF EDGES :");
    scanf("%d",&ne);

    printf("\nENTER THE EDGE SRC,DEST AND WEIGHT :");
    for(i=0;i<ne;i++){
        scanf("%d %d %d",&el[i].src,&el[i].dest,&el[i].weight);
        src = el[i].src;
        dest = el[i].dest;
        graph[src][dest] = el[i].weight;
        graph[dest][src] = el[i].weight;

    }

    printf("\nTHE ADJACENCY MATRIX IS :");
    for(i=0;i<nv;i++){
        printf("\n");
        for(j=0;j<nv;j++){
            printf("%d\t",graph[i][j]);
        }
    }

    kruskal();

    printf("\nSPANNING TREE :");
    for(i=0;i<spanlist.n;i++){
        printf("\n%d\t%d\t%d\t",spanlist.data[i].src,spanlist.data[i].dest,spanlist.data[i].weight);
        tcost +=spanlist.data[i].weight;
    }
    printf("\nWEIGHT OF MINIMUM SPANNING TREE : %d",tcost);

}
