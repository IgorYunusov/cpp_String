#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <iostream>

/*! @class String <iostream>
 *  @brief A custom String implementation
 *
 *  A custom C++ implementation of a String object for pedagogical purposes.
 *  Is efficient for specifying the length of your String and does not depend
 *  on the use of a NULL termination. 
 *
 *  @author Bryan Goodrich
 *  @version 0.2
 *  @date 2013-12-13
 *  @invariant String data will always point to NULL or a valid address.
 *  @invariant String length will always indicate amount of allocated space.
 */
class String
{
    char*    data;    /*!< The ASCII characters that comprise the String */
    unsigned length;  /*!< The number of characters allocated in data */

public:

    /*! 
     *  @brief Empty String Constructor.
     *  @post String length is set equal to 0.
     */
    String ( );

    /*! 
     *  @brief Single-character String Constructor.
     *  @param[in] c A char literal.
     *  @post String data equals @a c and String length equals 1.
     */
    String (char c);

    /*! 
     *  @brief char* String Constructor
     *  @param[in] c A char* null-terminated string.
     *  @post String length equals @code{.cpp}strlen(c)@endcode.
     *  @post String data equals @a c allocated values, except the null-terminator.
     */
    String (const char* c);

    /*! 
     *  @brief Copy String Constructor
     *  @param[in] s A String instance.
     *  @post This String will be identical to String @a s.
     */
    String (const String& s);

    /*! 
     *  @brief Default String Destructor
     *  @post String data is deleted.
     */
    ~String ( );

    /*! 
     *  @brief String length.
     *  @return Value in String @c length.
     */
    unsigned len ( ) const;

    /*! 
     *  @brief String index of @a c.
     *  @param[in] c A char literal.
     *  @return The index of @a c in String, if exists; -1 otherwise.
     */
    int index (char c) const;

    /*! 
     *  @brief Converts lowercase alphabetic characters to uppercase.
     *  @param[in] first Starting index of String to change case.
     *  @param[in] last  Ending index of String to change case.
     *  @pre @a first is less than or equal to @a last and @a last is less than
     *       or equal to String length.
     *  @post All lowercase alphabetic characters in String data greater than
     *        or equal to @a first, but less than @a last are uppercase.
     *  @throw int
     */
    void upcase (unsigned first, unsigned last);

    /*! 
     *  @brief Converts uppercase alphabetic characters to lowercase.
     *  @param[in] first Starting index of String to change case.
     *  @param[in] last Ending index of String to change case.
     *  @pre @a first is less than or equal to @a last and @a last is less than
     *       or equal to String length.
     *  @post All uppercase alphabetic characters in String data greater than
     *        or equal to @a first, but less than @a last are lowercase.
     *  @throw int
     */
    void downcase (unsigned first, unsigned last);

    /*! 
     *  @brief Toggles lowercase alphabetic characters to uppercase, and vice versa.
     *  @param[in] first Starting index of String to change case.
     *  @param[in] last  Ending index of String to change case.
     *  @pre @a first is less than or equal to @a last and @a last is less than
     *       or equal to String length.
     *  @post All lowercase alphabetic characters in String data greater than
     *        or equal to @a first, but less than @a last are uppercase, and
              all uppercase alphabetic characters in String data are lowercase.
     *  @throw int
     */
    void togglecase (unsigned first, unsigned last);

    //@{
    /*! 
     *  @brief Stream operators.
     *  @param so A stream object.
     *  @param s  A String object.

     *  @return Stream object containing String content.
     */
    friend std::ostream& operator<< (std::ostream& so, const String& s);
    friend std::istream& operator>> (std::istream& so,       String& s);
    //@}

    //@{
    /*! 

     *  @brief Access String character.
     *  @param j Index value in String.
     *  @pre @a j is less than String length.
     *  @return character at @a j index of String data.
     *  @throw int

     */
    char  operator[] (unsigned j) const;
    char& operator[] (unsigned j);
    //@}

    /*! 
     *  @brief Sets String value.
     *  @param[in] s A String object.
     *  @return A String reference to *this.
     *  @post String will be equivalent to @a s.
     */
    String& operator= (const String& s);

    /*! 
     *  @brief Append to String.
     *  @param[in] s A String object.
     *  @return A String reference to *this.
     *  @post String will equal the concatenation of itself with @a s.
     */
    String& operator+= (const String& s);

