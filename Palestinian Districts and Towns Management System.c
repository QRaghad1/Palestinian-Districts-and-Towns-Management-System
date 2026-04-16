
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct town{
char tName[20];
int tPopulation;
struct town* previous;
struct town* next;
};
struct district{
char dName[20];
int dPopulation;
struct district* previous;
struct district* next;
struct town* firstTown;
};
struct character{
char c; // alphabet character
struct district* firstDistrict;
};
typedef struct town* Town;
typedef struct district* District;
typedef struct character* Character;

// define global variables
Character characters[54];
char strings[200][50];
char dist[200][20];
char extendedDist[200][20];
char town[200][20];
char pop[200][20];
char afterDeletion[100][50];
char extendedStrings[100][50];
char line[50];
int count=0;
int numDist=0;
int numTown;
char c;
int op;
int x;
int countDist;
int isLoaded=0;
int isSorted=0;
int isSortedT=0;
char nameofDis[20];
char nameofTown[20];
int townPopulation;
District unsortedList;
District extendedUnsortedList;
District extendedSortedList;
District AfterSorting;
void loadFile();
void printLodedInfo(District L);
void sort();
void radixSort(District L);
void copyTwoLists(District L1,District l2);
void sortTown(District L);
void printSortedInfo(District L);
void addDist(District L,char name[]);
void addTown(District L,char name[],char distName[],int pop);
void deleteTown(char name[],District L);
void deleteDistrict(District L,char name[]);
int calculatePalestinePOP(District L);
int minTownPop(District L);
int maxTownPop(District L);
void printDistAndPOP();
void changeTownPOP();
void saveToFile(District L);
void displayMenu();
void deleteList(Character L);
void deleteList1(District L);
int countNumberOfDistrict(District L);
District findDist(char name[],District L);
District make_Empty(District L);
void countPopulation(District L);
Town findTown(District L,char name[]);
District findDistCotainTown(District L,char name[]);
int isEmpty(Character L);
int isEmpty1(District L);
void makeArrayOfChar();
void Insert(Character L,char strings[]);
void makeArrayOfChar();
Character creatCharNode(Character C);
int maxDigit(District L);
void extendString(char name[],int max,int length);
void deleteCharacter(char str[], char ch);
int countNumberOfDistrict(District L);
void freeLists();
int main()
{

unsortedList=make_Empty(unsortedList);
extendedUnsortedList=make_Empty(extendedUnsortedList);
AfterSorting=make_Empty(AfterSorting);
extendedSortedList=make_Empty(extendedSortedList);






    do{

    printf("Enter a number to choose operation:\n");
   displayMenu();
   scanf("%d",&op);
   printf("\n");

   switch(op){
case 1:
    if(isLoaded){
        printf("the file is already loaded choose another operation\n");
    }else{

    loadFile();
    numDist=count/3;


   for(int i=0;i<numDist;i++){
     addDist(unsortedList,dist[i]);
     addTown(unsortedList,town[i],dist[i],atoi(pop[i]));

    }

     countDist=countNumberOfDistrict(unsortedList);

    }

    break;
case 2:
    if(isLoaded){
       printLodedInfo(unsortedList);

    }else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }


    break;
case 3:
     if(isLoaded){
      if(isSorted==0){
     deleteList1(extendedUnsortedList);
     District p=unsortedList->next;
    for(int i=0;i<countDist;i++){
    strcpy(extendedDist[i],p->dName);
    extendString(extendedDist[i],maxDigit(unsortedList),strlen(p->dName));
    addDist(extendedUnsortedList,extendedDist[i]);
    p=p->next;
    }


       radixSort(extendedUnsortedList);
       p=extendedSortedList->next;
//delete $ from districts name
 for(int i=0;i<countDist;i++){
  strcpy(afterDeletion[i],p->dName) ;
  deleteCharacter(afterDeletion[i], '$');
    p=p->next;

 }
 //add sorted districts and towns to after sorting list
 deleteList1(AfterSorting);
 p=unsortedList->next;
 for (int i = 0; i < countDist;  ++i ) {
    addDist(AfterSorting,afterDeletion[i]);

   while(p!=NULL) {

        if (strcmp(afterDeletion[i], p->dName) == 0) {

            Town t=p->firstTown;
            while(t!=NULL){
             addTown(AfterSorting,t->tName,p->dName,t->tPopulation);
             t=t->next;
            }
        }
        p=p->next;
    }
   p=unsortedList->next;
 }
 deleteList1(unsortedList);
 copyTwoLists(AfterSorting,unsortedList);


 printf("the districts have been sorted\n");
      }
      else{
        printf("the districts are already sorted\n");
      }

    }
    else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }


    break;
case 4:
    if(isLoaded){
            if(isSortedT==0){
             sortTown(unsortedList);
        printf("the towns have been sorted\n");
            }else{
                printf("the towns are already  sorted\n");
            }

    }
    else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }
    break;
