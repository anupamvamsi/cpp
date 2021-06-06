// https://www.learncpp.com/cpp-tutorial/internal-linkage/
// https://www.learncpp.com/cpp-tutorial/external-linkage/

#include <iostream>

static int gInternalLinkageVariable;         // default init to 0
const int gConstInternalLinkageVariable{5};  // has to be init
constexpr int gConstExprInternalLinkageVariable{20};

int gExternalLinkageVariable;
extern const int gConstExternalLinkageVariable{23};
extern constexpr int gConstExprExternalLinkageVariable{12};

// another_cpp_file.cpp
int gExternalLinkageVariableInAnotherFile{-2};
extern const int gConstExternalLinkageVariableInAnotherFile{-14};
// this is useless:
extern constexpr int gConstExprExternalLinkageVariableInAnotherFile{-556};

/* In this current file, forward declarations of global var from another file */
// extern int gExternalLinkageVariableInAnotherFile;
// extern const int gConstExternalLinkageVariableInAnotherFile;

/* Forward declarations for constexpr are illegal */
// extern constexpr int gConstExprExternalLinkageVariableInAnotherFile;

int main() {
  std::cout << "Internal linkage variables: ";
  std::cout << gInternalLinkageVariable << " " << gConstInternalLinkageVariable
            << " " << gConstExprInternalLinkageVariable << "\n";

  std::cout << "External linkage variables: ";
  std::cout << gExternalLinkageVariable << " " << gConstExternalLinkageVariable
            << " " << gConstExprExternalLinkageVariable << "\n";

  return 0;
}