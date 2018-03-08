//
// Created by GasparQ on 05/03/2018.
//

#include "Cerealizer/JSON/JSONStream.hpp"

Cerealization::Cerealizer::JSONStream::JSONStream(const Cerealization::Cerealizer::JSONStream &ref) :
    buffer(ref.buffer.str())
{

}

Cerealization::Cerealizer::JSONStream::JSONStream(std::string const &data) :
    buffer(data)
{

}

std::string Cerealization::Cerealizer::JSONStream::Data() const
{
    return buffer.str();
}

size_t Cerealization::Cerealizer::JSONStream::Size() const
{
    return buffer.str().size();
}

Cerealization::Cerealizer::JSONStream &Cerealization::Cerealizer::JSONStream::operator<<(const Cerealization::Cerealizer::JSONStream &src)
{
    buffer << src.buffer.str();
    return *this;
}

char Cerealization::Cerealizer::JSONStream::nextCharacter()
{
    return static_cast<char>(buffer.peek());
}
