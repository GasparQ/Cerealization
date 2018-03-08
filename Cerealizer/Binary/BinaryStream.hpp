//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZABLE_BINARY_HPP
#define CEREALIZABLE_BINARY_HPP

#include <vector>
#include <cstdlib>

namespace Cerealization
{
    namespace Cerealizer
    {
        class BinaryStream
        {
        public:
            using Byte = unsigned char;

        public:
            explicit BinaryStream();
            explicit BinaryStream(size_t size);
            explicit BinaryStream(Byte *data, size_t size);
            ~BinaryStream() = default;

        public:
            size_t Read(Byte *dst, size_t size);
            size_t Write(const Byte *src, size_t size);

        public:
            template <typename T>
            size_t Read(T &dst)
            {
                return Read((Byte *)&dst, sizeof(dst));
            }

            template <typename T>
            size_t Write(T const &src)
            {
                return Write((const Byte *)&src, sizeof(src));
            }

        public:
            const Byte *Data() const;
            Byte *Data();
            size_t Size() const;

        public:
            BinaryStream &operator<<(BinaryStream const &src);

        public:
            std::vector<Byte>   buffer;
            size_t rindex;
        };
    }
}

#endif //CEREALIZABLE_BINARY_HPP
