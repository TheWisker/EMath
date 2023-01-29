$doxydocs=
{
  classes => [
    {
      name => 'emth::Arithmetic',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'emath.h'
      },
      all_members => [
        {
          name => 'get_divisors',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Arithmetic'
        }
      ],
      public_static_methods => {
        members => [
          {
            kind => 'function',
            name => 'get_divisors',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gets the all the positive divisors for an integer. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'n'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The integer to get the divisors for. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'v'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The vector reference where to store the divisors. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'static void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'n',
                type => 'int'
              },
              {
                declaration_name => 'v',
                type => 'std::vector< int > &'
              }
            ]
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Class with some functions for arithmetic math. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'The class consists of the functions that operate with real numbers. '
          }
        ]
      }
    },
    {
      name => 'emth::Monomial',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'emath.h'
      },
      all_members => [
        {
          name => 'coeff',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'emth::Monomial'
        },
        {
          name => 'degree',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'emth::Monomial'
        },
        {
          name => 'get_coeff',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'get_degree',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'get_expression',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'get_value',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'Monomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'Monomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'Monomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'Monomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator!=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator%',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator%=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator*',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator*=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator+',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator+=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator-',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator-=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator/',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator/=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator<',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator<<',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator<<',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator<=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator==',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator>',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'operator>=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        },
        {
          name => 'swap',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'emth::Monomial'
        },
        {
          name => '~Monomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Monomial'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Monomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Default constructor for when initialized with no arguments. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Monomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Normal constructor for initialization with coeff and degree. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'cf'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The coefficient as a double. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'dgr'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The degree as a integer. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'cf',
                type => 'const double'
              },
              {
                declaration_name => 'dgr',
                type => 'const int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Monomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Copy constructor for when initialized with an lvalue '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => ' object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The lvalue '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Monomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Move constructor for when initialized with an rvalue '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => ' object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The rvalue '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'Monomial &&'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Assigment operator overload for when called with an lvalue. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The lvalue '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Move assigment operator overload for when called with an rvalue. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The rvalue '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'Monomial &&'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator==',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Equal logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' objects coefficients and degrees match. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' objects coefficients and degrees dont match. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator!=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Not equal logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' objects coefficients and degrees dont match. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' objects coefficients and degrees match. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator>',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Greater than logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is greater than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is equal or less than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator<',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Less than logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is less than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is equal or greater than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator>=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Greater or equal than logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is greater or equal than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is less than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator<=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Less or equal than logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is less or equal than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is greater than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator+',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Addition operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to add. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator-',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Substraction operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to substract by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator*',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Multiplication operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to multiply by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator/',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Division operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to divide by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator%',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Modulus operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to divide by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator+=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Addition assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to add. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator-=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Substraction assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to substract by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator*=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Multiplication assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to multiply by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator/=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Division assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to divide by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator%=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Modulus assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to divide by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Monomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'get_degree',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Getter function for getting the degree of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(int) The degree of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'int',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'get_coeff',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Getter function for getting the coefficient of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(double) The coefficient of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'double',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'get_expression',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Getter function for getting the expression of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(std::string) The expression of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'std::string',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'get_value',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Calculus function for getting the value of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => ' at a point. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The point to evaluate. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(double) The result of the evaluation of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Monomial',
                      content => 'Monomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'double',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'x',
                type => 'const double &'
              }
            ]
          },
          {
            kind => 'function',
            name => '~Monomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The class destructor. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'swap',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The swap function for the copy-and-swap idiom implemented by the assigment operators. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The other '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' to swap the data with. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'Monomial &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'coeff',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The coefficient of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {},
            type => 'double'
          },
          {
            kind => 'variable',
            name => 'degree',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The degree of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {},
            type => 'int'
          }
        ]
      },
      friend_methods => {
        members => [
          {
            kind => 'friend',
            name => 'operator<<',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'A friend operator to insert the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => ' into a std::stringstream. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ss'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The std::stringstream. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'm'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to insert. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(std::stringstream&) A reference to the std::stringstream. '
                    }
                  ]
                }
              ]
            },
            type => 'friend std::stringstream &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ss',
                type => 'std::stringstream &'
              },
              {
                declaration_name => 'm',
                type => 'const Monomial &'
              }
            ]
          },
          {
            kind => 'friend',
            name => 'operator<<',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'A friend operator to insert the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => ' into a std::ostream. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The std::ostream. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'm'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Monomial',
                          content => 'Monomial'
                        },
                        {
                          type => 'text',
                          content => ' object to insert. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(std::ostream&) A reference to the std::ostream. '
                    }
                  ]
                }
              ]
            },
            type => 'friend std::ostream &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'out',
                type => 'std::ostream &'
              },
              {
                declaration_name => 'm',
                type => 'const Monomial &'
              }
            ]
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Class for representing and operating monomials. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'The class consists of the constructors, the operators, the getters, the properties and some private functions. '
          }
        ]
      }
    },
    {
      name => 'emth::Polynomial',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'emath.h'
      },
      all_members => [
        {
          name => 'get_degree',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'get_derivative',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'get_expression',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'get_integral',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'get_monomials',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'get_value',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'monomials',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator!=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator%',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator%=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator*',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator*=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator+',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator+=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator-',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator-=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator/',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator/=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator<',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator<<',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator<<',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator<=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator==',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator>',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'operator>=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'Polynomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'Polynomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'Polynomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'Polynomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'Polynomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'Polynomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        },
        {
          name => 'redux',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'emth::Polynomial'
        },
        {
          name => 'swap',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'emth::Polynomial'
        },
        {
          name => '~Polynomial',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'emth::Polynomial'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Polynomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Default constructor for when initialized with no arguments. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Polynomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Normal constructor for initialization with a std::map<int, Monomial> '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mns'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The std::map<int, Monomial>. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mns',
                type => 'const std::map< int, Monomial >'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Polynomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'List constructor for initialization with a std::initializer_list<Monomial> '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mns'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The std::initializer_list<Monomial>. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mns',
                type => 'const std::initializer_list< Monomial >'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Polynomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Vector constructor for initialization with a std::vector<Monomial> '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mns'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The std::vector<Monomial>. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mns',
                type => 'const std::vector< Monomial >'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Polynomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Copy constructor for when initialized with an lvalue '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => ' object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The lvalue '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Polynomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Move constructor for when initialized with an rvalue '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => ' object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The rvalue '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'Polynomial &&'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Assigment operator overload for when called with an lvalue. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The lvalue '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Move assigment operator overload for when called with an rvalue. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The rvalue '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'Polynomial &&'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator==',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Equal logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' objects degrees and monomials match. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' objects degrees and monomials dont match. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator!=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Not equal logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' objects degrees and monomials dont match. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' objects degrees and monomials match. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator>',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Greater than logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is greater than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is equal or less than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator<',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Less than logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is less than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is equal or greater than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator>=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Greater or equal than logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is greater or equal than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is less than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator<=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Less or equal than logic operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to compare to. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(true) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is less or equal than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => '(false) If the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' object degree is greater than the degree of the passed '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator+',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Addition operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to add. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator-',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Substraction operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to substract by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator*',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Multiplication operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to multiply by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator/',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Division operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to divide by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator%',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Modulus operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to divide by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ') A brand new '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ' that represents the result. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator+=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Addition assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to add. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator-=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Substraction assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to substract by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator*=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Multiplication assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to multiply by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator/=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Division assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to divide by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator%=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Modulus assigment operator overload. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to divide by. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '&) A reference to the lvalue of the operation. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'get_degree',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Getter function for getting the degree of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(int) The degree of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'int',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'get_monomials',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Getter function for getting the monomials of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(std::map<int, Monomial>) The monomials of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'std::map< int, Monomial >',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'get_expression',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Getter function for getting the expression of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(std::string) The expression of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'std::string',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'get_value',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Calculus function for getting the value of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => ' at a point. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The point to evaluate. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(double) The result of the evaluation of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'double',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'x',
                type => 'const double &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'get_derivative',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Calculus function for getting the derivative of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ') The result of the derivative of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'get_integral',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Calculus function for getting the integral of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '('
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => ') The result of the integral of the '
                    },
                    {
                      type => 'url',
                      link => 'classemth_1_1Polynomial',
                      content => 'Polynomial'
                    },
                    {
                      type => 'text',
                      content => '. '
                    }
                  ]
                }
              ]
            },
            type => 'Polynomial',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => '~Polynomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The class destructor. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'swap',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The swap function for the copy-and-swap idiom implemented by the assigment operators. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ogn'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The other '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' to swap the data with. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ogn',
                type => 'Polynomial &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'redux',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The redux function for removing the Monomials of zero coefficient. '
                }
              ]
            },
            detailed => {},
            type => 'Polynomial &',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'monomials',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The monomials of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => ' as a std::map<int, Monomial> where the key is the degree of the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Monomial',
                  content => 'Monomial'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {},
            type => 'std::map< int, Monomial >'
          }
        ]
      },
      friend_methods => {
        members => [
          {
            kind => 'friend',
            name => 'operator<<',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'A friend operator to insert the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => ' into a std::stringstream. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ss'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The std::stringstream. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'm'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to insert. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(std::stringstream&) A reference to the std::stringstream. '
                    }
                  ]
                }
              ]
            },
            type => 'friend std::stringstream &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ss',
                type => 'std::stringstream &'
              },
              {
                declaration_name => 'p',
                type => 'const Polynomial &'
              }
            ]
          },
          {
            kind => 'friend',
            name => 'operator<<',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'A friend operator to insert the '
                },
                {
                  type => 'url',
                  link => 'classemth_1_1Polynomial',
                  content => 'Polynomial'
                },
                {
                  type => 'text',
                  content => ' into a std::ostream. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The std::ostream. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'm'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The '
                        },
                        {
                          type => 'url',
                          link => 'classemth_1_1Polynomial',
                          content => 'Polynomial'
                        },
                        {
                          type => 'text',
                          content => ' object to insert. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(std::ostream&) A reference to the std::ostream. '
                    }
                  ]
                }
              ]
            },
            type => 'friend std::ostream &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'out',
                type => 'std::ostream &'
              },
              {
                declaration_name => 'p',
                type => 'const Polynomial &'
              }
            ]
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Class for representing and operating polynomials. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'The class consists of the constructors, the operators, the getters, the properties and some private functions. '
          }
        ]
      }
    }
  ],
  concepts => [
  ],
  namespaces => [
    {
      name => 'emth',
      classes => [
        {
          name => 'emth::Arithmetic'
        },
        {
          name => 'emth::Monomial'
        },
        {
          name => 'emth::Polynomial'
        }
      ],
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Englobes all the classes and functions of the emath library. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'The emth namespace contains three classes: Arithmetic, Monomial and Polynomial. The first contains functions for arithmetic operations. The last two are wrappers on abstract algebraic concepts. '
          }
        ]
      }
    }
  ],
  files => [
    {
      name => 'emath.h',
      includes => [
        {
          name => 'map'
        },
        {
          name => 'cmath'
        },
        {
          name => 'complex'
        },
        {
          name => 'vector'
        },
        {
          name => 'string'
        },
        {
          name => 'set.h'
        }
      ],
      included_by => [
        {
          name => 'src/emath.cpp',
          ref => 'src_2emath_8cpp'
        },
        {
          name => 'test/emath.cpp',
          ref => 'test_2emath_8cpp'
        }
      ],
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This is the main header file for the emath library. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This file declares the functions of the emath library.'
          },
          {
            type => 'linebreak'
          },
          {
            type => 'text',
            content => 'It consists of two classes, the Monomial class and the Polynomial class.'
          },
          {
            type => 'linebreak'
          },
          {
            type => 'text',
            content => 'The Monomial class declares all the functions, operators, and properties for representing and operating monomials.'
          },
          {
            type => 'linebreak'
          },
          {
            type => 'text',
            content => 'The Polynomial class declares all the functions, operators, and properties for representing and operating polynomials.'
          },
          {
            type => 'linebreak'
          }
        ]
      }
    },
    {
      name => 'emath.cpp',
      includes => [
        {
          name => 'emath.h',
          ref => 'emath_8h'
        }
      ],
      included_by => [
      ],
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This is the main source file for the mathematical equation operations. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This file implements the functions declared in '
          },
          {
            type => 'url',
            link => 'emath_8h',
            content => 'emath.h'
          },
          {
            type => 'text',
            content => '.'
          },
          {
            type => 'linebreak'
          },
          {
            type => 'text',
            content => 'It consists of two classes, the Monomial class and the Polynomial class.'
          },
          {
            type => 'linebreak'
          },
          {
            type => 'text',
            content => 'The Monomial class implements all the functions, operators, and properties for representing and operating monomials.'
          },
          {
            type => 'linebreak'
          },
          {
            type => 'text',
            content => 'The Polynomial class implements all the functions, operators, and properties for representing and operating polynomials.'
          },
          {
            type => 'linebreak'
          }
        ]
      }
    },
    {
      name => 'emath.cpp',
      includes => [
        {
          name => 'cassert'
        },
        {
          name => 'iostream'
        },
        {
          name => 'emath.h',
          ref => 'emath_8h'
        }
      ],
      included_by => [
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'test_monomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Runs all the monomial class tests. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(int) Returns 0 to specify to Meson that the tests finished correctly '
                    }
                  ]
                }
              ]
            },
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'test_polynomial',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Runs all the polynomial class tests. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(int) Returns 0 to specify to Meson that the tests finished correctly '
                    }
                  ]
                }
              ]
            },
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'main',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Calls the monomial and polynomial tests. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => '(int) The sum of the test_monomial and test_polynomial function wich should be zero when all tests pass '
                    }
                  ]
                }
              ]
            },
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This is the main test file of the emath library. It contains all the tests needed to assure that the library works properly. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This file contains a main function that calls a function for the monomials and a function for the polynomials that test that every method works as it should.'
          },
          {
            type => 'linebreak'
          },
          {
            type => 'text',
            content => 'If it doesn\'t then a message gets printed to the console describing the error. If this does happen open an issue on my github page. '
          }
        ]
      }
    }
  ],
  groups => [
  ],
  pages => [
    {
      name => 'index',
      title4 => 'EMath++ Project',
      detailed => {
        doc => [
          {
            type => 'sect1',
            title => 'Introduction',
            content => [
              {
                type => 'text',
                content => 'This is a project that aims to provide some wrapper classes for algebraic mathematical concepts.'
              },
              {
                type => 'linebreak'
              },
              {
                type => 'text',
                content => 'At the moment it includes the Monomial and Polynomial classes for general calculus. The library is currently in expansion.'
              },
              {
                type => 'linebreak'
              },
              {
                type => 'text',
                content => 'Any feedback is much appreciated!'
              }
            ]
          },
          {
            type => 'sect1',
            title => 'Installation',
            content => [
              {
                type => 'text',
                content => 'The project comes with a folder with some bash files that complete some Meson related tasks.'
              },
              {
                type => 'linebreak'
              },
              {
                type => 'text',
                content => 'All bash files must be executed from the project\'s root directory to work properly.'
              },
              {
                type => 'linebreak'
              },
              {
                type => 'text',
                content => 'To install the project, there is only need to execute two of them files.'
              },
              {
                type => 'linebreak'
              },
              {
                type => 'text',
                content => 'Once installed just include the '
              },
              {
                type => 'url',
                link => 'emath_8h',
                content => 'emath.h'
              },
              {
                type => 'text',
                content => ' header file in your code and link it with its implementation.'
              },
              {
                type => 'sect2',
                title => 'Step one: Setup the Project',
                content => [
                  {
                    type => 'text',
                    content => 'To setup the Meson project run the setup.sh bash file: '
                  },
                  {
                    type => 'preformatted',
                    content => 'bash ./scripts/setup.sh'
                  }
                ]
              },
              {
                type => 'sect2',
                title => 'Step two: Install the Library',
                content => [
                  {
                    type => 'text',
                    content => 'To install the emath library run the install.sh bash file:'
                  },
                  {
                    type => 'parbreak'
                  },
                  {
                    type => 'preformatted',
                    content => 'bash ./scripts/install.sh'
                  },
                  {
                    type => 'parbreak'
                  },
                  {
                    note => [
                      {
                        type => 'text',
                        content => 'You will need a privileged user\'s credentials'
                      }
                    ]
                  }
                ]
              }
            ]
          },
          {
            type => 'sect1',
            title => 'Testing',
            content => [
              {
                type => 'text',
                content => 'The project comes with some test files located in the test folder.'
              },
              {
                type => 'linebreak'
              },
              {
                type => 'text',
                content => 'To test that the library code works properly run the following bash file: '
              },
              {
                type => 'preformatted',
                content => 'bash ./scripts/test.sh'
              },
              {
                type => 'text',
                content => ' '
              }
            ]
          }
        ]
      }
    }
  ]
};
1;
