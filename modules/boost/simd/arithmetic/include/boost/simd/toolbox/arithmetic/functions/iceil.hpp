//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_ICEIL_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_ICEIL_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_arithmetic
 * \defgroup iceil iceil function
 *
 * \par Description
 * return a value of integer type of the same size and signedness than the entry.
 * The value returned is the smallest integer greater or equal to the entry
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/iceil.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::iceil_(A0)>::type
 *     iceil(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of iceil
 * 
 * \return an integer value
 *  
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *  
**/

namespace boost { namespace simd { namespace tag
  {         
    /*!
     * \brief Define the tag iceil_ of functor iceil 
     *        in namespace boost::simd::tag
    **/
    struct iceil_ {};
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::iceil_, iceil, 1)
} }

#endif

// modified by jt the 25/12/2010
