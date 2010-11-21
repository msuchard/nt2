//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_GSL_SPECFUN_FUNCTION_SCALAR_GSL_SF_CONICALP_0_HPP_INCLUDED
#define NT2_TOOLBOX_GSL_SPECFUN_FUNCTION_SCALAR_GSL_SF_CONICALP_0_HPP_INCLUDED

namespace nt2 { namespace functors
{
  extern "C"{
    extern double gsl_sf_conicalP_0 ( double, double, double);
  }
  template<class Info>
  struct validate<gsl_specfun::gsl_sf_conicalP_0_,tag::scalar_(tag::arithmetic_),Info>
    {
      template<class Sig> struct result;
      template<class This,class A0, class A1, class A2>
      struct result<This(A0, A1, A2)> :
         meta::has_smaller_size<A0,long double>{};
    };
  /////////////////////////////////////////////////////////////////////////////
  // Compute gsl_sf_conicalP_0(const A0& a0, const A1& a1, const A2& a2)
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is float
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<gsl_specfun::gsl_sf_conicalP_0_,tag::scalar_(tag::arithmetic_),float,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1, class A2>
    struct result<This(A0, A1, A2)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(3){ return gsl_sf_conicalP_0(a0, a1, a2); }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is double
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<gsl_specfun::gsl_sf_conicalP_0_,tag::scalar_(tag::arithmetic_),double,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1, class A2>
    struct result<This(A0, A1, A2)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(3){ return gsl_sf_conicalP_0(a0, a1, a2); }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<gsl_specfun::gsl_sf_conicalP_0_,tag::scalar_(tag::arithmetic_),arithmetic_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1, class A2>
    struct result<This(A0, A1, A2)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(3)
    {
      typedef typename NT2_CALL_RETURN_TYPE(3)::type type;
      return nt2::gsl_specfun::gsl_sf_conicalP_0(type(a0), type(a1), type(a2));
    }
  };

} }

#endif
/// Revised by jt the 16/11/2010