//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZABLE_JSONSTREAM_HPP
#define CEREALIZABLE_JSONSTREAM_HPP

#include <memory>
#include <sstream>

namespace Cerealization
{
    namespace Cerealizer
    {
        class JSONStream
        {
        public:
            JSONStream() = default;
            JSONStream(JSONStream const &ref);
            explicit JSONStream(std::string const &data);
            ~JSONStream() = default;

        public:
            template <typename T>
            void Read(T &dst)
            {
                buffer >> dst;
            }

            template <typename T>
            void ReadUntil(T &dst, char delim)
            {
                std::string line;

                if (std::getline(buffer, line, delim))
                {
                    std::stringstream n(line);

                    n >> dst;
                }
            }

            template <typename T>
            void Write(T const &src)
            {
                buffer << src;
            }

        public:
            char nextCharacter();

        public:
            void ignore(const size_t nbchar)
            {
                std::unique_ptr<char[]> u(new char[nbchar]);

                buffer.read(u.get(), nbchar);
            }

        public:
            std::string Data() const;
            size_t Size() const;

        public:
            JSONStream &operator<<(JSONStream const &src);

        private:
            std::stringstream   buffer;
        };
    }
}

#endif //CEREALIZABLE_JSONSTREAM_HPP
