#include <stdlib.h>
#include <stdio.h>


long trachtenberg_3(int);


int main(int argc, char** argv)
{
  int multiplicande = atoi(argv[1]);

  long res = trachtenberg_3(multiplicande);

  printf("res = %ld  | %d\n", res, multiplicande*3);
  
}

long trachtenberg_3(int x)
{
  int n=1;
  int y=x;
  while(y>10)
    {
      y/=10;
      n++;
    }

  int c[n];
  int mod=10;
  int div=1;
  for(int i =0; i<n; i++)
    {
      c[i]=x%mod/div;
      printf("c: %d\n",c[i]);
      mod*=10;
      div*=10;
    }

  int cp[n+1];
  int ret;

  cp[0] = (10-c[0])*2;
  if (c[0] % 2 == 1)
    cp[0] += 5;
  ret = cp[0] / 10;
  cp[0] %= 10;

  for (int i = 1; i < n; i++)
    {
      cp[i] = (9-c[i])*2 + (c[i-1]/2);
      if (c[i] % 2 == 1)
	cp[i] += 5;
      cp[i]+=ret;
      ret = cp[i] / 10;
      cp[i] %= 10;
    }
  cp[n] = c[n-1]/2-2+ret;

  
  /* int resultat = di*10000 + (m * 1000) + (c * 100) + (d * 10) + u; */

  int d=1;
  long resultat=0;
  for(int i =0; i<n+1; i++)
    {
      resultat += cp[i]*d;
      d*=10;
    }
      
  return resultat;

}
