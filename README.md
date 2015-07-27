Custom String Class
===================

Overview
----------
A custom string class that implements strings in the C/C++
environment without NULL termination. It is a proper object
that contains the string data and its length. Using these,
both read and write methods are provided, as well as 
other expected string commands, such as upcasing, downcasing,
or character indexing. 

An improvement for this exercise would be to incorporate more
string methods, such as those exemplified in the Python string
class: https://docs.python.org/3/library/string.html

This project does not attempt to provide an improvement
over C strings or the C++ `string` library. This is purely for
pedagogical purposes.

This is an update to my CISP 430 Data Structures class 
assignment from American River College taught by the great
David Fox. 


String API
==========


Constructors
------------
```
String ( )                // Empty String default constructor
String (char)             // Character String constructor
String (const char*)      // Character array String constructor
String (const String& s)  // Copy constructor
```

Informational Methods
---------------------
```
unsigned   len ( ) const     // String length
     int index (char) const  // Find character index
```

Case Methods
------------
```
void     upcase (unsigned first, unsigned last)  // Uppercase string within range
void   downcase (unsigned first, unsigned last)  // Lowercase string within range
void togglecase (unsigned first, unsigned last)  // Toggle case within range
```

Stream Operators
----------------
```
friend std::ostream& operator<< (std::ostream&, const String&)  // cout << String 
friend std::istream& operator>> (std::istream&, String&)        // cin >> String
```

Accessor Operators
------------------
```
 char operator[] (unsigned) const  // Reference access
char& operator[] (unsigned)        // Copy access
```

Assignment Operators
--------------------
```
String&  operator= (const String&)  // Assign new String
String& operator+= (const String&)  // Assign concatenated String
```

String Concatenation
--------------------
```
friend String operator+ (const String&, const String&)  // Concat two Strings
friend String operator+ (const String&, char)           // Concat a String and character
friend String operator+ (const String&, const char*)    // Concat a String and C-string
friend String operator+ (char, const String&)           // Concat a character and String
friend String operator+ (const char*, const String&)    // Concat a C-string and String
```

Logical Operators
-----------------
All argument permutations in concatenation are repeated here, also.
```
friend bool operator== (const String&, const String&)  // Equality
friend bool operator!= (const String&, const String&)  // Non-Equality
friend bool  operator< (const String&, const String&)  // Less-than Inequality
friend bool  operator> (const String&, const String&)  // Greater-than Inequality
friend bool operator<= (const String&, const String&)  // Less-than or Equailty
friend bool operator>= (const String&, const String&)  // Greater-than or Equality
```

