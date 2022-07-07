#include<stdio.h>
#include<string.h>

char frames[1024];

void receive()
{
    int i = 0,framelen,lpvar;
    char leninchar;
    printf("\nThis is receiver\n");
    printf("Data received is %s", frames);
    while (frames[i] != '\0')
    {
        
        leninchar = frames[i];
        framelen = (int)leninchar - (int)'0';
        printf("\nLength of frame is: %d\n",framelen);
        printf("Frames->  ");
        lpvar = i + framelen;
        i++;
        while (i <= lpvar)
        {
            /* code */
            printf("%c",frames[i++]);
        }
        printf("\n");
    }
    
}

int main()
{
    int n,i,len;
    char buffer[256],length[10];
    bzero(buffer,256);
    printf("Enter the number of frames: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        printf("Enter frame: ");
        scanf("%s",buffer);
        len = strlen(buffer);
        // len++;
        sprintf(length,"%d",len);
        strcat(frames,length);
        strcat(frames,buffer);
    }
    for(i = 0; frames[i] != '\0'; i++)
    {
        printf("%c",frames[i]);
    }
    receive();
}