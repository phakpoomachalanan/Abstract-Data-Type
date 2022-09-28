#include <stdio.h>
#include <stdlib.h>


typedef struct playerStats {
    int *playerHP;
    int playerNum;
} playerStats_t;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    playerStats_t list = {NULL,0};
    list.playerHP = (int*)malloc(sizeof(int)*n);
    
    int i = 0;
    char newline; 
    do {
        scanf("%d%c", &list.playerHP[i++], &newline);
        list.playerNum++;
    } while (newline != '\n' && i < n);
    
    list.playerNum = 0;
    int count = 1;
    int drunk = 0;
    
    while (drunk<n-1)
    {
        //printf("num %d HP %d                     current number %d\n",list.playerNum+1,list.playerHP[list.playerNum],count);
        if (count%k==0 && list.playerHP[list.playerNum]!=-2) {
            if (list.playerHP[list.playerNum] > -1) {  
                list.playerHP[list.playerNum] = list.playerHP[list.playerNum] - 1;
                //printf("num %d took a shot, %d HP left\n",list.playerNum+1,list.playerHP[list.playerNum]);
            }
            if (list.playerHP[list.playerNum] == -1) {
                list.playerHP[list.playerNum] = -2;
                drunk++; 
                //printf("num %d is drunk\n",list.playerNum+1);
                count++;
            }
            
        }       
        if (list.playerHP[list.playerNum]!=-2)
            count++;

        list.playerNum++;
        if (list.playerNum>n-1)
            list.playerNum = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (list.playerHP[i]!=-2)
        {
            printf("%d",i+1);
            break;
        }
        
    }
    
    return 0;
}
