//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_DEFAULTOPERATIONS_HPP
#define CEREALIZABLE_DEFAULTOPERATIONS_HPP

#include <string>
#include "BinaryStream.hpp"

Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, char data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, unsigned char data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, short data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, unsigned short data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, int data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, unsigned int data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, long data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, unsigned long data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, long long data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, unsigned long long data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, float data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, double data);
Cerealization::Cerealizer::BinaryStream &operator<<(Cerealization::Cerealizer::BinaryStream &output, std::string const &data);

Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, char &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, unsigned char &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, short &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, unsigned short &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, int &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, unsigned int &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, long &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, unsigned long &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, long long &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, unsigned long long &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, float &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, double &data);
Cerealization::Cerealizer::BinaryStream &operator>>(Cerealization::Cerealizer::BinaryStream &output, std::string &data);

#endif //CEREALIZABLE_DEFAULTOPERATIONS_HPP
