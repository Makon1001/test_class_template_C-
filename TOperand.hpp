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
#include <cstdint>
#include <limits>
#include <float.h>

template <typename T>
class Operand : public IOperand
{
    public :
        Operand(long double val = 0);
        ~Operand();
        T getMaxValue() const;
        T getMinValue() const;
        void setValue(T value);
        long double getValue() const override;
        eOperandType getType() const override;
        std::string getTypeString() const;
        int getPrecision() const;
        std::string toString() const override;
        IOperand* operator+(const IOperand& rhs) const override;
        IOperand* operator-(const IOperand& rhs) const override;
        IOperand* operator*(const IOperand& rhs) const override;
        IOperand* operator/(const IOperand& rhs) const override;
        IOperand* operator%(const IOperand& rhs) const override;
    private :
        std::string Type;
        T min_value;
        T max_value;
        int precision;
        T value;
};

template <typename T>
Operand<T>::Operand(long double val){
    setValue(val);
}


template<> Operand<typename::int8_t>::Operand(long double val): Type("int8"), min_value(std::numeric_limits<int8_t>::min()), max_value(std::numeric_limits<int8_t>::max()), precision(0){
    setValue(val);
    std::cout << "Constructeur Operand8a" << std::endl;
}

template<> Operand<typename::int16_t>::Operand(long double val): Type("int16"), min_value(std::numeric_limits<int16_t>::min()), max_value(std::numeric_limits<int16_t>::max()), precision(0){
    setValue(val);
    std::cout << "Constructeur Operand16a" << std::endl;
}

template <> Operand<typename::int32_t>::Operand(long double val): Type("int32"), min_value(std::numeric_limits<int32_t>::min()), max_value(std::numeric_limits<int32_t>::max()), precision(0){
    setValue(val);
    std::cout << "Constructeur Operand32a" << std::endl;
}

template <> Operand<float>::Operand(long double val): Type("float"), min_value(-FLT_MAX), max_value(+FLT_MAX + 1), precision(7){
    setValue(val);
    std::cout << "Constructeur OperandFloat" << std::endl;
}


template <typename T>
Operand<T>::~Operand(){
}

template <typename T>
T Operand<T>::getMaxValue() const
{
    return this->max_value;
}

template <typename T>
T Operand<T>::getMinValue() const
{
    return this->min_value;
}

template <typename T>
long double Operand<T>::getValue() const
{
    return this->value;
}

template <typename T>
std::string Operand<T>::getTypeString() const
{
    return this->Type;
}

template <typename T>
int Operand<T>::getPrecision() const
{
    return this->precision;
}

template <typename T>
void Operand<T>::setValue(T val)
{
    std::cout <<"value : "<< val << std::endl;
    
    if(val > this->getMaxValue()){
       throw std::overflow_error("Overflow Error");
        this->value = 0;
    } else if (val < this->getMinValue()){
       throw std::underflow_error("Underflow Error");
        this->value = 0;
    } else {
        this->value = val;
    }
}

template <typename T>
eOperandType Operand<T>::getType() const
{
    EnumParser<eOperandType> TypeParser;
    eOperandType index_of_eOperandType = TypeParser.ParseEnum(this->getTypeString());
    return index_of_eOperandType;
}

template <typename T>
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

template <typename T>
IOperand* Operand<T>::operator+(const IOperand& rhs) const
{
    eOperandType defineType(typeAnalyse(this->getType(), rhs.getType()));
    
   if(defineType == Int8){
        Operand<typename::int8_t>* result = new Operand<typename::int8_t>;
        result->setValue(this->getValue() + rhs.getValue());
        return result;
    } else if (defineType == Int16){
        Operand<typename::int16_t> *result16 = new Operand<typename::int16_t>;
        result16->setValue(this->getValue() + rhs.getValue());
        return result16;
    } else if (defineType == Int32){
        Operand<typename::int32_t> *result32 = new Operand<typename::int32_t>;
        result32->setValue(this->getValue() + rhs.getValue());
        return result32;
    } else {
       Operand<float> *resultFloat = new Operand<float>;
        resultFloat->setValue(this->getValue() + rhs.getValue());
        return resultFloat;
    }

    return nullptr;
}

