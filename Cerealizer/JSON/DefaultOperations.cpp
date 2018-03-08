//
// Created by GasparQ on 07/03/2018.
//

#include "DefaultOperations.hpp"

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, char data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned char data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, short data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned short data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, int data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned int data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, long data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned long data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, long long data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &
operator<<(Cerealization::Cerealizer::JSONStream &output, unsigned long long data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, float data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, double data)
{
    output.Write(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &
operator<<(Cerealization::Cerealizer::JSONStream &output, std::string const &data)
{
    output.Write("\"" + data + "\"");
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, char &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned char &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, short &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned short &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, int &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned int &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, long &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned long &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, long long &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &
operator>>(Cerealization::Cerealizer::JSONStream &output, unsigned long long &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, float &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, double &data)
{
    output.Read(data);
    return output;
}

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, std::string &data)
{
    output.ignore(1); //ignore "\""
    output.ReadUntil(data, '"');
//    data = data.substr(1, data.size() - 1);
    return output;
}
