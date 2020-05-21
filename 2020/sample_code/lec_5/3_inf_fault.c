/*
 *
 * project: hw2
 * name:
 * account: 
 * date: 
 * file: itox.c
 * notes:
 */

#include <stdio.h>

int main(void)
{
    int i=0,j=0, temp;
    int arr[30];
    for (i=0;i<30;i++){
        arr[i] = i;
    }
    while (j < i){
      temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
   }
}