template <typename T>
IOperand* Operand<T>::operator-(const IOperand& rhs) const
{
    eOperandType defineType(typeAnalyse(this->getType(), rhs.getType()));
    
   if(defineType == Int8){
        Operand<typename::int8_t>* result = new Operand<typename::int8_t>;
        result->setValue(this->getValue() - rhs.getValue());
        return result;
    } else if (defineType == Int16){
        Operand<typename::int16_t> *result16 = new Operand<typename::int16_t>;
        result16->setValue(this->getValue() - rhs.getValue());
        return result16;
    } else if (defineType == Int32){
        Operand<typename::int32_t> *result32 = new Operand<typename::int32_t>;
        result32->setValue(this->getValue() - rhs.getValue());
        return result32;
    } else {
       Operand<float> *resultFloat = new Operand<float>;
        resultFloat->setValue(this->getValue() - rhs.getValue());
        return resultFloat;
    }

    return nullptr;
}

template <typename T>
IOperand* Operand<T>::operator*(const IOperand& rhs) const
{
    eOperandType defineType(typeAnalyse(this->getType(), rhs.getType()));
    
   if(defineType == Int8){
        Operand<typename::int8_t>* result = new Operand<typename::int8_t>;
        result->setValue(this->getValue() * rhs.getValue());
        return result;
    } else if (defineType == Int16){
        Operand<typename::int16_t> *result16 = new Operand<typename::int16_t>;
        result16->setValue(this->getValue() * rhs.getValue());
        return result16;
    } else if (defineType == Int32){
        Operand<typename::int32_t> *result32 = new Operand<typename::int32_t>;
        result32->setValue(this->getValue() * rhs.getValue());
        return result32;
    } else {
       Operand<float> *resultFloat = new Operand<float>;
        resultFloat->setValue(this->getValue() * rhs.getValue());
        return resultFloat;
    }
    return nullptr;
}

template <typename T>
IOperand* Operand<T>::operator/(const IOperand& rhs) const
{
    eOperandType defineType(typeAnalyse(this->getType(), rhs.getType()));
    if(rhs.getValue() == 0){
        throw std::overflow_error("Error : Division by zero");
    }
    
   if(defineType == Int8){
        Operand<typename::int8_t>* result = new Operand<typename::int8_t>;
        result->setValue(this->getValue() / rhs.getValue());
        return result;
    } else if (defineType == Int16){
        Operand<typename::int16_t> *result16 = new Operand<typename::int16_t>;
        result16->setValue(this->getValue() / rhs.getValue());
        return result16;
    } else if (defineType == Int32){
        Operand<typename::int32_t> *result32 = new Operand<typename::int32_t>;
        result32->setValue(this->getValue() / rhs.getValue());
        return result32;
    } else {
       Operand<float> *resultFloat = new Operand<float>;
        resultFloat->setValue(this->getValue() / rhs.getValue());
        return resultFloat;
    }
    return nullptr;
}

template <typename T>
IOperand* Operand<T>::operator%(const IOperand& rhs) const
{
    eOperandType defineType(typeAnalyse(this->getType(), rhs.getType()));
    if(rhs.getValue() == 0){
        throw std::overflow_error("Error : modulo by zero.");
    }
    if(this->getType() > Int32 || rhs.getType() > Int32) {
        throw std::overflow_error("Error : modulo with non integer number.");
    }
    
   if(defineType == Int8){
        Operand<typename::int8_t>* result = new Operand<typename::int8_t>;
        result->setValue(this->getValue() / rhs.getValue());
        return result;
    } else if (defineType == Int16){
        Operand<typename::int16_t> *result16 = new Operand<typename::int16_t>;
        result16->setValue(this->getValue() / rhs.getValue());
        return result16;
    } else if (defineType == Int32){
        Operand<typename::int32_t> *result32 = new Operand<typename::int32_t>;
        result32->setValue(this->getValue() / rhs.getValue());
        return result32;
    } else {
       Operand<float> *resultFloat = new Operand<float>;
        resultFloat->setValue(this->getValue() / rhs.getValue());
        return resultFloat;
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
