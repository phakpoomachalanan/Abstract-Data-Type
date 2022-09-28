#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 69420

typedef struct numArray
{
    int *arr;
    int pos;
} numArray_t;

int main() {
    char x[MAXSIZE],y[MAXSIZE];
    scanf("%s",&x);
    scanf("%s",&y);
    numArray_t X = {NULL, 0};
    X.arr = (int*)malloc(sizeof (int) * MAXSIZE);
    numArray_t Y = {NULL, 0};
    Y.arr = (int*)malloc(sizeof (int) * MAXSIZE);
    
    int bigger=strlen(x)-1;
    //printf("%d\n",strlen(x));
    //printf("%d\n",strlen(y));
    if (strlen(x)>strlen(y)) {
        bigger = strlen(x)-1;
        for (int i = 0; i < strlen(x)-strlen(y); i++)
        {
            Y.arr[i] = 0;
            Y.pos++;
        }
    }
    
    if (strlen(x)<strlen(y)) {
        bigger = strlen(y)-1;
        for (int i = 0; i < strlen(y)-strlen(x); i++)
        {
            X.arr[i] = 0;
            X.pos++;
        }    
    }
    //printf("%d\n",X.pos);
    //printf("%d\n",Y.pos);
    for (int i = X.pos; i <= bigger ; i++)
    {
        X.arr[i] = (int)x[i-X.pos]-48;
    }
    for (int i = Y.pos; i <= bigger ; i++)
    {
        Y.arr[i] = (int)y[i-Y.pos]-48;
    }
    /*
    for (int i = 0; i <= bigger; i++)
    {
        printf("%d",X.arr[i]);
    }
    printf("\n");
    for (int i = 0; i <= bigger; i++)
    {
        printf("%d",Y.arr[i]);
    }
    printf("\n");*/
    numArray_t Sum = {NULL, 0};
    Sum.arr = (int*)malloc(sizeof (int) * bigger);
    int leftover = 0;
    
    for (int i = bigger; i >=0 ; i--)
    {
        int digitSum = X.arr[i]+Y.arr[i]+leftover;
        if (i!=0) {
            if (digitSum>9) { 
                Sum.arr[i] = digitSum%10;
                leftover = 1;
            }
            else {
                Sum.arr[i] = digitSum;
                leftover = 0;
            }
        }
        else {
            Sum.arr[i] = digitSum;
        }
    
    }
    
    for (int i = 0; i <= bigger ; i++)
    {
        printf("%d",Sum.arr[i]);
    }
    
}