case 5:
    if(isLoaded){
        if(isSorted && isSortedT){
             printSortedInfo(unsortedList);
        }
        else{
        printf("the list  not sorted yet \n");
        }

    }

    else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }
    break;
case 6:
if(isLoaded){

    printf("enter the name of district to add: ");
  getchar();//to delete the new line character
   scanf("%[^\n]", nameofDis);//read until new line char
   if(findDist(nameofDis,unsortedList))
      printf("the district is already in the list \n");
   else{

    addDist(unsortedList,nameofDis);//add district to sorted districts list
    printf("the district added \n");
    //sorting list after adding

    countDist++;
     deleteList1(extendedUnsortedList);
     District p=unsortedList->next;
    for(int i=0;i<countDist;i++){
    strcpy(extendedDist[i],p->dName);
    extendString(extendedDist[i],maxDigit(unsortedList),strlen(p->dName));
    addDist(extendedUnsortedList,extendedDist[i]);
    p=p->next;
    }
       radixSort(extendedUnsortedList);
       p=extendedSortedList->next;
//delete $ from districts name
 for(int i=0;i<countDist;i++){
  strcpy(afterDeletion[i],p->dName) ;
  deleteCharacter(afterDeletion[i], '$');
    p=p->next;

 }
 //add sorted districts and towns to after sorting list
 deleteList1(AfterSorting);
 p=unsortedList->next;
 for (int i = 0; i < countDist;  ++i ) {
    addDist(AfterSorting,afterDeletion[i]);

   while(p!=NULL) {

        if (strcmp(afterDeletion[i], p->dName) == 0) {

            Town t=p->firstTown;
            while(t!=NULL){
             addTown(AfterSorting,t->tName,p->dName,t->tPopulation);
             t=t->next;
            }
        }
        p=p->next;
    }
   p=unsortedList->next;
 }
 deleteList1(unsortedList);
 copyTwoLists(AfterSorting,unsortedList);

   }
}else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }

    break;
case 7:
    if(isLoaded){
        printf("enter the name of town to add and district to add to and the population of this town:\n ");
    printf("District: ");
    getchar();
   scanf("%[^\n]", nameofDis);
    getchar();
    if(!findDist(nameofDis,unsortedList))
        printf("the district does not exist in the list\n");
    else{
    printf("Town: ");
    scanf("%[^\n]",nameofTown);
    getchar();
    if(findTown( unsortedList,nameofTown)){
        printf("the town already exists \n");
    }else{
    printf("Population: ");
    scanf("%d",&townPopulation);
    addTown(unsortedList,nameofTown,nameofDis,townPopulation);
     printf("the town added\n");

    }}
    }else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }

 isSortedT=0;

    break;
case 8:
    if(isLoaded){
      printf("enter town to delete :");
    getchar();
    scanf("%[^\n]",nameofTown);
    getchar();
    if(findTown(unsortedList,nameofTown)){
      deleteTown(nameofTown,unsortedList);
      numTown--;
      printf("the town deleted \n");
    }else{
    printf("town not found \n");
    }

    }else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }


    break;
case 9:
    if(isLoaded){
    printf("enter district to delete :");
    getchar();
    scanf("%[^\n]",nameofDis);
    if(findDist(nameofDis,unsortedList)){
    deleteDistrict(unsortedList, nameofDis);
    countDist--;
    printf("the district deleted \n");
    }else{
    printf("district not found\n");
    }
    }


    else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }
    break;
