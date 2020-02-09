#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define FILENAME "database.bin"

// -----Typedefs -------
typedef struct {
  char firstname[20];
  char famnamne[20];
  char pers_number[13]; // yyyymmddnnnc
}PERSON;

// Function declaration (to be extended)
PERSON input_record(void); // Reads in a person record.
void write_new_file(PERSON *inrecord); //Creates a file and writes a first record
void printfile(void); // print out all persons in the file
void search_by_name(int *option, char *name); // print out person if in list
void append_file(PERSON *inrecord); // appends a new person to the file
PERSON create_dummy(PERSON *inrecord);
void clear_stdin(void);
void printOptions();
void remove_extra_chars(char* string);
void remove_newline(char* string);

void clear_stdin(){
  while(getchar() != '\n'){
  }
}

void remove_newline(char* string){
  int length = strlen(string);
  if((length > 0) && (string[length-1] == '\n')){
    string[length-1] ='\0';
  }
}

void remove_extra_chars(char* string){
  int c;
  if (strchr(string, '\n') == NULL) {
    while ((c = getchar()) != EOF && c != '\n'){

    }
  }
}

PERSON input_record(){
  PERSON *person = (PERSON*)malloc(sizeof(PERSON));
  char temp[20];
  puts("\nEnter first name: ");
  fgets(temp, 20, stdin);
  remove_extra_chars(temp);
  remove_newline(temp);
  //strtok(temp, "\n");
  strlcpy(person->firstname, temp, sizeof(person->firstname));
  puts("Enter last name: ");
  fgets(temp, 20, stdin);
  remove_extra_chars(temp);
  remove_newline(temp);
  strlcpy(person->famnamne, temp, sizeof(person->famnamne));
  puts("Enter person number: ");
  fgets(temp, 13, stdin);
  remove_extra_chars(temp);
  remove_newline(temp);
  strlcpy(person->pers_number, temp, sizeof(person->pers_number));
  free(person);
  return *person;
}

void append_file(PERSON *inrecord){
  FILE* fileptr;
  fileptr = fopen(FILENAME, "ab");
  if (fileptr == NULL){
    puts("===>Error: unable to open file");
    exit(1);
  }
  // fwrite(const void *ptr, size_t size, size_t n, FILE *stream);
  // (pointer to start of data block, size of block, nr of block, file pointer)
  fwrite(inrecord, sizeof(PERSON), 1, fileptr);
  printf("\n===>%s added to file.\n", inrecord->firstname);
  fclose(fileptr);
}

void search_by_name(int *option, char *name){
  FILE *fileptr = fopen(FILENAME, "rb");
  PERSON *person = malloc(sizeof(PERSON));
  if(fileptr == NULL){
    puts("===>Error: Could not open file.");
    exit(1);
  }

  while(!feof(fileptr)){
    if(fread(person, sizeof(PERSON), 1, fileptr)){
      if (*option == 1){
        // Search via first name
        if (strcmp(person->firstname, name) == 0){
          printf("\nFirst name: %s\n", person->firstname);
          printf("Family name: %s\n", person->famnamne);
          printf("Person number: %s\n", person->pers_number);
        } 
      } else {
        // Search via family name
        if (strcmp(person->famnamne, name) == 0){
          printf("\nFirst name: %s\n", person->firstname);
          printf("Family name: %s\n", person->famnamne);
          printf("Person number: %s\n", person->pers_number);
        }
      }
      //person++;
    }
  }
  fclose(fileptr);
}

void write_new_file(PERSON *inrecord){
  FILE *fileptr;
  inrecord = (PERSON*) malloc(sizeof(PERSON));
  fileptr = fopen(FILENAME, "wb");
  if (fileptr == NULL){
    puts("===>Error: cannot create the file.");
    exit(1);
  }
  //create a dummy person
  *inrecord = create_dummy(inrecord);
  fwrite(inrecord, sizeof(PERSON), 1, fileptr);
  fclose(fileptr);
  printf("\n===>Created new file: %s\n", FILENAME);
}

PERSON create_dummy(PERSON *inrecord){
  strlcpy(inrecord->firstname, "Dummy", sizeof(inrecord->firstname));
  strlcpy(inrecord->famnamne, "Person", sizeof(inrecord->famnamne));
  strlcpy(inrecord->pers_number, "1234567890", sizeof(inrecord->pers_number));
  free(inrecord);
  return *inrecord;
}

void printfile(){
  FILE* fileptr;
  PERSON *person = malloc(sizeof(PERSON));
  fileptr = fopen(FILENAME, "rb");
  if (fileptr == NULL){
    puts("===>Error: Could not open file.");
    exit(1);
  }
  while (!feof(fileptr)) {
			if (fread(person, sizeof(PERSON), 1, fileptr)) {
				printf("\nFirstname: %s\n", person->firstname);
				printf("Lastname: %s\n", person->famnamne);
				printf("Person number: %s\n", person->pers_number);
				person++;
			}
		}
		fclose(fileptr);

}

void printOptions(){
  puts("\nChoose your options below: ");
  puts("1 Create a new and delete the old file.");
  puts("2 Add a new person to the file.");
  puts("3 Search for a person in the file.");
  puts("4 Print out all in the file.");
  puts("5 Exit the program.");
}

int main( void){
  PERSON ppost;
  PERSON *ppostPtr = &ppost;
  int option, nameOption;
  char name[20];

  puts("\n==========FILE MANAGEMENT OF PERSON REGISTER==========");
  while (true) {
    printOptions();
    scanf("%d", &option);
    clear_stdin();
    switch (option){
      case 1:
        write_new_file(ppostPtr);
        break;
      case 2:
        *ppostPtr = input_record();
        append_file(ppostPtr);
        break;
      case 3:
        puts("\nChoose options below:\n1 First name\n2 Family name");
        scanf("%d", &nameOption);
        clear_stdin();
        puts("\nType in name to search for:");
        fgets(name, 20, stdin);
        //or maybe check if name > 20
        remove_extra_chars(name);
        remove_newline(name);
        search_by_name(&nameOption, name);
        break;
      case 4:
        printfile();
        break;
      case 5:
        puts("===>Ending program.\n");
        exit(1);
        break;
      default:
        puts("===>Invalid input.");
        break;
    }
  }
  // 1 Create a new and delete the old file.
  // 2 Add a new person to the file.
  // 3 Search for a person in the file.
  // 4 Print out all in the file.
  // 5 Exit the program.

  return(0);
}