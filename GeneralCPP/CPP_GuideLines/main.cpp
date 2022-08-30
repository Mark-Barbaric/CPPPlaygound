#include "Move.h"
#include "Move2.h"
#include "VectorBestPractice.h"

void runMove();
void runCPPGuidelines();
void runMove2();

void runMove(){
    std::cout << "Running Move Example.\n";
    std::cout << "Initializing Entity using implicit conversion.\n";
    CPPGuidelines::Entity entity ("Timothy");
    entity.printName();
    std::cout << "Initializing string2.\n";
    CPPGuidelines::String string2 = "Hello";
    std::cout << "Initializing dest using std::move.\n";
    CPPGuidelines::String dest = std::move(string2);
    dest = dest;
    CPPGuidelines::Entity entity2 (dest);
    std::cout << "String Count: " << CPPGuidelines::String::getCount() << std::endl;
}

void runCPPGuidelines(){
    std::cout << "Running CPP Guidelines.\n\n";
    runMove();
    CPPGuidelines::runVectorBestPractices();
}

void runMove2(){

    using namespace MoveSemantics;
    std::cout << "Running Move2.\n\n";
    std::string s = "asas";
    A as(std::move(s));
    B b(s);
    B b2("test");
    std::cout << s;
}

int main(int argc, char* argv[]){
    runCPPGuidelines();
    runMove2();
    return 0;
}