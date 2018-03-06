//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZATION_SCALAR_HPP
#define CEREALIZATION_SCALAR_HPP

namespace Cerealization
{
    namespace Cerealizable
    {
        template<typename T>
        class Scalar
        {
        public:
            explicit Scalar(T &attribute) :
                    tohandle(&attribute), allocated(false)
            {

            }

            explicit Scalar() :
                    tohandle(new T()), allocated(true)
            {

            }

            Scalar(T const &value) :
                    tohandle(new T(value)), allocated(true)
            {

            }

            virtual ~Scalar()
            {
                if (allocated)
                    delete tohandle;
            }

        public:
            T &get()
            {
                return *tohandle;
            }

        private:
            T          *tohandle;
            const bool allocated;
        };

        using Char = Scalar<char>;
        using UChar = Scalar<unsigned char>;
        using Short = Scalar<short>;
        using UShort = Scalar<unsigned short>;
        using Int = Scalar<int>;
        using UInt = Scalar<unsigned int>;
        using Long = Scalar<long>;
        using ULong = Scalar<unsigned long>;
        using LongLong = Scalar<long long>;
        using ULongLong = Scalar<unsigned long long>;
    }
}

#endif //CEREALIZATION_SCALAR_HPP
