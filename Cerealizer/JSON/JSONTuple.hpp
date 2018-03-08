//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_JSONTUPLE_HPP
#define CEREALIZABLE_JSONTUPLE_HPP

#include "DefaultOperations.hpp"
#include "JSONStream.hpp"

namespace Cerealization
{
    namespace Cerealizer
    {
        class JSONTuple
        {
        public:
            class Cereal
            {
            public:
                explicit Cereal(JSONStream &out) :
                        out(out),
                        first(true)
                {

                }

                template <typename T>
                void operator()(T const &data)
                {
                    if (first)
                        first = false;
                    else
                        out.Write(", ");
                    out << data;
                }

            private:
                JSONStream &out;
                bool first;
            };

            class Decereal
            {
            public:
                explicit Decereal(JSONStream &out) :
                    out(out),
                    first(true)
                {

                }

                template <typename T>
                void operator()(T &data)
                {
                    if (first)
                        first = false;
                    else
                        out.ignore(2); //ignore ", "
                    out >> data;
                }

            private:
                JSONStream &out;
                bool first;
            };
        };
    }
}

#endif //CEREALIZABLE_JSONTUPLE_HPP
