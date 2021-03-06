[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'type_defs' : [],
         'types' : ['real_', 'integer_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 18/02/2011',
             'included' : [],#"#include <nt2/include/functions/shli.hpp>"],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 18/02/2011',
            },
         'ranges' : {
             'default' : [
                [['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2']],
                ],
            },
         'specific_values' : {
             'default' : {
                 'nt2::One<T>()' : {'result' : 'nt2::shli(nt2::Mone<r_t>(),1)','ulp_thresh' : '0',},
                 'nt2::Three<T>()' : {'result' : 'nt2::shli(nt2::Mone<r_t>(),2)','ulp_thresh' : '0',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Mone<r_t>()','ulp_thresh' : '0',},
                },
             'integer_' : {
                 'nt2::Mone<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0',},
                 'nt2::One<T>()' : {'result' : 'nt2::shli(nt2::Mone<r_t>(),1)','ulp_thresh' : '0',},
                 'nt2::Three<T>()' : {'result' : 'nt2::shli(nt2::Mone<r_t>(),2)','ulp_thresh' : '0',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Mone<r_t>()','ulp_thresh' : '0',},
                },
             'real_' : {
                 'nt2::Nan<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'integer_' : ['nt2::complement(a0)'],
                },
             'property_value' : {
                 'integer_' : ['T(~a0)'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'integer_' : ['0'],
                },
            },
        },
    },
]
