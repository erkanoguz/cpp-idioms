#include "gtest/gtest.h"
#include "../src/tag_dispatching/advance.hpp"

#include <iterator>
#include <vector>

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