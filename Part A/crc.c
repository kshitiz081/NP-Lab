#include<stdio.h>

int min(int a, int b)
{
    return a == b ? 0 : 1;
}

int main()
{
    int data[20], datalen, div[20], divlen, crc[5], remd[5],newdata[20], newdatalen, i, j, k,recdata[20];
    printf("Enter data length\n");
    scanf("%d", &datalen); 
    printf("Enter data\n");
    for(i = 0; i < datalen; i++)
    {
        scanf("%d", &data[i]); 
    }
    printf("Enter divisor length\n");
    scanf("%d", &divlen); 
    printf("Enter divisor\n");
    for(i = 0; i < divlen; i++)
    {
        scanf("%d", &div[i]); 
    }    
    printf("New data is\n");
    for(i = 0; i < datalen+divlen-1; i++)
    {
        if(i < datalen)
        {
            newdata[i] = data[i];
        }
        else
        {
            newdata[i] = 0;
        }
        printf("%d",newdata[i]);
    }
    printf("\n");
    for(j = 0; j < datalen; j++)
    {
        for(i = 0; i < divlen; i++)
        {
            crc[i] = newdata[i+j];
            if(crc[0] == 1)
            {
                newdata[i+j] =  min(newdata[i+j],div[i]);
            }
            else
            {
                newdata[i+j] =  min(newdata[i+j],0);
            }
        }
    }
    printf("The transferred data is\n");
    for(i = 0; i < datalen+divlen-1; i++)
    {
        newdata[i] = min(data[i],newdata[i]);
        printf("%d",newdata[i]);
    }

    printf("Enter the data received\n");
    for ( i = 0; i < datalen+divlen-1; i++)
    {
        scanf("%d",&recdata);
    }
     for(j = 0; j < datalen; j++)
    {
        for(i = 0; i < divlen; i++)
        {
            remd[i] = recdata[i+j];
            if(remd[0] == 1)
            {
                recdata[i+j] =  min(recdata[i+j],div[i]);
            }
            else
            {
                recdata[i+j] =  min(recdata[i+j],0);
            }
        }
        k = 0;
        for ( i = 0; i < divlen-1; i++)
        {
            if(remd[i] == 0) k++;
        }
        
    }
    if(k == 0){
        printf("No Error\n");
    }
    else{
        printf("Error is there");
    }
}