/*ADITHYADEV S
S2DS
EXPERIMENT 1*/
#include<stdio.h>
void main()
{
    int op,i,j,num,search,arr[50],left=0,right=0,mid=0,flag=0,flag2=0;
    printf("Enter option (1 or 2\n1.LINEAR SEARCH\n2.BINARY SEARCH\nENTER THE CHOICE : ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
    printf("Enter the number of elments : ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);    
    }
    printf("Enter the number to search : ");
    scanf("%d",&search);
    for(i=0;i<num;i++)
    {
        if (arr[i]==search)
        {
            flag=i;
            flag2=1;
            break;
        }
    }
    if(flag2==1)
    {
        printf("%d is in position %d !\n",search,flag);
    }
    else
    {
        printf("ELEMENT %d NOT FOUND LOL !\n",search);
    }
    
    case 2:
     printf("Enter the number of elements : ");
     scanf("%d",&num);
     printf("Enter the elements in ascending order : \n");
     for(i=0;i<num;i++)
     {
          printf("Enter the element %d : ",i+1);
          scanf("%d",&arr[i]);
     }
     printf("Enter the element to search : ");
     scanf("%d",&search);
     
     left=0;
     right=num-1;
     
     
     while(mid!=search)
     {
          mid=((left+right)/2);
          if(search<arr[mid])
          {
               right=mid-1;
          }
          else if(search==arr[mid])
          {
               flag=mid;
               break;
          }
          else
          {
               left=mid+1;
          }
     }
     
     printf("POSITION : %d",mid);
    }
     
}
