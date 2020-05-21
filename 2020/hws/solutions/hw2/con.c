#include <stdio.h>

void print(char s[], int q);
void num2q(int num, char num_q[], int q);
int q2num(char num_q[], int q);
void f2b(float f, char fb[]);
float b2f(char fb[]);

void print(char s[], int q){
  printf(" %2d-string: ", q);
  for (int i=0;s[i]; i++){
    if (!((i)%4)&&i!=0) printf("|");
    printf("%c", s[i]);
  }
  printf("\n");
}




void num2q(int num, char num_q[], int q){
  
  if (!num) { 
       num_q[0] = '0';
       num_q[1] = 0;

  }else {
    int rem,i=0, j=0;
    while (num > 0){
      rem = num % q;
      num = num / q;
      if (rem < 10)
        num_q[i++] = rem - 0 + '0';
      else 
        num_q[i++] = rem - 10 + 'A';
    }
    num_q[i--] = '\0';

    while (j < i){
      rem = num_q[j];
      num_q[j] = num_q[i];
      num_q[i] = rem;
      j++;
      i--;
    }
  }

}

int q2num(char num_q[], int q){

  int num=0, i = 0;
  while (num_q[i]){
    if (num_q[i] <= 'Z' && num_q[i] >= 'A')
      num = num * q +num_q[i++] - 'A' + 10;
    else
      num = num * q + num_q[i++] - '0';
  }
  return num;
}


/* function converts float f into binary string */
void f2b(float f, char fb[]){

  int num = (int) f;
  float frac = f - num;
  num2q(num, fb, 2);
  int i=0, j=0; float prod;
  while (fb[i]) i++;
  fb[i++] = '.';

  do {
      prod =  frac * 2;
      num = (int) prod;
      if (num)
        fb[i++] = '1';
      else
        fb[i++] = '0';
      frac = prod - num;
      j++;
  }while(frac && j<8);
  fb[i] = '\0';


}


float b2f(char fb[]){
  int i=0;
  float f = 0.0f, frac = 1.0f;
  while ( '.' != fb[i] ){
    f = f*2+fb[i++] - '0';
  }
  i++;
  while (fb[i]){
    frac = frac/2.0f;
    f = f + frac * (fb[i++]-'0');
  }
  return f;
}


void bin_char(unsigned n, char s[]) 
{ 
    
    unsigned i, j=0; 
    for (i = 1 << 31; i > 0; i = i / 2) {
        s[j++] = (n & i)?  '1' : '0';
    }
    s[j] = 0;
}