case 10:
    if(isLoaded){
      printf("the population of Palestine  : %d \n",calculatePalestinePOP(unsortedList));
      printf("the max population  : %d \n",maxTownPop(unsortedList));
      printf("the min population  : %d \n",minTownPop(unsortedList));

    }else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }

    break;

case 11:
    if(isLoaded){
        printDistAndPOP(unsortedList);
    }else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }

    break;
case 12:
  if(isLoaded){
    printf("enter the town name :");
    getchar();
    scanf("%[^\n]",nameofTown);
    if(findTown(unsortedList,nameofTown)!=NULL){
      printf("enter the new population: ");
    scanf("%d",&x);
     changeTownPOP(unsortedList,nameofTown,x);
    }
    else{
        printf("town not found \n");
    }
  }else{
        printf("the file not loaded yet if you want to load the file choose 1:\n");
    }


    break;
case 13:
    if(isLoaded==0){
 printf("the file not loaded yet if you want to load the file choose 1:\n");
    }
    else{
    saveToFile(unsortedList);
    printf("the file is saved successfully \n");

    }

    break;
case 14:
    freeLists();
    printf("thank you :)");
    break;
default:
     printf("invalid operation.Try different number:\n");

}}while(op!=(14));
return 0;
}
void displayMenu(){

printf("1. Load the input file (Palestinian districts and their town with population).\n");
printf("2. Print the loaded information before sorting (as in the input file format).\n");
printf("3. Sort the districts alphabetically using Radix sort.\n");
printf("4. Sort the towns for each district based on population in ascending order.\n");
printf("5. Print the sorted information.\n");
printf("6. Add a new district to the list of sorted districts (and sort the list).\n");
printf("7. Add a new town to a certain district.\n");
printf("8. Delete a town from a specific district.\n") ;
printf("9. Delete a complete district.\n");
printf("10.Calculate the population of Palestine, the max and min town population.\n");
printf("11.Print the districts and their total population (without towns details).\n");
printf("12.Change the population of a town.\n");
printf("13.Save to output file.\n");
printf("14.Exit.\n");

}
//function to load file and store it contents into strings
void loadFile(){
 FILE *in;

    in = fopen("districts.txt", "r");
    if (in == NULL) {
        printf("Error opening file.\n");
        exit(1) ;// Exit program
    }


 int s=0;
 while(fgets(line,sizeof(line),in)!=NULL && !feof(in)){ //read a line from the file check if the line has been read successfully and if it does not reach the end of the file
char* token = strtok(line,"|");//divide the line by
   while(token  != NULL ){
  strcpy(strings[s],token); // copy  to string

  //printf("%s ",strings[s]);
  token=strtok(NULL,"|");
s++;
  }

  }
  fclose(in);

  int m=0;
  //printf("%d ",s);
  count=s;
  //store each of district,town and population in different strings
for(int i=0;i<s;i+=3){

   strcpy(dist[m],strings[i]) ;
   strcpy(town[m],strings[i+1]) ;
   strcpy(pop[m],strings[i+2]) ;
   m++;

}
isLoaded=1; //the file is loaded
printf("the file is successfully loaded \n");
}
//function to find a certain district in the list
District findDist(char name[],District L){
  District p=L->next;

  while(p!=NULL){
        if(strcmp(p->dName,name)==0)
           return p;
    p=p->next;
  }
  return NULL;
  }

//add a district to list of districts
void addDist(District L,char name[]){
 if(L==NULL){ //check if the list is not exist
    printf("the list not found");
 }

 else{
 if(findDist(name,L)==NULL){
    District newDist=(District)malloc(sizeof(struct district));
    if(newDist==NULL){ //check if memory allocation failed
       printf("no space");
    }

    else{
    strcpy(newDist->dName,name);
    newDist->dPopulation=0;
    newDist->next=NULL;
    newDist->firstTown=NULL;
    District p=L;
    while(p->next!=NULL)//find last
        p=p->next;

   newDist->previous=p;
    p->next=newDist;

    }

 }
 }

  }
  //function to add town to a specific district(at last)
