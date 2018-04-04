#include <gtest/gtest.h>
//#include <glog/logging.h>

std::string topLevelProjectDir;

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);

  // If you run "make test", the add_test() macro in this_dir/CMakeLists.txt
  // will automatically pass the directory name as first argument to the test
  // If you are running executable manually, you have to pass the top-level
  // src directory name on the command line
  if (argc == 1) {
    // if top level directory has not been passed use
    // the current directory
    topLevelProjectDir = "./";
  } else {
    topLevelProjectDir = argv[1];
  }
  return RUN_ALL_TESTS();
}

