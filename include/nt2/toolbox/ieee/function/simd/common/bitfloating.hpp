//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_BITFLOATING_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_BITFLOATING_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/constant/properties.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_gez.hpp>
#include <nt2/include/functions/select.hpp>


namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<bitfloating_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::is_integral<A0>{};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute bitfloating(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<bitfloating_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::as_real<A0>{}; 

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (2, (unsigned,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,    unsigned)
    {
      typedef typename meta::as_real<A0>::type type;
      return simd::native_cast<type>(a0); 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      typedef typename meta::as_real<A0>::type type;
      //A0 s = Signmask<A0>(); 
      //      type that = {sel(isgez(type(a0)), a0, s-a0)};
      type r;
      A0 s = simd::native_cast<A0>(Signmask<type>()); 
      r = sel(isgez(a0)      , simd::native_cast<A0>(a0), simd::native_cast<A0>(s-a0));
      return r; 
    }
  };
} }

      
#endif