//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 boost_math toolbox - sph_neumann/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of boost_math components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/boost_math/include/sph_neumann.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<sph_neumann_> from boost_math
//////////////////////////////////////////////////////////////////////////////
using nt2::boost_math::tag::sph_neumann_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sph_neumann_,(RS(iT,iT(0),iT(10)))(RS(T,T(0),T(10))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sph_neumann_,(RS(iT,iT(0),iT(10)))(RS(T,T(0),T(10))))
}

#undef RS