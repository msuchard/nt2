//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SIMD_COMMON_EXPNI_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SIMD_COMMON_EXPNI_HPP_INCLUDED
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/include/functions/log.hpp>
#include <nt2/include/functions/exp.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/pow.hpp>
#include <nt2/include/functions/gamma.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/is_odd.hpp>
#include <nt2/include/functions/bitwise_ornot.hpp>
#include <nt2/include/functions/nbtrue.hpp>


namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<expni_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0, A1)> : meta::is_real_convertible<A1>{}; 
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute expni(const A0& a0, const A0& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<expni_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0, A1)> : 
      boost::result_of<meta::floating(A1)>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      A1,
      (2, (real_,arithmetic_))
    )
    NT2_FUNCTOR_CALL_EVAL_IF(2,       real_)
    {
      A1 x =  a1|islez(a1);
      const int32_t sn =  a0;
      if( sn == 0 )  return exp(-x)/x;
      if (sn < 0 )   return Nan<A1>(); 
      A1 n = splat<A1>(sn); 
      if (sn  > 5000 )
	{
	  A1 xk = x + n;
	  A1 yk = rec(sqr(xk)); 
	  A1 t = n;
	  A1 ans = yk*t*(Six<A1>()*sqr(x)-Eight<A1>()*t*x+sqr(t));
	  ans = yk*(ans+t*(t-Two<A1>()*x));
	  ans = yk*(ans+t);
	  return oneplus(ans)*exp(-x)/xk;
	}
      A1 r =  Nan<A1>(); 
      A1 test1 = is_le(a1, One<A1>()); 
      int32_t nb = 0; 
      if ((nb = nbtrue(test1)) > 0)
	{
	  A1 xx = sel(test1, x, One<A1>()); 
 	  A1 y1 = case_1(xx, sn);  
	  r = b_ornot(y1, test1);
	  if (nb >= meta::cardinal_of<A1>::value) return r; 	  
	}
      A1 xx = sel(test1, Two<A1>(), x); 
      A1 y2 =  case_2(xx, sn); 
      r &= b_or(y2, test1);
      r =  seladd(islt(x, Maxlog<A1>()), Zero<A1>(), r); 
      return b_or(r, isnan(a1)); // we are done
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,       arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(2)::type type;
      return expni(a0, tofloat(a1));
    }
  private :
    template < class A1 >
    static inline A1 case_1(const A1 & x,  int32_t sn)
    {
      typedef typename meta::scalar_of<A1>::type sA1; 
      /*		Power series expansion		*/
      sA1 psi1 = Zero<sA1>(); 
      for( int32_t i=sn-1; i; --i )  psi1 += rec((sA1)i);
      A1 n = splat<A1>(sn); 
      A1 psi = -Euler<A1>()-nt2::log(x)+splat<A1>(psi1); 
      A1 t; 
      A1 z = -x;
      A1 xk = Zero<A1>();
      A1 yk = One<A1>();
      A1 pk = One<A1>() - n;
      A1 ans = ( sn == 1 ) ? Zero<A1>() : rec(pk); 
      do
	{
	  xk += One<A1>();
	  yk *= z/xk;
	  pk += One<A1>();
	  ans = seladd(isnez(pk), ans, yk/pk);
	  t = sel(isnez(ans), nt2::abs(yk/ans), One<A1>());
	}
      while( any(t > Halfeps<A1>()) );
      t = n;
      A1 r = n - One<A1>();
      return (pow(z, r) * psi / gamma(t)) - ans;
    }
    
    template < class A1 >
    static inline A1 case_2(const A1 & x,  int32_t sn)
    {
      typedef typename meta::scalar_of<A1>::type sA1;
      A1 n = splat<A1>(sn); 
      int32_t sk = 1;
      A1 t; 
      A1 pkm2 = One<A1>();
      A1 qkm2 = x;
      A1 pkm1 = One<A1>();
      A1 qkm1 = x + n;
      A1 ans = pkm1/qkm1;
      do
	{
	  A1 test =  isnez(splat<A1>(is_odd(++sk)));
	  A1 k_2 =  splat<A1>(sk >> 1); 
	  A1 yk = sel(test, One<A1>(), x);
	  A1 xk = seladd(test, k_2, n); 
	  A1 pk = pkm1 * yk  +  pkm2 * xk;
	  A1 qk = qkm1 * yk  +  qkm2 * xk;
	  A1 r = pk/qk;
	  test = isnez(qk); 
	  t = sel(test,nt2::abs((ans-r)/r),One<A1>());
	  ans = sel(test, r, ans);
	  pkm2 = pkm1;
	  pkm1 = pk;
	  qkm2 = qkm1;
	  qkm1 = qk;
	  test = isgt(nt2::abs(pk), Expnibig<A1>());
	  A1 fac = sel(test, Halfeps<A1>(), One<A1>()); 
	  pkm2 *= fac;
	  pkm1 *= fac;
	  qkm2 *= fac;
	  qkm1 *= fac;
	}
      while( any(t > Halfeps<A1>()) );
      return ans*exp(-x);
    }
  };
} }

      
#endif