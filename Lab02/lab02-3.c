#include<stdio.h>
#include<math.h>

int main(void)
{
    int route[] = {0, 0, 0, 0};
    int headTo = 0;
    
    int times;
    scanf("%d", &times);

    char path[times+1];
    scanf("%s", path);

    int ch;
    for (int i=0; i<times; i++)
    {
        ch = path[i];
        switch(path[i])
        {
        case 'R':
            headTo = headTo-1>0 ? (headTo-1)%4 : (headTo+3)%4;
            break;

        case 'L':
            headTo = (headTo+1)%4;
            break;

        case 'F':
            route[headTo] += 1;
            break;
        }
    }
    printf("%.4lf\n", sqrt(pow(route[0]-route[2],2) + pow(route[1]-route[3], 2)));
    
    return 0;
}