#include <stdio.h>

int main()
{
  int n;
  printf("enter the number\n");
  scanf("%d",&n);
  for(int i=0;i<n-1;i++){
      for(int j=1;j<((i+1)*2);j++){
          if((j==1)||j==((i+1)*2)-1)
          printf("*");
          else
          printf(" ");
      }
      printf("\n");
  }
  for(int i=0;i<n;i++){
      printf("* ");
  }

    return 0;
}