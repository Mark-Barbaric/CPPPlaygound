#include <gtest/gtest.h>
#include "AbstractFactory.h"

TEST(CreationalPatternTests, AbstractFactoryTests){
    BasicCarFactory basicCarFactory;
    Car* newCar = basicCarFactory.buildCar();
    ASSERT_EQ(newCar->getTireType(), "Basic");
    ASSERT_EQ(newCar->getBodyType(), "Aluminium");

    LuxuryCarFactory luxuryCarFactory;
    newCar = luxuryCarFactory.buildCar();

    ASSERT_EQ(newCar->getTireType(), "Luxury");
    ASSERT_EQ(newCar->getBodyType(), "Gold");

}