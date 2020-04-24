/* "#pragma once" ensures that code is not duplicated.

    // INSTEAD OF "#pragma once", THE FOLLOWING WAS USED BEFORE.
 * "<PROJECT>_<PATH>_<FILE>_H_"
 * "#ifndef FOO_BAR_BAZ_H_" is for the "baz.h" file in "foo/src/bar/baz.h".
 * "#define FOO_BAR_BAZ_H_"
 * "..." 
 * "#endif" // FOO_BAR_BAZ_H_

*/
#pragma once

void printHello();