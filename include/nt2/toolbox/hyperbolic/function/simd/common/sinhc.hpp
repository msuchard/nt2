//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_HYPERBOLIC_FUNCTION_SIMD_COMMON_SINHC_HPP_INCLUDED
#define NT2_TOOLBOX_HYPERBOLIC_FUNCTION_SIMD_COMMON_SINHC_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/sinh.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/fma.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/toolbox/hyperbolic/function/scalar/constants.hpp>
#include <nt2/sdk/constant/eps_related.hpp>


namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<sinhc_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      meta::is_real_convertible<A0>{};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute sinhc(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<sinhc_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>: meta::as_real<A0>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (2, (real_,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,       real_)
    {
      A0 a = abs(a0); 
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type;
      A0 r1 = sinh(a)*rec(a);
      A0 a2 = sqr(a); 
      A0 r2 = oneplus(a2*fma(a2, Oneo_120<A0>(), Oneo_6<A0>()));
      return sel(isge(a,Four<A0>()*Four<A0>()*Forthrooteps<A0>()), r1, r2); 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type; 
      return sinhc(type(a0));
    }
  };
} }

      
#endif