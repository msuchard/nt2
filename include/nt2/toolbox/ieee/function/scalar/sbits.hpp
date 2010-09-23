//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_SBITS_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_SBITS_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_bits.hpp>


namespace nt2 { namespace functors
{

  //  no special validate for sbits

  /////////////////////////////////////////////////////////////////////////////
  // Compute sbits(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<sbits_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {	typedef typename meta::as_integer<A0, signed>::type type;}; 

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::as_bits<A0, signed>::type type; 
      type that = {a0}; 
       return that.bits; 
    }
  };
} }


      
#endif