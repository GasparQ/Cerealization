//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZATION_TUPLE_HPP
#define CEREALIZATION_TUPLE_HPP

#include <tuple>
#include <memory>

namespace Cerealization
{
    template <typename First, typename ... Args>
    class Tuple
    {
    private:
        template <typename T>
        using Elem = T *;

        using DataType = std::tuple<Elem<First>, Elem<Args>...>;

        template <size_t i>
        using TElem = std::tuple_element<i, std::tuple<Elem<First>, Elem<Args>...>>;

        template <size_t i>
        using TElemType = typename TElem <i>::type;

    private:
        using seq = std::make_index_sequence<sizeof...(Args) + 1>;

        template <size_t ... idxs>
        using seqT = std::integer_sequence<size_t, idxs...>;

    private:
        class Deleter
        {
        public:
            template <typename T>
            void operator()(T &todelete)
            {
                delete(&todelete);
            }
        };

    public:
        explicit Tuple(First &fattr, Args &... attributes) :
                data{&fattr, (&attributes)...},
                allocated(false)
        {

        }

        explicit Tuple(First &&fval, Args &&... values) :
                data{new First(fval), (new Args(values))...},
                allocated(true)
        {

        }

        explicit Tuple() :
                data{new First(), (new Args())...},
                allocated(true)
        {

        }

        virtual ~Tuple()
        {
            if (allocated)
            {
                Deleter deleter;
                forEach(deleter);
            }
        }

    public:
        template <size_t index, typename Value>
        void set(Value &&value)
        {
            *std::get<index>(data) = value;
        }

        template <size_t index>
        typename TElemType<index>::element_type &get()
        {
            return *std::get<index>(data);
        }

    public:
        template <typename Callable>
        void forEach(Callable &tocall) const
        {
            _forEach(tocall, seq());
        }

    private:
        template <typename Callable, size_t ... idxs>
        void _forEach(Callable &tocall, seqT<idxs...>) const
        {
            _forEach(tocall, (std::get<idxs>(data))...);
        }

        template <typename Callable, typename F, typename ... Nexts>
        void _forEach(Callable &tocall, Elem<F> const &tosend, Nexts const &... nexts) const
        {
            tocall(*tosend);
            _forEach(tocall, nexts...);
        }

        template <typename Callable, typename L>
        void _forEach(Callable &tocall, Elem<L> const &last) const
        {
            tocall(*last);
        }

    private:
        DataType data;
        const bool allocated;
    };
}

#endif //CEREALIZATION_TUPLE_HPP
