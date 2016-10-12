extern "C" {
   #include "fftlog.h"
}

#include "fftlog.hpp"

void FFTLOG::Pk2Xi(const dvector &k,  const dvector &pk, dvector *r, dvector *xi) {
  pk2xi(k.size(),&k[0],  &pk[0], &((*r)[0]), &((*xi)[0]));
}

void Xi2Pk(const dvector &r,  const dvector &xi, dvector *k, dvector *pk) {
  xi2pk (r.size(), &r[0], &xi[0], &((*k)[0]), &((*pk)[0]));
}

void ComputeXiLM(int l, int m, int N, const dvector &k,  const dvector &pk, dvector *r, dvector *xi) {
  fftlog_ComputeXiLM(l,m,N, &k[0],  &pk[0], &((*r)[0]), &((*xi)[0]));
		     
}
void Fht(dvector &r,  cdvector &a, dvector *k, cdvector *b, double mu,
         double q, double kcrc, bool noring, cdvector* u) {
  // let's hope this works
  double __complex__ *a_ = reinterpret_cast<double __complex__*> (&a[0]);
  double __complex__ *b_ = reinterpret_cast<double __complex__ *> (&((*b)[0]));
  double __complex__ *u_ = reinterpret_cast<double __complex__ *> (&((*u)[0]));
  fht(r.size(), &r[0], a_, &((*k)[0]), b_,mu,q,kcrc,(int)(noring), u_);
}

void Compute_u_coefficients(int N, double mu, double q, double L, double kcrc, cdvector* u) {
  double __complex__ *u_ = reinterpret_cast<double __complex__ *> (&((*u)[0]));
  compute_u_coefficients(N,mu,q,L,kcrc,u_);
}
