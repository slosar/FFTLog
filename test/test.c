#include "stdio.h"
#include "fftlog.h"
#define N 1000
#define PK_FNAME "test/pklogspaced.txt"
#define OUTNAME "test_result.txt"
int main() {
  double k[N], Pk[N], r[N], xi[N], k2[N],Pk2[N];
  FILE *fp=fopen(PK_FNAME,"r");
  if (!fp) {
    printf ("Can't open Pk file.\n");
    return 1;
  }
  int fr;
  for (int i=0; i<N; i++) 
    fr=fscanf(fp,"%lf %lf \n",&k[i],&Pk[i]);
  fclose(fp);
  printf ("File read ok.\n");
  printf ("Forward transforming...\n");
  pk2xi(N,k,Pk,r,xi);
  printf ("Backward transforming...\n");
  xi2pk(N,r,xi,k2,Pk2);
  fp=fopen(OUTNAME,"w");
  if (!fp) {
    printf ("Can't open output file.\n");
    return 1;
  }
  fprintf (fp,"# k Pk r xi(r) kback Pk_back(kback)\n");
  for (int i=0; i<N; i++)
    fprintf (fp,"%g %g %g %g %g %g \n", k[i],Pk[i], r[i], xi[i], k2[i], Pk2[i]);
  fclose(fp);
    
}