void addTown(District L,char name[],char distName[],int x){
District p=L->next;
//find the district
while(p!=NULL && strcmp(p->dName,distName)!=0){
     p=p->next;
       }
       //if the district exists
       if(p!=NULL){
        Town town =(Town)malloc(sizeof(struct town));
        if(town==NULL){//check if memory allocation failed
            printf("no enough space");
            return;
        }

       if(p->firstTown==NULL){
        p->firstTown=town;
        strcpy(town->tName,name);
        town->tPopulation=x;
        town->next=NULL;
        town->previous=NULL;
       }
       else{
      Town last=p->firstTown;
      while(last->next!=NULL)
           last=last->next;

            strcpy(town->tName,name);
            town->tPopulation=x;
            town->next=NULL;
            town->previous=last;
            last->next=town;

       }
       }
       p->dPopulation=p->dPopulation+x;
}
//function to print the information as in the file input
void printLodedInfo(District L){
 for(int i=0;i<numDist;i++){
    printf("%s|%s|%s \n",dist[i],town[i],pop[i]);
 }

}
//print the sorted list
void printSortedInfo(District L){
District p=L->next;
   Town town;
   if(p==NULL){ //check if the list is empty
    printf("empty linked list \n");
   }

   else{
    while(p!=NULL){
       printf("%s District,Population=%d \n",p->dName, p->dPopulation);
       town=p->firstTown;
      while(town!=NULL){
        printf("   %s %d\n",town->tName,town->tPopulation);
        town=town->next;
      }
      p=p->next;
    }
}
}
//function to create the head of the list
District make_Empty(District L){
    L=(District)malloc(sizeof(struct district));
  if(L==NULL){//check if memory allocation failed
    printf("out of memory");
  }

    else{
    L->next=NULL;
    L->previous=NULL;
    L->firstTown=NULL;

    }


  return L;

 }
 //function to calculate the number of districts in the list
 int countNumberOfDistrict(District L){
int count=0;
District p=L->next;
while(p!=NULL){
    count++;
    p=p->next;
}


return count;
}
//function to calculate the population of the districts
void countPopulation(District L){
District p=L->next;
Town town;

while(p!=NULL){
   int sum=0;
town=p->firstTown;
   while(town!=NULL){
    sum+=town->tPopulation;
    town=town->next;
}
p->dPopulation=sum;


p=p->next;
}

}
//function to find a certain town in the list
 Town findTown(District L,char name[]){
 District p= L->next;
 Town t;
while(p!=NULL){
   t=p->firstTown;
    while(t!=NULL){
      if(strcmp(t->tName,name)==0)
            return t;
      t=t->next;
    }
    p=p->next;
   }

   return NULL;
}
//find a district that contain a specific town
District findDistCotainTown(District L,char name[]){
District p= L->next;
 Town t;
while(p!=NULL){
   t=p->firstTown;
    while(t!=NULL){
      if(strcmp(t->tName,name)==0)
          return p;
      t=t->next;
    }
    p=p->next;
   }
   return NULL;
}


