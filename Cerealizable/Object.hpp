//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZATION_OBJECT_HPP
#define CEREALIZATION_OBJECT_HPP

#include <string>
#include <vector>
#include <functional>

#include "Tuple.hpp"

namespace Cerealization
{
    namespace Cerealizable
    {
        template<typename First, typename ... Args>
        class Object : private Tuple<First, Args...>
        {
        private:
            using Name = std::string;
            using NamePtr = std::unique_ptr<Name>;
            using Names = std::vector<NamePtr>;

        private:
            template<typename Callable>
            class Injector
            {
            public:
                Injector(Callable &callback, Names const &names) :
                        callback(callback), names(names), index(0)
                {

                }

            public:
                template<typename T>
                void operator()(T &curr)
                {
                    callback(*names[index++], curr);
                }

            private:
                Callable &callback;
                const Names &names;
                unsigned int index;
            };

        public:
            template<typename T> using Element = std::pair<std::string, T>;

        public:
            explicit Object(Element<First *> const &attr, Element<Args *> const &... attrs) :
                Tuple<First, Args...> {
                    *attr.second,
                    *attrs.second...
                },
                names ()
            {
                setNames({attr.first, attrs.first...});
            }

            explicit Object(Element<First> &&fval, Element<Args> &&... ovals) :
                Tuple<First, Args...> {
                    fval.second,
                    ovals.second...
                },
                names ()
            {
                setNames({fval.first, ovals.first...});
            }

            Object(std::initializer_list<std::string> const &names) :
                    Tuple<First, Args...> {}, names()
            {
                setNames(names);
            }

            Object() :
                Tuple<First, Args...>(),
                names()
            {
                setNames(std::vector<Name>(sizeof...(Args) + 1, Name()));
            }

        public:
            template<typename Callable>
            void forEach(Callable &tocall) const
            {
                Injector<Callable> injector(tocall, names);

                Tuple<First, Args...>::forEach(injector);
            }

        public:
            using Tuple<First, Args...>::apply;

        private:
            void setNames(std::vector<std::string> const &toset)
            {
                for (Name const &name : toset)
                {
                    this->names.push_back(std::make_unique<Name>(name));
                }
            }

        private:
            Names names;
        };
    }
}

#endif //CEREALIZATION_OBJECT_HPP
