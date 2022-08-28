#include "gtest/gtest.h"
#include "../src/tag_dispatching/advance.hpp"
#include "../src/tag_dispatching/distance.hpp"

#include <iterator>
#include <vector>
#include <list>

class TagDispatching : public ::testing::Test
{
};

TEST_F(TagDispatching, TagDispatching_AdvanceIterVector)
{
    std::vector<int> v{1, 2, 3};
    
    auto vi = v.begin();
    exo::advance(vi, 2);
    
    EXPECT_EQ(*vi, 3);
}

TEST_F(TagDispatching, TagDispatching_DistanceIterVector)
{
    std::vector<int> v{1, 2, 3, 7};

    auto diff = exo::distance(v.begin(), v.end());
    auto invDiff = exo::distance(v.end(), v.begin());

    EXPECT_EQ(diff, 4);
    EXPECT_EQ(invDiff, -4);
}

TEST_F(TagDispatching, TagDispatching_DistanceIterList)
{
    std::list<int> v{1, 2, 3, 7};

    auto diff = exo::distance(v.begin(), v.end());
    auto invDiff = exo::distance(v.end(), v.begin());

    EXPECT_EQ(diff, 4);
    EXPECT_EQ(invDiff, 1);
}
