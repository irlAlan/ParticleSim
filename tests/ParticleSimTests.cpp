#include <gtest/gtest.h>
#include <cassert>

#include <ParticleSim.h>


/**
 * Trying out Test Driven Development
 *  1) You are not allowed to write any production code unless it is to make a failing unit test pass.
 *  2) You are not allowed to write any more of a unit test than is sufficient to fail; and compilation failures are failures.
 *  3)You are not allowed to write any more production code than is sufficient to pass the one failing unit test.
 */

TEST(ParticleSim,construct)
{
  ParticleSim particleSim;
}


int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
