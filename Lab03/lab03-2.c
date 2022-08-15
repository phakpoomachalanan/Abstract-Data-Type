#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m, p, n;
    int diff;
    int flag;
    char *str;
    char *sub;
    char *temp;

    scanf("%d %d %d", &m, &p, &n);

    str = (char *)malloc(sizeof(char) * m);
    scanf("%s", str);
    sub = (char *)malloc(sizeof(char) * p);
    scanf("%s", sub);
    temp = (char *)malloc(sizeof(char) * p);

    for (int i=0; i<m; i++)
    {
        diff = 0;
        flag = 1;
        if (i < m-p+1)
        {
            for (int j=0; j<p; j++)
            {
                temp[j] = str[i+j];
                if (str[i+j] != sub[j])
                {
                    diff++;
                    temp[j] = '?';
                    if (diff > n)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                printf("[%s]", temp);
                i += p-1;
            }
            else
            {
                printf("%c", str[i]);
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    
    return 0;
}