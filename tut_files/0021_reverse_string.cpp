#include <cstring>  // for strlen
#include <iostream>

char* ReverseString(char* input_string) {
  int len = strlen(input_string);
  // int len2 = sizeof(input_string);

  // std::cout << len << std::endl;
  // std::cout << len2 << std::endl; // 8 [= sizeof(char*)]

  char* start_ptr = &(input_string[0]);      // (or) input_string
  char* end_ptr = &(input_string[len - 1]);  // input_string + len - 1

  char temp;

  for (; start_ptr < end_ptr;) {
    temp = *start_ptr;
    *start_ptr = *end_ptr;
    *end_ptr = temp;

    start_ptr++;
    end_ptr--;
  }

  return input_string;
}

int main() {
  char original[]{"Perfecto! This is  goood!\n Yaya:  | "};

  std::cout << original << std::endl;

  std::string reversed = ReverseString(original);
  std::cout << reversed << std::endl;

  std::cin.get();
}