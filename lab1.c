#include <stdio.h>
const int I0 = 22;
const int J0 = 10;
const int L0 = 10;
struct 
{  int stepNow;
   int stepNext;
   } StepsI,StepsJ,StepsL;
int Moudle (int a) {
   return (a > 0) ? a : -a;
}
int Max (int a, int b) {
   return (a > b) ? a : b;
}
int Sign (int a) {
   return (a != 0) ? a/Moudle(a) : 0;
}
int Min (int a, int b) {
   return (a > b) ? b : a;
}
int MoveI (int i, int j, int l, int k) {
   return Min(l%5, (i*k)%5) + j + k/3;
}
int MoveJ (int i, int j, int l) {
   return Max(-3*i, 2*j)/5 - Moudle(j-l);
}
int MoveL (int i, int j, int l, int k) {
   return j + l%7 + (k*Sign(i))%10;
}
int HitCheck (int i, int j) {
   return (((-5 >= j && j >= -15) && (5 <= i && i <= 15)) == 0) ? 0 : 1; 
}
int main(void) {
   StepsI.stepNow = I0,StepsJ.stepNow = J0,StepsL.stepNow = L0;
   int stepNow = 0;
   while ((stepNow < 50) && (HitCheck(StepsI.stepNow,StepsJ.stepNow) == 0)) {
      StepsI.stepNext = MoveI(StepsI.stepNow, StepsJ.stepNow, StepsL.stepNow, stepNow);
      StepsJ.stepNext = MoveJ(StepsI.stepNow, StepsJ.stepNow, StepsL.stepNow);
      StepsL.stepNext = MoveL(StepsI.stepNow, StepsJ.stepNow, StepsL.stepNow, stepNow);
      StepsI.stepNow = StepsI.stepNext;
      StepsJ.stepNow = StepsJ.stepNext;
      StepsL.stepNow = StepsL.stepNext;
      stepNow ++;
   }
      if (stepNow < 50) {
         printf("Попал на шаге %d i = %d, j = %d, l = %d \n", stepNow, StepsI.stepNow, StepsJ.stepNow, StepsL.stepNow);
      } else {
         printf("Не попал,i = %d, j = %d, l = %d \n", StepsI.stepNow, StepsJ.stepNow, StepsL.stepNow);
      }
   return 0;
}