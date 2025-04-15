#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
      /* Write the logic to reverse the array. */
      int temp;
      for(int i=num-1,j=0;i>j;i--,j++){
            temp=*(arr+j);
            *(arr+j)=*(arr+i);
            *(arr+i)=temp;
      }

 for(i = 0; i < num; i++)
        printf("%d ", *(arr+ i));
 
    return 0;
}