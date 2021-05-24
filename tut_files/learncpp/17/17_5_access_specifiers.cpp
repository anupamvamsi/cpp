// 17.5
// https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
/* AS - Access Specifier | I - Inheritance Type
-------------------------------------------------------
Base AS   : I: Public    | I: Private   | I: Protected
-------------------------------------------------------
Public 	  : Public 	     | Private 	    | Protected
Protected : Protected    | Private 	    | Protected
Private 	: Inaccessible | Inaccessible | Inaccessible
-------------------------------------------------------
*/

// 17.6
// https://www.learncpp.com/cpp-tutorial/adding-new-functionality-to-a-derived-class/
/* SUMMARY
 * Can add a function to a derived class, which is not present in a base class.
 */

// 17.7
// https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
/* SUMMARY
 * Calling a function - compiler first checks derived class -> then goes up in
 * order to find the member function in the base classes of the derived class.

 * Can redefine a base class member fn in a derived class by using same name -
 this changes the access specifier of the base class member fn in the derived
 class

 * Can add functionality by using the scope qualifier (::) - even this changes
 the access specifier of the base class member fn

 * Cast the derived class object as a base class object using
 static_cast<const T&> in the operator<< overload functions (which can be
 defined in both the base and the derived classes)

 * Check 17_2_inheritance_1.cpp and 17_2_inheritance_2.cpp for examples of the
 above points.
 */