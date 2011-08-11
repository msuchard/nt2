/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DSL_INFINITES_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DSL_INFINITES_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Turn some digits consatnt into DSL terminals
////////////////////////////////////////////////////////////////////////////////
#include <boost/proto/proto.hpp>
#include <boost/simd/include/constants/real.hpp>
#include <boost/simd/sdk/constant/category.hpp>

namespace boost { namespace simd
{
  boost::proto::terminal< constant_<tag::inf_ > >::type   inf_  = {{}};
  boost::proto::terminal< constant_<tag::m_inf_> >::type  minf_ = {{}};
} }

#endif