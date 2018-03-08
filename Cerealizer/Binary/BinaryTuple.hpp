//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_BINARYTUPLE_HPP
#define CEREALIZABLE_BINARYTUPLE_HPP

#include "BinaryStream.hpp"

namespace Cerealization
{
    namespace Cerealizer
    {
        class BinaryTuple
        {
        public:
            class Cerealizer
            {
            public:
                explicit Cerealizer(BinaryStream &out) :
                        out(out)
                {

                }

                template <typename T>
                void operator()(T const &dat)
                {
                    out << dat;
                }

            private:
                BinaryStream &out;
            };

            class Decerealizer
            {
            public:
                explicit Decerealizer(BinaryStream &out) :
                        out(out)
                {

                }

                template <typename T>
                void operator()(T &data)
                {
                    out >> data;
                }

            private:
                BinaryStream &out;
            };
        };
    }
}

#endif //CEREALIZABLE_BINARYTUPLE_HPP
