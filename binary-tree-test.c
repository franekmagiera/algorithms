#include "binary-tree.h"
#include "compare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char * name;
    char * surname;
} Person;

void printPerson(const void * p) 
{
    const Person * p2 = (Person *) p;
    printf("----------------------------\n");
    printf("Name:\t\t%12s\n", p2->name);
    printf("Surname:\t%12s\n", p2->surname);
    printf("----------------------------\n");
}

void printDouble(const void * a)
{
    const double * x = (const double *) a;
    printf("%f", *x);
}

int comparePerson(const void * a, const void * b)
{
    const Person * p1 = (Person *) a;
    const Person * p2 = (Person *) b;
    return strcmp(p1->surname, p2->surname);
}

int main()
{
   Person p1 = {"Joan", "Jett"};
   Person p2 = {"Gwen", "Stefani"};
   Person p3 = {"Bob", "Dylan"};
   Person p4 = {"Patti", "Smith"};
   Person p5 = {"Keith", "Richards"};
   Person p6 = {"Eric", "Clapton"};
   Person persons[6] = {p1, p2, p3, p4, p5, p6};
   double doubles[15] = {5.2, -51.2, 12.2, -3.3, 0.1, 0.01, 0.001, -123.22, 12, 1, 2, 3, -1, 1.4, 1.5};
   btNode * root;
   initBt(&root);
   isBtEmpty(root) ? printf("Binary tree is empty.\n") : printf("Binary tree is not empty.\n");
   for (int i = 0; i < 6; i++) {
       insertBtElement(&root, persons+i, sizeof(Person), comparePerson);
   }
   isBtEmpty(root) ? printf("Binary tree is empty.\n") : printf("Binary tree is not empty.\n");
   inorderPrint(root, printPerson);
   printf("----------------------------\n");
   printf("----------------------------\n\n");
   Person lookingFor = {"Eric", "Clapton"};
   btNode * node = treeSearch(root, &lookingFor, comparePerson);
   Person * found = node->element;
   found->name = "Eric Patrick";
   inorderPrint(root, printPerson);
   freeBt(&root);

   isBtEmpty(root) ? printf("Binary tree is empty.\n") : printf("Binary tree is not empty.\n");
   for (int i = 0; i < 15; i++)
       insertBtElement(&root, doubles+i, sizeof(double), compareDoubles);
   inorderPrint(root, printDouble);
   void * dest = malloc(sizeof(double));
   if (dest == NULL)
       exit(EXIT_FAILURE);
   double searching = 1.5;
   iterativeTreeSearch(root, &searching, &dest, sizeof(double), compareDoubles);
   printf("Got a copy of %f\n",*((double *)dest));
   free(dest);
   freeBt(&root);
   return 0;
}

