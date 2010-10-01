//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EULER_FUNCTION_GAMMALN_HPP_INCLUDED
#define NT2_TOOLBOX_EULER_FUNCTION_GAMMALN_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/euler/include.hpp>

namespace nt2 { namespace functors
  {	       
    struct gammaln_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(functors::gammaln_, gammaln, 1)
}
 
#include <nt2/toolbox/euler/function/scalar/gammaln.hpp>
#include NT2_EULER_INCLUDE(gammaln.hpp) 

 
#endif