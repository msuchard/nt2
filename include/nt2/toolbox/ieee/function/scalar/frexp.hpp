//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_FREXP_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_FREXP_HPP_INCLUDED
#include <boost/mpl/vector.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <boost/fusion/tuple.hpp>


namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<frexp_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : boost::is_floating_point<A0> {};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute frexp(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<frexp_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef typename boost::result_of<meta::floating(A0)>::type mantissa;
      typedef typename meta::as_integer<A0,signed>::type          exponent;
      typedef boost::fusion::tuple<mantissa,exponent>             type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      typedef boost::mpl::vector<float, double> tags;
      typename NT2_CALL_RETURN_TYPE(1)::type res;
      eval( a0
          , boost::fusion::at_c<0>(res)
          , boost::fusion::at_c<1>(res)
          , typename meta::find_type<A0,tags,empty_>::type()
          );
      return res;
    }

  private:
    template<class A0,class R0,class R1> inline void
    eval(A0 const& a0,R0& r0, R1& r1, double const &)const
    {
      int r1t;
      r0 = ::frexp(a0, &r1t);
      r1 = r1t;
    }

    template<class A0,class R0,class R1> inline void
    eval(A0 const& a0,R0& r0, R1& r1, float const &)const
    {
      r0 = ::frexpf(a0, &r1);
    }
  };
} }


      
#endif