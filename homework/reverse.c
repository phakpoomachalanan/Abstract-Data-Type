#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100001];
    fgets(str, sizeof str, stdin);
    
    char wordArray[30001][51];

    int j = 0;
    int k = 0;
    for(int i=0;i<=(strlen(str));i++)
    {
        
        if(str[i]==' '||str[i]=='\0'||str[i]=='\n')
        {
            k++;  
            j=0;    
        }
        else
        {
            wordArray[k][j]=str[i];
            j++;
        }
    }
    
    
    for(int i=k;i >= 0 ;i--)
        if (wordArray[i][0] != '\0') {
            printf("%s ",wordArray[i]);
        }
    return 0 ;
}