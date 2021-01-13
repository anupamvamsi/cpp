#include<stdio.h>
#include<curses.h>
void main()
{
    FILE *fp;
    char c;
    fp=fopen("try.txt","w");
    printf("Enter data");
    while((c=getchar())!=EOF)
    {
        putc(c,fp);
    }
    fclose(fp);
    fp=fopen("try.txt","r");
    while(c!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
    
}
