#include <string>
#include <cctype>

using namespace std;

std::string hello() {
   return "Hello World!";
}

int strcmp_case_insensitive (string s1, string s2, bool skip_spaces = false, int max_length = -1) { //Define default boolean in parameter so I have argument flexibility

   int max_len_s1 = s1.length();  //Default to full length of s1
   int max_len_s2 = s2.length();  //Default to full length of s2

   if (max_length != -1) {//If max_length is provided we need to stop at the requested length

      max_len_s1 = (s1.length() < max_length) ? s1.length() : max_length;  //Use the smaller of max_length and s1's length
      max_len_s2 = (s2.length() < max_length) ? s2.length() : max_length;  //Use the smaller of max_length and s2's length
   }

   int i = 0; //Index for s1
   int j = 0; //Index for s2

   //This while loop compares each string character
   while (i < max_len_s1 && j < max_len_s2){ //Loops if the shortest string length is greater than current index i

      if (skip_spaces) { //Only skips spaces if the user wants to
         while (i < max_len_s1 && s1[i] == ' ') { //Skips spaces in s1
            i++;
         }
         while (j < max_len_s2 && s2[j] == ' ') { //Skips spaces in s2
            j++;
         }

         if (i == max_len_s1 || j == max_len_s2) { //Avoids an out-of-bounds error, skip the rest of this iteration and the loop will end naturally
            continue; //Goes back to the main loop condition, lines below will not be checked
         }
      }

      //Check if both characters are digits; this is the start of number comparison in each string; only runs if characters in the string are digits
        if (isdigit(s1[i]) && isdigit(s2[j])) {
            int start_i = i; //Extract the number from s1
            while (i < max_len_s1 && isdigit(s1[i])) i++;
            int num1 = stoi(s1.substr(start_i, i - start_i));

            int start_j = j; //Extract the number from s2
            while (j < max_len_s2 && isdigit(s2[j])) j++;
            int num2 = stoi(s2.substr(start_j, j - start_j));

            //Compare the extracted numbers from the strings to each other
            if (num1 < num2) return -1; //We extract the whole number to avoid a false case of 10 < 9 which is not true
            if (num1 > num2) return 1; //Ex: 10 < 9 would be true if we compared individual digits
      } else { //Force to case-insensitive comparison; this runs assuming the previous code block did not find any numbers in the strings

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
      }
   } //While loop ends here

   if (max_length != -1) { //Limit the length of comparison to the max_length if provided
      if (i < max_length && j < max_length) {
         return (i == j) ? 0 : (i < j ? 1 : -1); //This notation avoid a headache of if-else statements, I used it above for max_lengths too
      }
   }

   if (skip_spaces) { //Ensures trailing spaces don’t make two otherwise equal strings compare as different lengths
      while (i < max_len_s1 && s1[i] == ' ') { //Skips spaces in s1
         i++;
      }
      while (j < max_len_s2 && s2[j] == ' ') { //Skips spaces in s2
         j++;
      }
   }

   //After the loop and skip spaces check: check string lengths since the function will only
   //Run these lines if the strings have been equal thus far
   if (i == max_len_s1 && j == max_len_s2) {
      return 0; //Both strings are of equal length
   } else if (i < max_len_s1) {
      return 1; //s1 has leftover characters; it is longer than s2
   } else {
      return -1; //s2 has leftover characters; it is longer than s1
   }
}//End of strcmp_case_insensitive(string s1, string s2)