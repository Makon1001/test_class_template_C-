//
//  TOperand.hpp
//  test_class_template
//
//  Created by Manuel Konrath on 23/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#ifndef TOperand_hpp
#define TOperand_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "struc_of_type.hpp"
#include "IOperand.hpp"
#include "EnumParser.h"
#include <stdexcept>

template <class T>
class Operand : public IOperand
{
    public :
        Operand(double val = 0);
        ~Operand();
        int getMaxValue() const;
        int getMinValue() const;
        void setValue(double value) override;
        int getValue() const override;
        eOperandType getType() const override;
        std::string getTypeString() const;
        int getPrecision() const;
        std::string toString() const override;
        IOperand* operator+(const IOperand& rhs) const override;
    private :
        std::string Type;
        double min_value;
        double max_value;
        int precision;
        int value;
};

template <class T>
Operand<T>::Operand(double val){
    setValue(val);
}


template<> Operand<class Int8>::Operand(double val): Type("int8"), min_value(-128), max_value(127), precision(0){
    setValue(val);
    std::cout << "Constructeur Operand8a" << std::endl;
}

template<> Operand<class Int16>::Operand(double val): Type("int16"), min_value(-32768), max_value(32767), precision(0){
    setValue(val);
    std::cout << "Constructeur Operand16a" << std::endl;
}

template <> Operand<class Int32>::Operand(double val): Type("int32"), min_value(-2147483648), max_value(2147483647), precision(0){
    setValue(val);
    std::cout << "Constructeur Operand32a" << std::endl;
}


template <class T>
Operand<T>::~Operand(){}

template <class T>
int Operand<T>::getMaxValue() const
{
    return this->max_value;
}

template <class T>
int Operand<T>::getMinValue() const
{
    return this->min_value;
}

template <class T>
int Operand<T>::getValue() const
{
    return this->value;
}

template <class T>
std::string Operand<T>::getTypeString() const
{
    return this->Type;
}

template <class T>
int Operand<T>::getPrecision() const
{
    return this->precision;
}

template <class T>
void Operand<T>::setValue(double val)
{
    if(val > this->max_value){
        throw std::overflow_error("Overflow Error");
        this->value = 0;
    } else if (value < this->min_value){
        throw std::underflow_error("Underflow Error");
        this->value = 0;
    } else {
        this->value = val;
    }
}

template <class T>
eOperandType Operand<T>::getType() const
{
    EnumParser<eOperandType> TypeParser;
    eOperandType index_of_eOperandType = TypeParser.ParseEnum(this->getTypeString());
    return index_of_eOperandType;
}

template <class T>
std::string Operand<T>::toString() const
{
    std::string describtion;
    describtion = "Value : " + std::to_string(this->getValue()) + "\n"
                + "Type : " + this->getTypeString() + "\n"
                + "Max value : " + std::to_string(this->getMaxValue()) + "\n"
                + "Min value : " + std::to_string(this->getMinValue()) + "\n"
                + "Precision : " + std::to_string(this->getPrecision()) + "\n";
    return describtion;
}

template <class T>
IOperand* Operand<T>::operator+(const IOperand& rhs) const
{
    eOperandType defineType(typeAnalyse(this->getType(), rhs.getType()));
    if(defineType == Int8){
        Operand<class Int8> *result = new Operand<class Int8>;
        result->setValue(this->getValue() + rhs.getValue());
        return result;
    } else if (defineType == Int16){
        Operand<class Int16> *result16 = new Operand<class Int16>;
        result16->setValue(this->getValue() + rhs.getValue());
        return result16;
    } else {
        Operand<class Int32> *result32 = new Operand<class Int32>;
        result32->setValue(this->getValue() + rhs.getValue());
        return result32;
    }

                return nullptr;
}

eOperandType typeAnalyse( eOperandType a, eOperandType b)
{
    if(a >= b ){
        return a;
    } else {
        return b;
    }
}


#endif /* TOperand_hpp */
