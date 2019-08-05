#include<stdio.h>
char cycl[4][9];
int que[4];
int ch[4];

void turn(int N, int D) {
   ch[N] = 1;
   
   if (N != 3&&ch[N+1]==0) {
      if (cycl[N][(que[N] + 2) % 8] != cycl[N + 1][(que[N + 1] + 6) % 8]) {
         
         turn(N + 1, -D);
         
      }
      
   }
   if (N != 0 && ch[N - 1] == 0) {
      if (cycl[N][(que[N] + 6) % 8] != cycl[N - 1][(que[N - 1] + 2) % 8]) {
         
         turn(N - 1, -D);
         
      }
   }
   que[N] = (que[N] - D + 8) % 8;
   
   return;
   
}
int main() {
   for (int i = 0; i < 4; i++) {
      scanf("%s", &cycl[i]);
   }
   int n, a, b;
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf("%d %d", &a, &b);
      turn(a-1, b);
      memset(ch, 0,4*4);
   }
printf("%d", (cycl[0][que[0]] - 48)*1+ (cycl[1][que[1]] - 48) * 2 + (cycl[2][que[2]] - 48) * 4 + (cycl[3][que[3]] - 48) * 8);
   
   
}
