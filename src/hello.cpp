#include <string>

using namespace std;

std::string hello() {
   return "Hello World!";
}

int strcmp_case_insensitive (string s1, string s2, bool skip_spaces = false) { //Define default boolean in parameter so I have argument flexibility

   int i = 0; //Index for s1
   int j = 0; //Index for s2


   //This while loop compares each string character
   while (i < s1.length() && j < s2.length()){ //Loops if the shortest string length is greater than current index i

      if (skip_spaces) { //Only skips spaces if the user wants to
         while (i < s1.length() && s1[i] == ' ') { //Skips spaces in s1
            i++;
         }
         while (j < s2.length() && s2[j] == ' ') { //Skips spaces in s2
            j++;
         }

         if (i == s1.length() || j == s2.length()) { //Avoids an out-of-bounds error, skip the rest of this iteration and the loop will end naturally
            continue; //Goes back to the main loop condition, lines below will not be checked
         }
      }

      // Force to case-insensitive comparison
      char c1 = tolower(s1[i]);
      char c2 = tolower(s2[j]);

      if (c1 == c2) { //Continue looping over the strings
         i++;
         j++;
      } else if (c1 < c2) {
         return -1;
      } else {
         return 1;
      }
   } //While loop ends here

   //After the loop: check string lengths since the function will only
   //Run these lines if the strings have been equal thus far

   if (skip_spaces) { //Ensures trailing spaces don’t make two otherwise equal strings compare as different lengths
      while (i < s1.length() && s1[i] == ' ') { //Skips spaces in s1
         i++;
      }
      while (j < s2.length() && s2[j] == ' ') { //Skips spaces in s2
         j++;
      }
   }

   if (i == s1.length() && j == s2.length()) { //Both strings are of equal length
      return 0;
   } else if (i < s1.length()) { //s1 has leftover characters; it is longer than s2
      return 1;
   } else { //s2 has leftover characters; it is longer than s1
      return -1;
   }
}//End of strcmp_case_insensitive(string s1, string s2)