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

            Scalar(Scalar<T> const &ref) :
                Scalar(ref.get())
            {

            }

            virtual ~Scalar()
            {
                if (allocated)
                    delete tohandle;
            }

            bool operator==(Scalar<T> const &ref) const
            {
                return get() == ref.get();
            }

            bool operator!=(Scalar<T> const &ref) const
            {
                return get() != ref.get();
            }

            Scalar<T>   &operator=(Scalar<T> const &ref)
            {
                get() = ref.get();
                return *this;
            }

        public:
            T &get()
            {
                return *tohandle;
            }

            const T &get() const
            {
                return *tohandle;
            }

        private:
            T          *tohandle;
            const bool allocated;
        };
    }
}

#endif //CEREALIZATION_SCALAR_HPP