    //@{
    /*! 
     *  @brief String concatenation (addition).
     *  @param[in] lhs The left-hand operand String or String convertable.
     *  @param[in] rhs The right-hand operand String or String convertable.
     *  @return Copy of a String object.
     *  @post The String will be the concatenation of @a lhs and @a rhs.
     */
    friend String operator+ (const String& lhs, const String& rhs);
    friend String operator+ (const String& lhs, char          rhs);
    friend String operator+ (const String& lhs, const char*   rhs);
    friend String operator+ (char          lhs, const String& rhs);
    friend String operator+ (const char*   lhs, const String& rhs);
    //@}

    //@{
    /*! 
     *  @brief String equality
     *  @param[in] lhs The left-hand operand String or String convertable.
     *  @param[in] rhs The right-hand operand String or String convertable.
     *  @return True, if @a lhs and @a rhs have the same length, and each
     *          character in their String data are identical in both value
     *          and index. 
     */
    friend bool operator== (const String& lhs, const String& rhs);
    friend bool operator== (const String& lhs, char          rhs);
    friend bool operator== (const String& lhs, const char*   rhs);
    friend bool operator== (char          lhs, const String& rhs);
    friend bool operator== (const char*   lhs, const String& rhs);
    //@}

    //@{
    /*!
     *  @brief String inequality: Greater-than.
     *  @param[in] lhs The left-hand operand String or String convertable.
     *  @param[in] rhs The right-hand operand String or String convertable.
     *  @return True, if @a lhs is in dictionary order (Capitals-first) to
     *          @a rhs when comparing alphabetical characters or @a lhs is
     *          greater in ASCII value to @a rhs, in corresponding String
     *          data indices.
     */
    friend bool operator> (const String& lhs, const String& rhs);
    friend bool operator> (const String& lhs, char          rhs);
    friend bool operator> (const String& lhs, const char*   rhs);
    friend bool operator> (char          lhs, const String& rhs);
    friend bool operator> (const char*   lhs, const String& rhs);
    //@}

    //@{
    /*! 

     *  @brief String non-equality
     *  @param[in] lhs The left-hand operand String or String convertable.
     *  @param[in] rhs The right-hand operand String or String convertable.
     *  @return True, if @a lhs is not equal to @a rhs.
     *  @see String::operator==

     */
    friend bool operator!= (const String& lhs, const String& rhs);
    friend bool operator!= (const String& lhs, char          rhs);
    friend bool operator!= (const String& lhs, const char*   rhs);
    friend bool operator!= (char          lhs, const String& rhs);
    friend bool operator!= (const char*   lhs, const String& rhs);
    //@}

    //@{
    /*! 
     *  @brief String inequality: Less-than.
     *  @param[in] lhs The left-hand operand String or String convertable.
     *  @param[in] rhs The right-hand operand String or String convertable.
     *  @return True, if @a lhs is neither equal to, nor greater-than @a rhs.
     *  @see String::operator==,String::operator>
     */
    friend bool operator< (const String& lhs, const String& rhs);
    friend bool operator< (const String& lhs, char          rhs);
    friend bool operator< (const String& lhs, const char*   rhs);
    friend bool operator< (char          lhs, const String& rhs);
    friend bool operator< (const char*   lhs, const String& rhs);
    //@}

    //@{
    /*! 
     *  @brief String inequality: Less-than or equal
     *  @param[in] lhs The left-hand operand String or String convertable.
     *  @param[in] rhs The right-hand operand String or String convertable.
     *  @return True, if @a lhs is not greater-than @a rhs.
     *  @see String::operator>
     */
    friend bool operator<= (const String& lhs, const String& rhs);
    friend bool operator<= (const String& lhs, char          rhs);
    friend bool operator<= (const String& lhs, const char*   rhs);
    friend bool operator<= (char          lhs, const String& rhs);
    friend bool operator<= (const char*   lhs, const String& rhs);
    //@}

    //@{
    /*! 
     *  @brief String inequality: Greater-than or equal
     *  @param[in] lhs The left-hand operand String or String convertable.
     *  @param[in] rhs The right-hand operand String or String convertable.
     *  @return True, if @a lhs is greater-than or equal to @a rhs.
     *  @see String::operator>,String::operator==
     */
    friend bool operator>= (const String& lhs, const String& rhs);
    friend bool operator>= (const String& lhs, char          rhs);
    friend bool operator>= (const String& lhs, const char*   rhs);
    friend bool operator>= (char          lhs, const String& rhs);
    friend bool operator>= (const char*   lhs, const String& rhs);
    //@}
};

#endif // CUSTOM_STRING_H
