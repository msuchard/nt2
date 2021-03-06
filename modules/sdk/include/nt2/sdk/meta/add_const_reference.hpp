//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_META_ADD_CONST_REFERENCE_HPP_INCLUDED
#define NT2_SDK_META_ADD_CONST_REFERENCE_HPP_INCLUDED

#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_reference.hpp>

namespace nt2 { namespace meta
{
  template<typename T>
  struct  add_const_reference
        : boost::add_reference< typename boost::add_const<T>::type >
  {};
} }

#endif