//  function to delete a certain town
void deleteTown(char name[],District L){
Town Find=findTown(L,name);
District Dist=findDistCotainTown(L,name);
if(Find==NULL ||Dist==NULL){//check if the town exist
    return;
}
   Dist->dPopulation=Dist->dPopulation-Find->tPopulation;
   if(Find->next!=NULL){
    Find->next->previous=Find->previous;
   }

   if(Find->previous==NULL){//if it is the first town
    Dist->firstTown=Find->next;
   }else{
   Find->previous->next=Find->next;
   }




free(Find);

}
//delete a district and its towns
void deleteDistrict(District L,char name[]){
District p=findDist(name,L);
if(p!=NULL){
   Town t=p->firstTown;
   p->firstTown=NULL;
while(t!=NULL){
 Town temp=t;
 t=t->next;
 free(temp);

}
if(p==L->next){
   L->next=p->next;
}

else{
    p->previous->next=p->next;
}
if(p->next!=NULL){
   p->next->previous=p->previous;
}


   free(p);
}
}
//add all district populations
int calculatePalestinePOP(District L){
District p=L->next;
countPopulation(L);//count population for each dist
int sum=0;
while(p!=NULL){
  sum=sum+(p->dPopulation);
  p=p->next;
}
return sum;
}
//find the town with maximum population
int maxTownPop(District L){
District p=L->next;
Town town;
Town  maxTown=p->firstTown;
int max=p->firstTown->tPopulation;
while(p!=NULL){
 town=p->firstTown;
   while(town!=NULL){
    if(town->tPopulation>max){
       max=town->tPopulation;
       maxTown=town;
    }

    town=town->next;
}
p=p->next;
}
printf("The town that has the max population:%s\n",maxTown->tName);
return max;
}
//find the town with minimum population
int minTownPop(District L){
District p=L->next;
Town town;
Town  minTown=p->firstTown;
int min=p->firstTown->tPopulation;
while(p!=NULL){
town=p->firstTown;
   while(town!=NULL){
    if(town->tPopulation<min){
        min=town->tPopulation;
        minTown=town;
    }

    town=town->next;
}
p=p->next;
}
printf("The town that has the min population:%s\n",minTown->tName);
return min;
}
//print Districts with population
void printDistAndPOP(District L){
    District p=L->next;
    while(p!=NULL){
     printf("District: %s  ",p->dName) ;
     printf(",Population: %d",p->dPopulation);
     printf("\n");
     p=p->next;
    }

}
//change population to a specific town
void changeTownPOP(District L,char name[],int x){
Town town=findTown(L,name);
town->tPopulation=x;
}
//function  to sort districts according to radix sort
void sortList(){
District p;
deleteList1(extendedSortedList);
    for(int i=0; i<54; i++){
        p=characters[i]->firstDistrict;
    if(p==NULL){ //empty list
            continue;
        }
        while(p!=NULL){
            addDist(extendedSortedList, p->dName);
            p=p->next;
        }
         deleteList(characters[i]);
    }

}

//sort the districts using radix sort
void radixSort(District L){

copyTwoLists(extendedUnsortedList,extendedSortedList);

if(extendedSortedList==NULL)
    printf("the list not found  ");
    else if(isEmpty1(extendedSortedList))
        printf("list is Empty");
else if(extendedSortedList->next->next==NULL)
    printf("the list has one element   ");
    else{
        makeArrayOfChar();//create an array of character
        District p=extendedSortedList->next;//point to the first district
        int max=maxDigit(extendedSortedList);

        char read;
        int count=max-1,m=0;
        for(int i=0;i<max;i++){
            while(p!=NULL){
                read=p->dName[count];
             while(read!=(characters[m]->c)){//find the character to add district to it
                m++;
             }
             Insert(characters[m],p->dName);//add the district to the character list
             m=0;
             p=p->next; //move to next district

            }
          count--; //move to the previous character in the district name
          sortList();
          p=extendedSortedList->next;//back to the first district

        }
}
isSorted=1;
}
//function to copy list to another
void copyTwoLists(District L1, District L2){ //L1->source, L2->distination
    District p=L1->next;
Town t;
    while(p!=NULL){
        addDist(L2,p->dName);
       t=p->firstTown;
       while(t!=NULL){
        addTown(L2,t->tName,p->dName,t->tPopulation);
        t=t->next;
       }
        p=p->next;
    }

}
//delete all the character list
void deleteList(Character L){

    if(L==NULL || isEmpty(L)){
       return;
    }


    District p=L->firstDistrict;
    L->firstDistrict=NULL;
    District temp;

    while(p!=NULL){
        temp=p->next;
        free(p);
        p=temp;
    }


}
//delete all the district list
void deleteList1(District L){

    if(L==NULL ||isEmpty1(L))
        return;


    District p=L->next;
    L->next=NULL;
    District temp;

    while(p!=NULL){
        temp=p->next;
        free(p);
        p=temp;
    }

    return;

}
int isEmpty(Character L){

    return(L->firstDistrict==NULL);

}
int isEmpty1(District L){

    return(L->next==NULL);

}
//creat an array of characters
void makeArrayOfChar(){
  characters[0]=creatCharNode(characters[0]);
  characters[0]->c='$';
characters[1]=creatCharNode(characters[0]);
  characters[1]->c=' ';

int i=0;
char digit='A';
for(i=2;i<28;i++){
characters[i]=creatCharNode(characters[i]);
characters[i]->c=digit;
digit++;
}
digit='a';
for(i=28;i<54;i++){
characters[i]=creatCharNode(characters[i]);
characters[i]->c=digit;
digit++;
}

}
//find the  length of tallest district
int maxDigit(District L) {
    District p=L->next;
    int max=strlen(p->dName);
    while(p!=NULL){
        if(strlen(p->dName)>max)
            max=strlen(p->dName);
        p=p->next;
    }


    return max;
}

