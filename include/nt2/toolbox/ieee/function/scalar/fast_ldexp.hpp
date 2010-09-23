//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_FAST_LDEXP_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_FAST_LDEXP_HPP_INCLUDED
#include <nt2/sdk/constant/properties.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/include/functions/bitwise_andnot.hpp>

namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<fast_ldexp_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      		 boost::is_integral<A1> {};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute fast_ldexp(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<fast_ldexp_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0, A1)>
    {
      typedef A0 type;
    };

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      A0,
      (2, (real_,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(2,       real_)
    {
      // No denormal provision
      typedef typename meta::as_integer<A0, unsigned>::type int_type;

//       static int_type const nmb = Nbmantissabits<A0>();
//       static int_type const n1  = ((2*(Maxexponent<A0>()-1)+3) << nmb);

      // clear exponent in x
      A0 const x(b_andnot(a0, Ldexpmask<A0>()));
      // extract exponent and compute the new one
      int_type e    = b_and(Ldexpmask<A0>(), a0);
      e += int_type(a1) << Nbmantissabits<A0>();
      return b_or(x, e);
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2, arithmetic_)
    {
       return (a1>=0)?(a0<<a1):(a0>>a1);
    }
  };
} }


      
#endif