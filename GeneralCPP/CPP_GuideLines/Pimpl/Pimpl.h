#pragma once

class MyClassImpl;

class MyClass{

    explicit MyClass();
    void DoSomething();

private:
    const MyClassImpl* Pimpl() const {return m_pImpl.get();}
    MyClassImpl* Pimpl() {return m_pImpl.get();}
    std::unique_ptr<MyClassImpl> m_pImpl;
};

class MyClassImpl{
public:
    void DoStuff();
};
