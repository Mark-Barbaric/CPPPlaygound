#define CATCH_CONFIG_RUNNER
#include "include/catch.hpp"

int main(int argc, char* argv[])
{
    const auto result = Catch::Session().run(argc, argv);
    return result;
}