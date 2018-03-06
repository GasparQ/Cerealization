//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZATION_SCALAR_HPP
#define CEREALIZATION_SCALAR_HPP

namespace Cerealization
{
    template <typename T>
    class Scalar
    {
    public:
        explicit Scalar(T &attribute) :
                tohandle(&attribute),
                allocated(false)
        {

        }

        explicit Scalar() :
                tohandle(new T()),
                allocated(true)
        {

        }

        explicit Scalar(T &&value) :
                tohandle(new T(value)),
                allocated(true)
        {

        }

        virtual ~Scalar()
        {
            if (allocated)
                delete tohandle;
        }

    public:
        T   &get()
        {
            return *tohandle;
        }

    private:
        T *tohandle;
        const bool allocated;
    };
}

#endif //CEREALIZATION_SCALAR_HPP
