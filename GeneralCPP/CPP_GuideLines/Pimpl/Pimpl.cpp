#include "Pimpl.h"

MyClass::MyClass():m_pImpl(new MyClassImpl)
{}

MyClass::~MyClass(){ delete m_pImpl;}

void MyClass::DoSomething(){
    m_pImpl->DoStuff();
}