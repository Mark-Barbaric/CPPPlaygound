#include "user.h"
#include <string_view>

struct User::Impl {

    Impl(std::string_view n)
    :m_name(n)
    {

    }

    const std::string& getName() const noexcept {return m_name;}
    private:

    const std::string m_name;

};

User::User(std::string_view name)
:pimpl(new Impl(name))
{

}

User::~User() = default;

const std::string& User::getName() const noexcept {
    return pimpl->getName();
}