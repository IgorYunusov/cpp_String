#include "String.h"
#include <stdlib.h> // rand()
using namespace std;


char main_menu ()
{
  char res;

  cout << endl << endl << endl;
  cout << endl << "  ~~~  String Simulator   ~~~  ";
  cout << endl << endl;
  cout << "(0) Assign values to String s1, s2, and s3" << endl;
  cout << "(1) Toggle Case s1, Upcase s2[0, 4], and Downcase s3[2, 4]" << endl;
  cout << "(2) Copy s2 into s5 and set s2 = s2 + s4" << endl;
  cout << "(3) Find 'c' in s5, -1 if not found." << endl;
  cout << "(4) Add 'fooBlah' to s1" << endl;
  cout << "(5) Add Random character to s4" << endl;
  cout << "(6) Insert String into s5" << endl;
  cout << "(7) Perform Logical Comparisons" << endl;
  cout << "(8) Display Currently Registered Strings" << endl;
  cout << "(9) Exit simulation" << endl << endl << endl;
  cout << "Enter a selection (0-9): ";
  cin >> res;
  return res;
}



void DisplayStrings (const String& s1, const String& s2, const String& s3,
                     const String& s4, const String& s5)
{
  cout << endl << "--- Current Registered Strings --- " << endl;
  cout << "                   Length  Content" << endl;
  cout << "        String s1:      " << s1.len() << "  " << s1 << endl;
  cout << "        String s2:      " << s2.len() << "  " << s2 << endl;
  cout << "        String s3:      " << s3.len() << "  " << s3 << endl;
  cout << "        String s4:      " << s4.len() << "  " << s4 << endl;
  cout << "        String s5:      " << s5.len() << "  " << s5 << endl;
}



void AssignStrings (String& s1, String& s2, String& s3)
{
  // Assign s1 (random alphabet)
  unsigned N = rand() % 10; // Random length
  char c1[N];
  for (unsigned j=0; j<N; j++)
  {
    char c = (char)(rand() % 26 + 65);  // Random Alphabet
    c1[j]  = c;
  }
  
  // Assign s2 (random name)
  const char* names[10] = {"Alpha", "bob", "Joe", "chris", "Foo",
                           "foobar", "crystal", "Bart", "Bob", "Omega"};
  N = rand() % 10; // Random Name
  const char* c2 = names[N];
    
  // Assign s3 (random ASCII)
  N = rand() % 7; // Random length
  char c3[N];
  for (unsigned j=0; j<N; j++)
  {
    char c = (char)(rand() % 255); // Random ASCII
    c3[j]  = c;
  }
  
  s1 = c1;
  s2 = c2;
  s3 = c3;
}



void LogicalTests (const String& s1, const String& s2, const String& s3,
                   const String& s4, const String& s5)
{
  cout << endl << "*** Logical Tests ***" << endl;
  cout << "       s1 == s2?      " << ((s1 == s2) ? "True" : "False") << endl;
  cout << "       s1 != s2?      " << ((s1 != s2) ? "True" : "False") << endl;
  cout << "       s2 > s5?       " << ((s2 > s5)  ? "True" : "False") << endl;
  cout << "       s4 < s2        " << ((s4 < s2) ? "True" : "False") << endl;
  cout << "       s1 <= fooBlah? " << ((s1 <= "fooBlah") ? "True" : "False") << endl;
  cout << "       s4 >= C        " << ((s4 >= 'C') ? "True" : "False") << endl;
}



int main()
{
  bool isDone = false;
  char choice;
  String s1, s2, s3;
  String s4 = '\0';
  String s5;
  srand (443);
  
  
  do
  {
    char c = (char)(rand() % 26 + 65);
    choice = main_menu();
    try
    {
      switch(choice)
      {
        case '0': AssignStrings(s1, s2, s3); break;
        case '1': s1.togglecase(0, s1.len());
                  s2.upcase(0, 4);
                  s3.downcase(2, 4); break;
        case '2': s5 = s2; s2 += s4; break;
        case '3': cout << endl << "Find 'c' in s5: " << s5.index('c'); break;
        case '4': s1 = s1 + "fooBlah"; break;
        case '5': s4[0] = c; break;
        case '6': cout << endl << "Enter String into s5" << endl;
                  cout << "> ";
                  cin >> s5; break;
        case '7': LogicalTests(s1, s2, s3, s4, s5); break;
        case '8': DisplayStrings(s1, s2, s3, s4, s5); break;
        case '9': isDone = true; break;
        default: cout << "Invalid selection. Try again."; break;
      }
    }
    catch (int e) 
    {
      cout << "Error " << e << ": Index out of bounds" << endl;
    }
  } while(!isDone);

  return 0;
}

