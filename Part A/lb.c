#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x<y)?x:y
int main()
{
    int capacity, inp[10] = {0}, count = 0, drop = 0, orate, ch,x, i=0, nsec;
    printf("Enter capacity: \n");
    scanf("%d", &capacity);
    printf("Enter output rate\n");
    scanf("%d",&orate);
    do
    {
        printf("Enter the number of packets coming at %d:  ",(i+1));
        scanf("%d",&inp[i]);
        if(inp[i] > capacity){
            printf("Packet Discarded\n");
            exit(0);
        }
        i++;
        printf("Enter 1 to insert more else insert 0");
        scanf("%d",&ch);
    } while (ch);
    nsec = i;
    printf("Second \t Received \t Sent \t Count \t Drop\n");
    for ( i = 0; i < nsec || count; i++)
    {
        printf("%d\t%d\t%d\t",(i+1),inp[i],MIN(inp[i]+count,orate));
        if((x = inp[i] + count - orate) > 0)
        {
            if(x > capacity)
            {
                count = capacity;
                drop = x - capacity;
            }
            else
            {
                count = x;
                drop = 0;
            }
        }
        else
        {
            count = 0;
            drop = 0;
        }
        printf("%d\t%d\n",drop,count);
    }
    
}