
#define CATCH_CONFIG_RUNNER
#include "../../Catch2/single_include/catch2/catch.hpp"

int main(int argc, char* argv[])
{
	const auto result = Catch::Session().run(argc, argv);
	return result;
}