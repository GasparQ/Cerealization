//
// Created by GasparQ on 07/03/2018.
//

#include "Cerealizer/Binary/DefaultOperations.hpp"
#include "Cerealizer/Binary/ModelOperations.hpp"
#include "Cerealizable/List.hpp"

using namespace Cerealization::Cerealizer;

BinaryStream &operator<<(BinaryStream &output, char data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, unsigned char data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, short data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, unsigned short data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, int data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, unsigned int data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, long data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, unsigned long data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, long long data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, unsigned long long data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, float data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, double data)
{
    output.Write(data);
    return output;
}

BinaryStream &operator<<(BinaryStream &output, std::string const &data)
{
    output << String(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, char &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, unsigned char &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, short &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, unsigned short &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, int &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, unsigned int &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, long &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, unsigned long &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, long long &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, unsigned long long &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, float &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, double &data)
{
    output.Read(data);
    return output;
}

BinaryStream &operator>>(BinaryStream &output, std::string &data)
{
    output >> Cerealization::Cerealizable::String(data);
    return output;
}
