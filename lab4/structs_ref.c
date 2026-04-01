#include <stdio.h>
#include <string.h>  //needed for strcpy (strings)

/*DEFINITION
   What is a Struct?
      Structures (also called structs) are a way to group several related variables into one place and under one name.
      Each variable in the structure is known as a member of the structure (or field).
      Unlike an array, a structure can contain many different data types (int, float, char...).

   When do you use a struct?
      Whenever a "thing" in your program naturally has multiple properties.
      Ask yourself: does this thing have several pieces of data that belong together?

   exp:
      A student has a name, age, grade → use a struct
      A book has a title, author, price → use a struct
      You just need to store one number → no need, use a plain int
*/


/*MEMORY
   When you declare a struct variable, C reserves one continuous block of memory big enough to hold all fields back to back.
   If s starts at address 100 and name is 50 bytes:
      name (50 bytes)  |  age (4 bytes)  |  grade (4 bytes)
      100                 150               154

   &s and &s.name point to the exact same address.
   The struct variable is just a label for the whole block.
   Each field has its own address inside that block.
*/


/* SYNTAX
   1. DEFINE the blueprint
      struct StructName {
         type field1;
         type field2;
      };                 (The semicolon after the closing brace is required.)

         => No variable is created yet. No memory used yet.

   2. CREATE a variable
      struct StructName variableName;

         => This is when memory is actually reserved.

   3. ASSIGN values to fields
      variableName.field = value;
      strcpy(variableName.field, "text");   => Strings cannot use = directly, you must use strcpy()

         => The dot means: go inside this variable, grab this field.

   4. READ a field
      printf("%d", variableName.field);

         => You always pick one field at a time, nothing is automatic.

   5. SHORTCUT: initialize at declaration
      struct Student s = {"Karim", 20, 15.5};

         => Fields fill in the same order they were defined.

   6. Copy Structures: assign one structure to another
      struct myStructure s1 = {13, 'B', "Some text"};
      struct myStructure s2;
      s2 = s1;

         => the values of s1 are copied to s2:

   7. Modify Values
      struct myStructure {
         int myNum;
         char myLetter;
         char myString[30];
      };

      int main() {
         struct myStructure s1 = {13, 'B', "Some text"};             => Create a structure variable and assign values to it

         s1.myNum = 30;
         s1.myLetter = 'C';
         strcpy(s1.myString, "Something else");                      => Modify values

         printf("%d %c %s", s1.myNum, s1.myLetter, s1.myString);     => Print values
         return 0;
      }
*/


//exp

//define the blueprint
struct Student {
   char name[50];  //string field (needs strcpy to assign)
   int age;       //int field (use = to assign)
   float grade;  //float field (use = to assign)
};

int main() {

   //create a variable
   struct Student s;   //at this point s exists in memory but fields are empty

   //fill in the fields
   strcpy(s.name,"mia");  //string => strcpy
   s.age= 19;
   s.grade= 15.5;

   //read fields
   printf("name: %s\n",s.name);
   printf("age: %d\n",s.age);
   printf("grade: %.2f\n",s.grade);

   //shortcut: declare and initialize in one line
   struct Student s2 = {"lynx", 21, 17.0};  //fields go in the same ORDER as defined in the struct

   printf("name: %s\n",s2.name);
   printf("age: %d\n",s2.age);
   printf("grade: %.2f\n",s2.grade);

   //array of structs: just like an array of ints, but each element is a struct
   struct Student students[3]= {
      {"mia", 19, 15.5},
      {"lynx", 21, 17.0},
      {"bob", 20, 13.0}
   };

   for (int i=0;i<3;i++) {  //printing the array of structs
      printf("%s age:%d grade:%.2f\n",
         //class[i] is one Student variable
         students[i].name,    //class[i].name is the name field of that student
         students[i].age,
         students[i].grade);
   }
   return 0;
}

/*quick reference
Define:
   struct Student { char name[50]; int age; float grade; };

Create variable:
   struct Student s;

Assign fields:
   strcpy(s.name,"text");   <= strings only
   s.age= 20;
   s.grade= 15.5;

Read fields:
   s.name    => use %s in printf
   s.age     => use %d in printf
   s.grade   => use %f or %.xf in printf (x E N*)

Shortcut initialization (same order as defined):
   struct Student s = {"mia", 19, 15.5};

Array of structs:
   struct Student class[3];
   class[0].age = 19;

Memory:
   &s == &s.name  (struct starts where first field starts)
   fields are continuous in memory, each has its own address
*/

/*even quicker reference hehehee:)
   define       struct Student { char name[50]; int age; float grade; };
   create       struct Student s;
   assign       strcpy(s.name, "text");   s.age = 19;   s.grade = 15.5;
   read         s.name  s.age  s.grade
   shortcut     struct Student s = {"mia", 19, 15.5};
   array        struct Student class[3];   class[0].age = 20;
*/