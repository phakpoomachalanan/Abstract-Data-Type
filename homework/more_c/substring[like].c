#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int length, searchLength, tolerance;
    scanf("%d %d %d",&length,&searchLength,&tolerance);
    
    char *text,*searchText;
    text = (char *)malloc(sizeof(char)*length);
    searchText = (char *)malloc(sizeof(char)*searchLength);

    scanf("%s",text);
    scanf("%s",searchText);
    
    char *searching;
    searching = (char*)malloc(sizeof(char)*searchLength);
    char *temp;
    temp = (char*)malloc(sizeof(char)*searchLength);
    for (int i = 0; i < length; i++)
    {
        int tolerated = 0;
        if (i <= length-searchLength) {
            for (int j = 0; j < searchLength; j++)
            {
                searching[j] = text[j+i];
                temp[j] = text[j+i];
                
                if (searching[j]!=searchText[j]) {
                    tolerated++;
                    if (tolerated>tolerance) {
                        
                        printf("%c",temp[0]);
                        break;
                    }
                    else {
                        searching[j] = '?';
                    }
                } 
            }
            if (tolerated<=tolerance) {
                printf("[%s]",searching);
                i += searchLength-1;
            }
        }
        else {
            printf("%c",text[i]);
        }
        
    }
    
    return 0;
}