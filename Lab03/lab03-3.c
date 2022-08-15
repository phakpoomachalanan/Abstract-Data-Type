#include <stdio.h>

void printFromLastWord();

int main(void)
{
    printFromLastWord();
    printf("\n");

    return 0;
}

void printFromLastWord()
{ 
    char word[50];
    scanf("%s", word);
    if (fgetc(stdin) == '\n')
    {
        printf("%s ", word);
        return;
    }
    
    printFromLastWord();
    printf("%s ", word);
}