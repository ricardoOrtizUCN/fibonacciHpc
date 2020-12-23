/*
 * Copyright 2020 Ricardo Ortiz, ricardo.ortiz@alumnos.ucn.cl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom
 *  the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/**
*
* Fibonacci
*@author Ricardo Ortiz-Hidalgo
*/

//method that calculates the fibonacci
int fibonacci(int n) {
   int i, j;
   if (n<2)
      return n;
   else {
      #pragma omp task shared(i)
      i=fibonacci(n-1);
      #pragma omp task shared(j)
      j=fibonacci(n-2);
      #pragma omp taskwait
      return i+j;
   }
}

// The main method
int main(int argc, char **argv){
   int valor = 2;
   int n, resultado;

   char *a = argv[1];
   n = atoi(a);
   
   #pragma omp parallel
   {
      #pragma omp single
      {
          for(int i = 0; i<=n;i++)
          {
              result = fibonacci(n);
              
              result= fibonacci(i);
              printf("fibonacci de (%d) %d =",i,result);
              if(result<5)
              {
                  printf("%d\n",result); 

              }else
              {
                  while (result != 1)
                  {
                      if(result%valor==0)
                      {
                          printf("%d",valor);
                          result=result/valor;
                          if (result != 1)
                          {
                              printf("X");
                          }
                          
                      }else
                      {
                          valor++;
                      }
                      
                  }

                  valor = 2;
                  printf("\n");
                  
              }
              factoredFibonacci(result);

              newResult= factoredFibonacci(result);
              printf("FIB(%d) = %ld\n", i,newResult);
          }
          
      }

      
   }
   printf("Result is %d\n", result);
}

//method that calculates the factored fibonacci series
void factoredFibonacci(int numFibonacci) {
    int div = 2;

    if (numFibonacci <= 5) {
        printf("%d", numFibonacci);

    } else {
        while (numFibonacci != 1) {

            if (numFibonacci % div == 0) {
                printf("%d ", div);
                numFibonacci = numFibonacci / div;

                if (numFibonacci != 1)
                    printf("x ");

            } else {
                div++;
            }
        }
    }
}

