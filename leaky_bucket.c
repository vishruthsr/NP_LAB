#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x
int main()
{
    int orate , drop =0,cap,x,count=0,inp[10]={0},i=0,nsec,ch;
    printf("\nENTER BUCKET SIZE : ");
    scanf("%d",&cap);
    printf("\nENTER OUTPUT RATE : ");
    scanf("%d",&orate);
    do
    {
        printf("\nENTER THE NUMBER OF PACKETSS COMING AT SECOND %d :",i+1);
        scanf("%d",&inp[i]);
        if(inp[i] > cap)
        {
            printf("BUCKET OVERFLOW \n");
            printf("PACKET DISCARDED\n");
            exit(0);
        }
        i++;
        printf("\nenter\n1.to continue \n0.to quit\n");
        scanf("%d",&ch);
    }while(ch);
    nsec = i;
    printf("\n SECOND \t RECEIVED \t SEND \t DROPPED \t TREMAINED \n ");
    for(i=0;count || i<nsec;i++)
    {
        printf(" %d",i+1);
        printf("\t\t%d\t",inp[i]);
        printf("\t%d\t",MIN((inp[i] + count),orate));
        if((x=inp[i] + count - orate) > 0)
        {
            if(x>cap)
            {
                count = cap;
                drop = x-cap;
            }
            else
            {
                count = x;
                drop=0;
            }
        }
        else
        {
            drop =0;
            count=0;
        }
        printf("\t%d\t%d",drop,count);
        printf("\n");
    }
    return 0;
}
