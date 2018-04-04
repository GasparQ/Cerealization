//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZATION_TUPLE_HPP
#define CEREALIZATION_TUPLE_HPP

#include <utility>
#include <tuple>
#include <memory>

namespace Cerealization
{
    namespace Cerealizable
    {
        template<typename First, typename ... Args>
        class Tuple
        {
        private:
            template<typename T>
            class Elem
            {
            public:
                using type = T;
                using ptr = T *;

            public:
                Elem(ptr dat) :
                    dat(dat)
                {

                }

                Elem(Elem<T> const &ref) :
                    dat(new T(ref.get()))
                {

                }

                Elem<T> &operator=(Elem<T> const &ref)
                {
                    set(ref.get());
                    return *this;
                }

            public:
                bool operator==(Elem<T> const &ref) const
                {
                    return get() == ref.get();
                }

                bool operator!=(Elem<T> const &ref) const
                {
                    return get() != ref.get();
                }

                type &get() const
                {
                    return *dat;
                }

                int set(T const &ref) const
                {
                    get() = ref; return 0;
                }

                int release()
                {
                    delete(dat); return 0;
                }

            private:
                ptr dat;
            };

            using DataType = std::tuple<Elem<First>, Elem<Args>...>;

            template<size_t i> using TElem = std::tuple_element<i, DataType>;

            template<size_t i> using TElemType = typename TElem<i>::type;

        private:
            using seq = std::index_sequence_for <First, Args...>;

            template <size_t ... idx> using seqT = std::index_sequence <idx...>;

        private:
            class Deleter
            {
            public:
                template<typename T>
                void operator()(T &todelete)
                {
                    delete (&todelete);
                }
            };

        public:
            explicit Tuple(First &fattr, Args &... attributes) :
                    data {
                            &fattr,
                            (&attributes)...
                    }, allocated {false}
            {

            }

            explicit Tuple(First const &fval, Args const &... values) :
                    data {
                            new First(fval),
                            (new Args(values))...
                    }, allocated {true}
            {

            }

            explicit Tuple() :
                    data {
                            new First(),
                            (new Args())...
                    }, allocated {true}
            {

            }

            Tuple(Tuple<First, Args...> const &ref) :
                    data(ref.data),
                    allocated(true)
            {

            }

            virtual ~Tuple()
            {
                if (allocated)
                {
                    _delete(seq());
                }
            }

            Tuple<First, Args...>   &operator=(Tuple<First, Args...> const &ref)
            {
                data = ref.data;
                return *this;
            }

        private:
            template <size_t ... idxs>
            void _delete(seqT<idxs...>)
            {
                (void)std::initializer_list<int>{(std::get<idxs>(data).release())...};
            }

        public:
            bool operator==(Tuple<First, Args...> const &ref) const
            {
                return data == ref.data;
            }

            bool operator!=(Tuple<First, Args...> const &ref) const
            {
                return data != ref.data;
            }

        public:
            template<size_t index, typename Value>
            void set(Value &&value)
            {
                get<index>() = value;
            }

            template<size_t index>
            typename TElemType<index>::type &get() const
            {
                return std::get<index>(data).get();
            }

        public:
            template<typename Callable>
            void forEach(Callable &tocall) const
            {
                _forEach(tocall, seq());
            }

        private:
            template<typename Callable, size_t ... idxs>
            void _forEach(Callable &tocall, seqT<idxs...>) const
            {
                _forEach(tocall, get<idxs>()...);
            }

            template<typename Callable, typename F, typename ... Nexts>
            void _forEach(Callable &tocall, F &tosend, Nexts &... nexts) const
            {
                tocall(tosend);
                _forEach(tocall, nexts...);
            }

            template<typename Callable, typename L>
            void _forEach(Callable &tocall, L &last) const
            {
                tocall(last);
            }

        public:
            template <typename Callable>
            void apply(Callable const &tocall) const
            {
                _apply(tocall, seq());
            }

        private:
            template <typename Callable, size_t ... idxs>
            void _apply(Callable const &tocall, seqT<idxs...>) const
            {
                tocall((std::get<idxs>(data).get())...);
            }

        private:
            DataType data;
            const bool allocated;
        };
    }
}

#endif //CEREALIZATION_TUPLE_HPP
