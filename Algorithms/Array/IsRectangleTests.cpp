#include <gtest/gtest.h>
#include "IsRectangle.h"

TEST(IsRectangle, NonRectangleTests){

    const std::vector<Point> square = {{1,1}, {4,1}, {4,4}, {1,4}, {1,1}};
    ASSERT_EQ(fit_into_rectangle(square, 0.0001f), std::nullopt);
    const std::vector<Point> triangle = {{1,1}, {4,1}, {4,4},{1,1}};
    ASSERT_EQ(fit_into_rectangle(triangle, 0.0001f), std::nullopt);
    const std::vector<Point> weirdShape = {{1,1}, {5,1}, {5,3}, {3,2}, {1,3}, {1,1}};
    ASSERT_EQ(fit_into_rectangle(weirdShape, 0.0001f), std::nullopt);
}

TEST(IsRectangle, BaseRectangleTests){

    Point bottomLeft1 {1,1}, topRight1{5,3};
    const std::vector<Point> rectangle1 = {{1.000f,1}, {5,1}, {5,3}, {1,3}, {1,1}};
    ASSERT_NE(fit_into_rectangle(rectangle1), std::nullopt);
    ASSERT_EQ(fit_into_rectangle(rectangle1)->bottom_left, bottomLeft1);
    ASSERT_EQ(fit_into_rectangle(rectangle1)->top_right, topRight1);

    const std::vector<Point> rectangle2 = {{1,2},{1.000f,1}, {5,1}, {5,3}, {1,3}, {1,1}};
    ASSERT_NE(fit_into_rectangle(rectangle2), std::nullopt);
    ASSERT_EQ(fit_into_rectangle(rectangle2)->bottom_left, bottomLeft1);
    ASSERT_EQ(fit_into_rectangle(rectangle2)->top_right, topRight1);

    Point bottomLeft2 {-20,-4}, topRight2{-4,-1};
    const std::vector<Point> rectangle3 = {{-20,-4}, {-16, -4}, {-12,-4}, {-4,-4}, {-4, -3}, {-4, -1}, {-20, -1}, {-20, -4}};
    ASSERT_NE(fit_into_rectangle(rectangle3), std::nullopt);
    ASSERT_EQ(fit_into_rectangle(rectangle3)->bottom_left, bottomLeft2);
    ASSERT_EQ(fit_into_rectangle(rectangle3)->top_right, topRight2);

    const Polygon marginalRectangle = {{1.00001f,1}, {5,1}, {5,3}, {1,3}, {1,1}};
    const auto rectangle = fit_into_rectangle(marginalRectangle);
    ASSERT_TRUE(almost_equal(*rectangle, Rectangle{{1,1}, {5,3}}));
}

TEST(IsRectangle, FailedRectangleTests){
    const Polygon clockwiseRectangle = {{5,1}, {1,1}, {1,3}, {5,2}};
    ASSERT_EQ(fit_into_rectangle(clockwiseRectangle), std::nullopt);
    const Polygon nonAxisAlignedRectangle = {{1,1}, {5,2}, {4,3}, {0,1}, {1,1}};
    ASSERT_EQ(fit_into_rectangle(nonAxisAlignedRectangle), std::nullopt);
    const Polygon outsideOfMarginRectangle = {{1.0001f, 1}, {5,1}, {5,3}, {1,3}, {1.0001f, 1}};
    ASSERT_NE(fit_into_rectangle(outsideOfMarginRectangle), std::nullopt);
    const auto rectangle = fit_into_rectangle(outsideOfMarginRectangle);
    ASSERT_FALSE(almost_equal(*rectangle, Rectangle{{1,1}, {5,3}}));

    const auto newEpsilon = 0.001f;
    const auto rect2 = fit_into_rectangle(outsideOfMarginRectangle, newEpsilon);
    ASSERT_TRUE(almost_equal(*rect2, Rectangle{{1,1}, {5,3}}, newEpsilon));
}
