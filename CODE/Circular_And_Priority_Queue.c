#include <stdio.h>
#include<stdlib.h>

int q[100],cq[100];
struct pd{
    int data;
    int pri;
}pq[100];

int front=-1,rear=1,cfront=0,crear=0,pfront=-1,prear=-1;


void pushcq(int l){
    int it;
    printf("Enter element: ");
    scanf("%d",&it);
    if(cfront==(crear+1)%l)
    printf("Queue is full\n");
    else
    {
        crear=(crear+1)%l;
        cq[crear]=it;
        
    }
}

int popcq(int l){
    if(cfront==crear)
    printf("queue is empty\n");
    else
    {
        cfront=(cfront+1)%l;
        return cq[front];
        
    }
}

void displaycq(int l){
    int i=(cfront+1)%l;
    while(i!=(crear+1)%l)
    {
        printf("%d\t",cq[i]);
        i=(i+1)%l;
        
    }
    printf("\n");
}

void pushpq(int l){
    int item,prio;
    struct pd temp;
    
    if(prear>=l-1)
    printf("Queue is full\n");
    else
    {
    printf("Enter element: \n");
    scanf("%d",&item);
    printf("Enter priority: \n");
    scanf("%d",&prio);
    prear++;
    pq[prear].data=item;
    pq[prear].pri=prio;
    for(int i=prear;i>=pfront;i--)
    {
        if(pq[i].pri>pq[i-1].pri){
            temp=pq[i];
            pq[i]=pq[i-1];
            pq[i-1]=temp;
            
        }
    }
    }
}

void poppq(){
    if(pfront==prear)
    printf("Queue empty\n");
    else
    pq[++pfront];
    
}


void displaypq(){
    printf("\t Element \t| \t Priority\t\n");
    for(int i=pfront-1;i<prear-1;i++)
    printf("\t %d \t| \t %d\t\n", pq[i].data,pq[i].pri);
    
}



void cqueue(int n){
    int c;
    int limit=n;
    printf("1.Push\n2.Pop\n3.Display\nAny other to exit\n");
    while(1){
        printf("Enter the choice: ");
        scanf("%d",&c);
        switch(c){
            case 1: 
            pushcq(limit);
            break;
            case 2:
            popcq(limit);
            break;
            case 3:
            displaycq(limit);
            break;
            default:
            return;
            
        }
    }
}

void pqueue(int n){
    int c;
    int limit=n;
    printf("1.Push\n2.Pop\n3.Display\nAny other to exit\n");
    while(1){
        printf("Enter the choice: ");
        scanf("%d",&c);
        switch(c){
            case 1: 
            pushpq(limit);
            break;
            case 2:
            poppq();
            break;
            case 3:
            displaypq();
            break;
            default:
            return;
            
        }
    }
}

void main(){
    int op;
    printf("1.Circular queue\n2.Priority queue\n3.Exit\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1: 
        int nc;
        printf("Enter the size of Circular queue: ");
        scanf("%d",&nc);
        cqueue(nc);
        break;
        case 2:
        int np;
        printf("Enter the size of Priority queue: ");
        scanf("%d",&np);
        pqueue(np);
       
    }
}
