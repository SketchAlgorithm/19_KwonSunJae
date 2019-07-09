#include <stdio.h>

int main() {
   int n;
   int tree[100000] = { 0, };
   scanf("%d", &n);
   int cnt = 1;

   while (n) {
      int cases, aim, max=0;
      scanf("%d %d", &cases, &aim);
      for (int i = 0; i < cases; i++) {
         scanf("%d", &tree[i]);
         if (max < tree[i]) max = tree[i];
      }
      for (int i = 0; i < max; i++) {
      	int sum=0;
         for (int j = 0; tree[j] != 0; j++) {
            if (i >= tree[j])continue;
            else {
            	sum+=tree[j]-i;
            }
         }
         if(sum==aim)printf("#%d %d",cnt,i);
         else if(i==max-1)printf("#%d %d",cnt,i);
      }
   }
}
