//
// Created by GasparQ on 05/03/2018.
//

#include <cstring>
#include "BinaryStream.hpp"

#define my_min(a, b) ((a) < (b) ? (a) : (b))

Cerealization::Cerealizer::BinaryStream::BinaryStream() :
    buffer(),
    rindex(0)
{

}

Cerealization::Cerealizer::BinaryStream::BinaryStream(size_t size) :
    buffer(size),
    rindex(0)
{

}

Cerealization::Cerealizer::BinaryStream::BinaryStream(Byte *data, size_t size) :
    BinaryStream(size)
{
    Write(data, size);
}

size_t Cerealization::Cerealizer::BinaryStream::Read(Byte *dst, size_t size)
{
    size_t read = my_min(size, Size());

    std::memcpy(dst, Data(), read);
    rindex += read;
    return read;
}

size_t Cerealization::Cerealizer::BinaryStream::Write(const Byte *src, size_t size)
{
    size_t write;

    for (write = 0; write < size; ++write)
    {
        buffer.push_back(src[write]);
    }
    return write;
}

const Cerealization::Cerealizer::BinaryStream::Byte *Cerealization::Cerealizer::BinaryStream::Data() const
{
    return &buffer.data()[rindex];
}

Cerealization::Cerealizer::BinaryStream::Byte *Cerealization::Cerealizer::BinaryStream::Data()
{
    return &buffer.data()[rindex];
}

size_t Cerealization::Cerealizer::BinaryStream::Size() const
{
    return buffer.size() - rindex;
}

Cerealization::Cerealizer::BinaryStream &Cerealization::Cerealizer::BinaryStream::operator<<(const Cerealization::Cerealizer::BinaryStream &src)
{
    Write(src.Data(), src.Size());
    return *this;
}
