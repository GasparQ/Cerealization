//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_BINARYOBJECT_HPP
#define CEREALIZABLE_BINARYOBJECT_HPP

#include <string>

#include "BinaryStream.hpp"
#include "DefaultOperations.hpp"
#include "Cerealizable/List.hpp"

namespace Cerealization
{
    namespace Cerealizer
    {
        class BinaryObject
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
                void operator()(std::string const &name, T const &data)
                {
                    out << name << data;
                }

            private:
                BinaryStream &out;
            };


        };
    }
}

#endif //CEREALIZABLE_BINARYOBJECT_HPP
