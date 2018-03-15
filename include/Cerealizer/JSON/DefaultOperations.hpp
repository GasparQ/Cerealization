//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_JSON_DEFAULTOPERATIONS_HPP
#define CEREALIZABLE_JSON_DEFAULTOPERATIONS_HPP

#include "JSONStream.hpp"

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, char data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned char data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, short data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned short data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, int data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned int data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, long data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned long data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, long long data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned long long data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, float data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, double data);
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, std::string const &data);

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, char &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned char &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, short &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned short &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, int &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned int &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, long &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned long &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, long long &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned long long &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, float &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, double &data);
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, std::string &data);

#endif //CEREALIZABLE_JSON_DEFAULTOPERATIONS_HPP
