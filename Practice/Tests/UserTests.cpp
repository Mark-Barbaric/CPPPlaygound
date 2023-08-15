#include <gtest/gtest.h>
#include "user.h"

TEST(UserTests, BasicFunctionalityTests)
{
    const std::unique_ptr<User> newUser = std::make_unique<User>("mark");
    EXPECT_EQ(newUser->getName(), "mark");

}