//extend string bu $
void extendString(char name[],int max,int length){
if(length<max){
    for(int i=length;i<max;i++){
        name[i]='$';
    }
}
name[max]='\0';
}
//insert a node to character list
void Insert(Character L, char strings[]){

    District Node=(District)malloc(sizeof(struct district));
    strcpy(Node->dName,strings);
    Node->next=NULL;

    if(L==NULL){
        printf("Linked List Not Found..\n");
        return;
    }else if(Node==NULL){
        printf("Out of space..\n");
        return;
    }else if(isEmpty(L)){
        Node->next=NULL;
        L->firstDistrict=Node;
        return;
    }
//insert last
    District temp = L->firstDistrict;

    while(temp->next != NULL){
        temp=temp->next;
    }

    Node->next=temp->next;
    temp->next=Node;

}
//create  node for characters
Character creatCharNode(Character C){
 C=(Character)malloc(sizeof(struct character));
if(C==NULL)
    printf(" error memory allocation");
else{

    C->firstDistrict=NULL;
}
return C;
}
//delete a character from a string by copy all characters except it
void deleteCharacter(char str[], char ch) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
//sort town by population in ascending order
void sortTown(District L){
District p=L->next;
while(p!=NULL){
    Town currentTown=p->firstTown;
    while(currentTown!=NULL){
        Town minTown=currentTown;
        Town nextTown=currentTown->next;
        while(nextTown!=NULL){
            if(nextTown->tPopulation<minTown->tPopulation){
                minTown=nextTown;
                }
                nextTown=nextTown->next;
            }
            //switshing
            int tempPOP=currentTown->tPopulation;
            currentTown->tPopulation=minTown->tPopulation;
            minTown->tPopulation=tempPOP;

            char tempName[20];
            strcpy(tempName,currentTown->tName);
            strcpy(currentTown->tName,minTown->tName);
            strcpy(minTown->tName,tempName);
            currentTown=currentTown->next;
        }
        p=p->next;
    }
isSortedT=1;
}

//print sorted list to out put file
void saveToFile(District L){
FILE* output;
output=fopen("sorted_districts.txt","w");
if(output==NULL){
    printf("error in opening file");
    return;
}

  District p=L->next;
while(p!=NULL){
    fprintf(output,"District %s,Population= %d\n",p->dName,p->dPopulation);
  Town t=p->firstTown;
    while(t!=NULL){
     fprintf(output,"%s,%d\n",t->tName,t->tPopulation);
     t=t->next;
    }
    fprintf(output,"\n");
    p=p->next;
}
fclose(output);
}
//free all used lists
void freeLists(){
if(isEmpty1(unsortedList)){
    deleteList1(unsortedList);
}
if(isEmpty1(extendedUnsortedList)){
    deleteList1(extendedUnsortedList);
}
if(isEmpty1(extendedSortedList)){
    deleteList1(extendedSortedList);
}
if(isEmpty1(AfterSorting)){
    deleteList1(AfterSorting);
}
if(unsortedList!=NULL){
 free(unsortedList);
}
if(extendedUnsortedList!=NULL){
 free(extendedUnsortedList);
}
if(extendedSortedList!=NULL){
 free(extendedSortedList);
}
if(AfterSorting!=NULL){
 free(AfterSorting);
}
int i=0;
while(i<54){
 if(!isEmpty(characters[i])) {
    deleteList(characters[i]);
 }
 i++;
}
}
