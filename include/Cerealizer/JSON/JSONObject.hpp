//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_JSONOBJECT_HPP
#define CEREALIZABLE_JSONOBJECT_HPP

#include "Operations.hpp"

namespace Cerealization
{
    namespace Cerealizer
    {
        class JSONObject
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
                void operator()(std::string const &name, T const &data)
                {
                    if (first)
                        first = false;
                    else
                        out.Write(", ");
                    out << name;
                    out.Write(": ");
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
                void operator()(std::string &name, T &data)
                {
                    if (first)
                        first = false;
                    else
                        out.ignore(2);  //ignore ", "
                    out >> name;
                    out.ignore(2);      //ignore ": "
                    out >> data;
                }

            private:
                JSONStream &out;
                bool first;
            };
        };
    }
}

#endif //CEREALIZABLE_JSONOBJECT_HPP
