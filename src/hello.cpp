#include <string>

using namespace std;

std::string hello() {
   return "Hello World!";
}

int strcmp_case_insensitive (string s1, string s2, bool skip_spaces = false) {

   int i = 0; //Keeps the while loop running

   while (i < s1.length() && i < s2.length()){ //Loops if the shortest string length is greater than current index i
      char c1 = tolower(s1[i]); //Force lower case since we
      char c2 = tolower(s2[i]); //Want a case-insensitive function

      if (c1 == c2) { //Continue looping over the strings
         i++;
      } else if (c1 < c2) {
         return -1;
      } else {
         return 1;
      }
   } //While loop ends here

   //After the loop: check string lengths since the function will only
   //Run these lines if the strings have been equal thus far

   if (s1.length() == s2.length()) {
      return 0;
   } else if (s1.length() > s2.length()) {
      return 1;
   } else {
      return -1;
   }
}//End of strcmp_case_insensitive(string s1, string s2)