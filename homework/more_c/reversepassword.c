#include <stdio.h>
#include <string.h>




void main() {
    char str[5000],x[5000],y[5000];
    
    scanf("%s",str);

    for (int i = 0; str[i] != 'x' ; i++)
    {
        if (str[i]!='\n')    
        {
            x[i]=str[i];
        }
        else 
        {
            i--;
        } 
        //printf("%c",str[i]);
    }
    //printf(" %d ",strlen(str));
    
    int j = 0;
    for (int i = strlen(str); str[i] != 'x' ; i--)
    {
        if (str[i]!='y' && (str[i]!='\n'))   
        {
            y[j]=str[i];
            j++;
        }
        else 
        {
            j = 0;
        } 
        //printf("%c",str[i]);   
    }
    if (strcmp(x,y)==0)
    {
        printf("1");
    }
    else {
        printf("0");
    }
    
    //printf("\n %s %s",x,y);





}