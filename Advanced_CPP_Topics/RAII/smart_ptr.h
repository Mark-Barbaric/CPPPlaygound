#pragma once
#include <iostream>

namespace AdvancedCPPTopics{

    template<class T>
    class smart_ptr{

        T* m_ptr;
    public:

        template<typename... Args>
        smart_ptr(Args&&... args) : m_ptr(new T(std::forward<Args>(args)...)){}

        ~smart_ptr(){
            std::cout << "Destructor called.\n";
            delete m_ptr;
        }

        smart_ptr(const smart_ptr& rhs) = delete;
        smart_ptr& operator=(const smart_ptr& rhs) = delete;

        smart_ptr(smart_ptr &&rhs):m_ptr(exchange(rhs.m_ptr, nullptr)){}
        smart_ptr& operator=(const smart_ptr &&rhs) {
            if(&rhs == this){
                return *this;            
            }

            delete m_ptr;
            m_ptr = exchange(rhs.m_ptr, nullptr);
            return *this;
        }

        T& operator*() const {return *m_ptr;}
        T* operator->() const {return m_ptr;}
    };

    void func(){
        auto ptr = smart_ptr<int>(3);
    }
}