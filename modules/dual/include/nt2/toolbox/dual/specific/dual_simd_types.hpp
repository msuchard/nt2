/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_DUAL_SPECIFIC_DUAL_SIMD_TYPES_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_SPECIFIC_DUAL_SIMD_TYPES_HPP_INCLUDED



namespace nt2
{
  /// simd version
  template<class T,  class X>
  class dual < simd::native < T, X > > 
  {
  public:
    typedef typename simd::native<T,X>                          type;
    typedef typename meta::scalar_of<type>::type                part; 
    typedef dual<type>                                          self;
    typedef self                                            floating;
    typedef typename boost::fusion::tuple<type, type>           pair;
    typedef meta::dual_<typename meta::hierarchy_of<type>::type> nt2_hierarchy_tag;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  Normal form constructor.
    ///
    /// This constructor produces an uninitialized dual
    ////////////////////////////////////////////////////////////////////////////
    dual() {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor - nothing special
    ////////////////////////////////////////////////////////////////////////////
    ~dual() {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from an other dual.
    ///
    /// constructor from an other dual.
    ///
    /// @param z the dual to be copied
    ////////////////////////////////////////////////////////////////////////////
    dual(const self& z)
      : mhilo(z.mhilo) {}

    dual(const pair& z)
      : mhilo(z) {}

 
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from two IEEE
    ///
    /// constructor from a  two real
    /// 
    /// @param a the hi part
    /// @param b the lo part  (default 0)
    ////////////////////////////////////////////////////////////////////////////
    explicit dual(const type& a,  const type& b) : mhilo(boost::fusion::make_tuple(a, b)) {}
    explicit dual(const type& a) : mhilo(boost::fusion::make_tuple(a, Zero<type>())) {}

//     dual(const double& a){
//       hi() = static_cast < type > (a); 
//       lo() = static_cast < type > (a-static_cast<double>(hi())); 
//       //        std::cout <<  std::setprecision(15) << a << std::endl;
//       //        std::cout <<  std::setprecision(7)  << mhi <<  " -- " << mlo <<  std::endl;
//     }

//     dual(const float& a): mhilo(boost::fusion::make_tuple(a, Zero<type>())){}

//    explicit dual(const int&a): mhilo(boost::fusion::make_tuple(type(a), Zero<type>())) {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  affectation from an other dual.
    ///
    /// affectation from an other dual.
    ///
    /// @param src the dual to be assigned
    ////////////////////////////////////////////////////////////////////////////
    self& operator=( const self& src)
    {
      if (&src !=  this)
	{
	  mhilo = src.mhilo;
	}
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi const hi part accessor
    ///
    /// hi hi part accessor.
    ////////////////////////////////////////////////////////////////////////////
    const type& hi() const { return boost::fusion::get<0>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  lo const lo part accessor
    ///
    /// lo lo part accessor.
    ////////////////////////////////////////////////////////////////////////////
    const type& lo() const { return boost::fusion::get<1>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi hi part accessor
    ///
    /// hi hi part accessor.
    ////////////////////////////////////////////////////////////////////////////
    type& hi()       { return boost::fusion::get<0>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  lo lo part accessor
    ///
    /// lo lo part accessor.
    ////////////////////////////////////////////////////////////////////////////
    type& lo()       { return boost::fusion::get<1>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hilo const pair accessor
    ///
    /// hilo accessor.
    ////////////////////////////////////////////////////////////////////////////
    const pair& hilo() const { return mhilo; }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hilo part accessor
    ///
    /// hilo accessor.
    ////////////////////////////////////////////////////////////////////////////
    pair& hilo()       { return mhilo; }

    void print() const
    {
      std::cout << "(" << hi() << ", " << lo() << ")" << std::endl;
    }
    void print(const char* m) const
    {
      std::cout << m << " = (" << hi() << ", " << lo() << ")" << std::endl;
    }
//     ////////////////////////////////////////////////////////////////////////////
//     /// @brief  ! true if non 0
//     ////////////////////////////////////////////////////////////////////////////
//     bool operator!()           const { return (!mhi() && !mlo());       }

//     ////////////////////////////////////////////////////////////////////////////
//     /// @brief  ! logical complement
//     ////////////////////////////////////////////////////////////////////////////
//     self operator~()           const { return self(~mhi, ~mlo);         }
    
//     ////////////////////////////////////////////////////////////////////////////
//     /// @brief  - unary minus
//     ////////////////////////////////////////////////////////////////////////////
//     self operator-()           const { return self(-mhi,-mlo);          }

//     bool isnan()    const { return nt2::is_nan(mhi) || nt2::is_nan(mlo); }
//     bool isfin()    const { return nt2::is_finite(mhi); }
//     bool isinf()    const { return nt2::is_inf(mhi); }
//     bool iseqz()    const { return nt2::is_eqz(hi());}
//     bool isone()    const{return (hi() == One<part>() && lo() == Zero<part>()); }
//     bool isgtz()    const{return (hi() > Zero<part>());}
//     bool isltz()    const{return nt2::is_ltz(hi());}

//     self operator&  (const self& b) const  { return self(mhi & b.mhi, mlo & b.mlo); }
//     self operator|  (const self& b) const  { return self(mhi | b.mhi, mlo | b.mlo); }
//     self operator^  (const self& b) const  { return self(mhi ^ b.mhi, mlo ^ b.mlo); }
//     self operator<< (const int & i) const  { return self(mhi << i, mlo << i);       }
//     self operator>> (const int & i) const  { return self(mhi >> i, mlo >> i);       }    
//     bool operator== (const self& b) const  { return (hi() == b.hi() && lo() == b.lo());       }
//     bool operator!= (const self& b) const  { return (hi() != b.hi() || lo() != b.lo());}
//     bool operator<  (const self& b) const  { return (hi() <  b.hi() || (hi() == b.hi() && lo() <  b.lo()));}
//     bool operator>  (const self& b) const  { return (hi() >  b.hi() || (hi() == b.hi() && lo() >  b.lo()));}
//     bool operator<= (const self& b) const  { return (hi() <  b.hi() || (hi() == b.hi() && lo() <= b.lo()));}
//     bool operator>= (const self& b) const  { return (hi() >  b.hi() || (hi() == b.hi() && lo() >= b.lo()));} 
//     bool operator&& (const self& b) const  { return (mhi || mlo) && b; }
//     bool operator|| (const self& b) const  { return (mhi || mlo || b); }

//     bool operator== (const type& b) const { return (hi() == b && lo() == Zero<part>()); };
//     bool operator!= (const type& b) const { return (hi() != b || lo() != Zero<part>());}
//     bool operator<  (const type& b) const { return (hi() < b || (hi() == b && lo() < Zero<part>()));       }
//     bool operator>  (const type& b) const { return (hi() > b.hi() || (hi() == b.hi() && lo() < b.lo()));   }
//     bool operator<= (const type& b) const { return (hi() < b || (hi() == b && lo() <= Zero<part>()));}
//     bool operator>= (const type& b) const { return (hi() > b || (hi() == b && lo() >= Zero<part>()));          }
//     bool operator&& (const type& b) const { return (mhi || mlo)  && (b.mhi || b.mlo); };
//     bool operator|| (const type& b) const { return (mhi || mlo || b.mhi || b.mlo); };

//     self operator*  (const type& b) const; 
//     self operator/  (const type& b) const;
//     self operator+  (const self& b) const;  
//     self operator-  (const self& b) const; 
//     self operator*  (const self& b) const; 
//     self operator/  (const self& b) const;
//     ////////////////////////////////////////////////////////////////////////////
//     /// @brief  - abs
//     ////////////////////////////////////////////////////////////////////////////
//     self abs()
//     {
//       if(mhi < 0) {mhi = -mhi;  mlo = -mlo; };
//       return *this; 
//     }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type += 
    ///
    /// @param a value to be added
    ////////////////////////////////////////////////////////////////////////////
    self& operator+=(const type& a)
    {
      pair s = two_sum(hi(), a);
      bf::get<1>(s) += lo();
      hilo() = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      return *this;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type += 
    ///
    /// @param a value to be added
    ////////////////////////////////////////////////////////////////////////////
    self& operator+=(const self& a)
    {
      pair s = two_sum(hi(), a.hi());
      pair t = two_sum(lo(), a.lo());
      bf::get<1>(s) += bf::get<0>(t); 
      s = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      bf::get<1>(s) += bf::get<1>(t);
      hilo() = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type -= 
    ///
    /// @param a value to be substracted
    ////////////////////////////////////////////////////////////////////////////
    self& operator-=(const type&a)
    {
      pair s = two_diff(hi(), a);
      bf::get<1>(s) += lo();
      hilo() = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      return *this; 
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type -= 
    ///
    /// @param a value to be substracted
    ////////////////////////////////////////////////////////////////////////////
    self& operator-=(const self& a)
    {
      pair s = two_diff(hi(), a.hi());
      pair t = two_diff(lo(), a.lo());
      bf::get<1>(s) += bf::get<0>(t); 
      s = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      bf::get<1>(s) += bf::get<1>(t);
      hilo() = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      return *this;
    }


    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type *= 
    ///
    /// @param a value to be multiplicated by
    ////////////////////////////////////////////////////////////////////////////
    self& operator*=(const type& a)
    {
      pair p = two_prod(hi(), a);
       bf::get<1>(p) += lo()*a;
      hilo() = quick_two_sum(bf::get<0>(p), bf::get<1>(p));
      return *this;
     }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type *= 
    ///
    /// @param a value to be multiplicated by
    ////////////////////////////////////////////////////////////////////////////
    self& operator*=(const self& a)
    {
      type p2;
      pair p = two_prod(hi(), a.hi());
      bf::get<1>(p) += a.lo() * hi();
      bf::get<1>(p) += a.hi() * lo();
      bf::get<1>(p) += a.lo() * lo();
      hilo() = quick_two_sum(bf::get<0>(p), bf::get<1>(p));
      return *this;
     }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type / 
    ///
    /// @param b value to be divided by
    ////////////////////////////////////////////////////////////////////////////
    self div(const self& b)const; 
    self div(const type& b)const; 
      
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type /= 
    ///
    /// @param s value to be divided by
    ////////////////////////////////////////////////////////////////////////////
    self& operator/=(const T& a)
    {
      return *this = *this / self(a);
    }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type /= 
    ///
    /// @param s value to be divided by
    ////////////////////////////////////////////////////////////////////////////
    self& operator/=(const self& a)
    {
      return *this = (*this)/ a;
    }
    
//     ////////////////////////////////////////////////////////////////////////////
//     /// @brief  normalization 
//     ///
//     /// @param s value to be divided by
//     ////////////////////////////////////////////////////////////////////////////
//     self& normalize()
//     {
//       std::cout << " normalize " << hi() <<  "  " << lo() <<  std::endl; 
//       if ( nt2::abs(hi())*Eps<type>() <  nt2::abs(lo()) ) mlo = Zero<type>();
//       std::cout << " normalize2 " << hi() <<  "  " << lo() <<  std::endl; 
//       return *this; 
//     }


    // /////////////////////////////////////////////////////////////////////////
    // static members
    ////////////////////////////////////////////////////////////////////////////
    
//     static self abs     (const self &a){return (a.hi() < 0) ? -a : a; }
//     static self sqr     (const self &a) { return a*a;                        }
//     static self aint    (const self &a) { return (a.hi() >= Zero<part>()) ? floor(a) : ceil(a);}
//     static type to_type (const self &a) { return a.hi();}
//     static int  to_int  (const self &a) { return static_cast<int>(a.hi());}
//     static self rec     (const self &a){return One<part>() / a;}
//     /* double-double * (2.0 ^ exp) */
//     static self ldexp   (const self  &a, const int& exp) { return self (nt2::ldexp(a.hi(), exp), nt2::ldexp(a.lo(), exp)); }
//     /* Cast to double. */
//     static double to_double(const self &a) { return a.hi();}
//     static void error   (const char *msg) { if (msg) { std::cerr << "ERROR " << msg << std::endl; } }
//     static const self& one(){static self z(1, 0);  return z; }
//     static const self& zero(){static self z(0, 0);  return z; }
//     static const self& nan (){static self z(Nan<type>(),Nan<type>());  return z; }
//     static const self& inf (){static self z(Inf<type>(),Zero<type>());  return z; }
    
  private:
    mutable pair mhilo; //perhaps normalization capability is not useful
    //    int read(const char *s);
    

  };
  

}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_simd_types.hpp
// /////////////////////////////////////////////////////////////////////////////
