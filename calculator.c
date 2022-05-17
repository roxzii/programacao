#include <stdio.h>
int main()
{
   float num1, num2, sum, sub, mult, div;
   scanf("%f%f", &num1, &num2);

   sum = num1 + num2;
   sub = num1 - num2;
   mult = num1 * num2;
   div = num1 / num2;

   printf("A soma é %f, a subtração é %f, a multiplicação é %f e a divisão é %f\n", sum, sub, mult, div);

   return 0;
}
