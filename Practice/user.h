
#pragma once

#include <memory>
#include <string_view>

class User {

    public:
    User(std::string_view name);
    ~User();

    const std::string& getName() const noexcept;
    private:
        class Impl;
        std::unique_ptr<Impl> pimpl;

};