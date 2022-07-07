#include<stdio.h>
#include<string.h>

void receiver(int *res, int n)
{
    int l1,l2,i,count = 0;
    l1 = n - 8;
    printf("Received message is: \n");
    for(i = 8; i < l1; i++)
    {
        if(res[i] == 0)
        {
            if(count == 5){
                i++;
                count = 0;
            }
            printf("%d",res[i]);
        }
        else
        {
            printf("%d", res[i]);
            count++;
        }
    }
    printf("\n");
}

void sender()
{
    int msg[50], res[50];
    int i,j,n,zero = 0,zerocount=0,count;
    printf("Enter the number of bits\n");
    scanf("%d",&n);
    printf("Enter bits\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&msg[i]);
    }
    res[0] = 0;
    res[1] = 1;
    res[2] = 1;
    res[3] = 1;
    res[4] = 1;
    res[5] = 1;
    res[6] = 1;
    res[7] = 0;
    j = 8;
    for(i = 0; i < n; i++)
    {
        if(msg[i] == 0)
        {
            res[j] = msg[i];
            j++;
            count = 0;
            zero = 1;
        }
        else
        {
            if(count == 5 && zero == 1)
            {
                res[j] = 0;
                j++;
                zerocount++;
            }
            res[j] = msg[i];
            j++;
            count++;
        }
    }
    res[j++] = 0;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 0;
    int size = n + zerocount + 16;
    printf("Size of frame is %d\n", size);
    printf("Frame is: \n");
    for(i = 0; i < j; i++)
    {
        printf("%d",res[i]);
    }
    printf("\n");
    receiver(res,j);
}
int main()
{
    sender();
}