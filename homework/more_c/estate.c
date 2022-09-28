#include <stdio.h>
#include <math.h>
int count = 0;

int squares2POWN(int w,int l) {
    if (w == 0|| l == 0)
        return 0;
    int biggest = 0;
    int shortestSide;
    if (w>l){
        shortestSide = l;
    } 
    else {
        shortestSide = w;
    }
    
    for (int n = 0; pow(2,n)<=shortestSide ; n++) 
    {
        biggest = pow(2,n);
    }
    printf("%d %d %d (%d)\n",w,l,biggest,count);
    
    int wRemain = w-biggest;
    
    int lRemain = l-biggest;
    
    if (biggest!=0) {
        count++;
    }
    if (wRemain > 0 && biggest > 0) { 
        //go down
        //printf("down\n");
        squares2POWN(wRemain,l); 
    }
    if (lRemain > 0 && biggest > 0) { 
        //go right
        //printf("right\n");
        squares2POWN(lRemain,biggest); 
    }
}

int main() {
    int width,length;
    scanf("%d %d",&width,&length);
    squares2POWN(width,length);
    printf("%d",count);
    return 0;
}
//big oh notation is O(nlogn).