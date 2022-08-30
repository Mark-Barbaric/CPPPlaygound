#pragma once

namespace MoveSemantics{

    struct T {
        // ...
    };

    T fn()
    {
        T t;
        return t;
    }

    struct A{
        std::string m_s;
        A(std::string const& in):m_s(in){}
        A(std::string && in):m_s(in){}
    };


    struct B{
        std::string m_s;
        B(std::string in):m_s(std::move(in)){}
    };
}