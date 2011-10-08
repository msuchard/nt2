//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_DETAILS_OF_SIZE_META_HPP_INCLUDED
#define NT2_CORE_SETTINGS_DETAILS_OF_SIZE_META_HPP_INCLUDED

#include <cstddef>
#include <boost/dispatch/meta/fusion.hpp>
#include <nt2/core/container/category.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <nt2/core/container/meta/is_block.hpp>
#include <boost/dispatch/meta/hierarchy_of.hpp>

namespace boost { namespace dispatch { namespace meta
{
  //============================================================================
  // value_of a of_size_ is simply ptrdiff_t
  //============================================================================
  template< BOOST_PP_ENUM_PARAMS( NT2_MAX_DIMENSIONS, std::ptrdiff_t D) >
  struct value_of< nt2::of_size_<BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS, D)> >
  {
    typedef std::ptrdiff_t type;
  };

  //============================================================================
  // hierarchy_of a of_size_ is mapped over the one of array as it's basically
  // a std::array with a funky interface.
  //============================================================================
  template< BOOST_PP_ENUM_PARAMS( NT2_MAX_DIMENSIONS, std::ptrdiff_t D)
          , class Origin
          >
  struct hierarchy_of < nt2::of_size_<BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS,D)>
                      , Origin
                      >
  {
    typedef nt2::of_size_<BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS,D)> base;    
    static const std::size_t size = base::static_size ? base::static_size : 1;

    typedef typename property_of<std::ptrdiff_t, Origin>::type    property_type;
    typedef array_<property_type, size>                           base_hierarchy;
    typedef container_< base_hierarchy, nt2::of_size_<1, size> >  type;
  };
} } }

namespace nt2 { namespace container
{
  //============================================================================
  // of_size_ is a block
  //============================================================================
  template< BOOST_PP_ENUM_PARAMS( NT2_MAX_DIMENSIONS, std::ptrdiff_t D) >
  struct is_block< nt2::of_size_<BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS, D)> >
    : boost::mpl::true_
  {};
} }

#endif