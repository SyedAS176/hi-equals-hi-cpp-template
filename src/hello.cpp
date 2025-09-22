#include <string>

using namespace std;

std::string hello() {
   return "Hello World!";
}

int string_compare(std::string s1, std::string s2) {

   int i = 0; //Keeps the while loop running

   while (i < s1.length() && i < s2.length()){
      char c1 = tolower(s1[i]);
      char c2 = tolower(s2[i]);
   }

}