//
//  Enup.hpp
//  test_class_template
//
//  Created by Manuel Konrath on 23/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef Enum_h
#define Enum_h

typedef enum
{
    push,
    pop,
    dump,
    clear,
    dup,
    swap_Instruction,
    assert,
    add_Instruction,
    sub,
    mul,
    div_Instruction,
    mod,
    load,
    store,
    print,
    exit_Instruction,
}eInstructionsListe;


typedef enum
{
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
}eOperandType;


#endif /* Enum_h */
