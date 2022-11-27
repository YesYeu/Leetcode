#include <fstream>
#include <iostream>
#include <sstream>

#include "Leetcode_215_R.h"
#include "Leetcode_221.h"
using namespace std;
void test_221(void);

void test(void);

int main(int, char **) {
  // vector<int> nums = {2,3,6,4,5,1};
  // Solution5 selectbyheap;
  // int buf= selectbyheap.findKthLargest(nums,2);
  // std::cout << "The " << 2 << "th largested element is:" <<  buf <<
  // std::endl; return 0;

  test();


  // test_221();
}

void test_221(void) {
  std::vector<std::vector<char>> maxtrix{{'1', '0', '1', '0', '0'},
                                         {'1', '0', '1', '1', '1'},
                                         {'1', '1', '1', '1', '1'},
                                         {'1', '0', '0', '1', '0'}};

  std::vector<std::vector<char>> maxtrix1{{'1', '0', '1', '0'},
                                          {'1', '0', '1', '1'},
                                          {'1', '0', '1', '1'},
                                          {'1', '1', '1', '1'}};

  std::vector<std::vector<char>> maxtrix2{
      {'1', '1', '1', '1', '1', '1', '1', '1'},
      {'1', '1', '1', '1', '1', '1', '1', '0'},
      {'1', '1', '1', '1', '1', '1', '1', '0'},
      {'1', '1', '1', '1', '1', '0', '0', '0'},
      {'0', '1', '1', '1', '1', '0', '0', '0'}};

  std::vector<std::vector<char>> maxtrix3{{'1', '0'}, {'0', '1'}, {'0', '1'},
                                          {'0', '1'}, {'1', '1'}, {'0', '0'},
                                          {'0', '1'}};

  Leetcode_221 inst;
  std::cout << inst.maximalSquare(maxtrix3) << std::endl;
  Leetcode_221_dynamicprogramming dp;
  std::cout << dp.maximalSquare(maxtrix3) << std::endl;
}
