#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SSIZE 100
#define FSIZE 30
typedef struct{
char *nid;
int id;
int credits;
float gpa;
char *name;
} student;
typedef struct{
char *nid;
int id;
char *department;
char *name;
char *rank;
} faculty;
void addFaculty(faculty members[], faculty member){
int c = 0;
member.name = malloc(100 * sizeof(char));
member.nid = malloc(3 * sizeof(char));
member.rank = malloc(50 * sizeof(char));
member.department = malloc(50 * sizeof(char));
printf("\n\nEnter the faculty's info: \n");
printf("\tName of the faculty: ");
getchar();
fgets(member.name, SSIZE, stdin);
member.name[strcspn(member.name, "\n")] = '\0';
for (int i = 0; i < strlen(member.name); i++) {
member.name[i] = toupper(member.name[i]);
}
while(c<3){
printf("\tID: ");
if(scanf("%2s%d", member.nid, &member.id) !=2 || strlen(member.nid) != 2){
int firstDigit = member.id/100000;
if(member.id<100000 || member.id > 999999 || firstDigit != 0){
printf("\t\tSorry entered ID (%s%d) is invalid. Try again.\n", member.nid,
member.id);
c++;
while (getchar() != '\n');
continue;
}
}
else{
break;
}
}
if(c == 3){
printf("You have tried too many times...\n");
printf("Thank you for using PerPro. Goodbye!");
exit(0);
}
c=0;
while(c<3){
printf("\tRank: ");
scanf("%s", member.rank);
for(int i = 0; i<strlen(member.rank); i++){
member.rank[i] = toupper(member.rank[i]);
}
if(strcmp(member.rank, "PROFESSOR") != 0 && strcmp(member.rank, "ADJUNCT") !=
0){
printf("\t\tSorry entered rank (%s) is invalid. Try again.\n", member.rank);
c++;
continue;
}
else{
break;
}
}
if(c == 3){
printf("You have tried too many times...\n");
printf("Thank you for using PerPro. Goodbye!\n");
exit(0);
}
c=0;
while(c<3){
printf("\tDepartment: ");
scanf("%s", member.department);
for(int i = 0; i<strlen(member.department); i++){
member.department[i] = toupper(member.department[i]);
}
if(strcmp(member.department, "MATH") != 0 && strcmp(member.department, "CS") !=
0 && strcmp(member.department, "SCIENCE") != 0){
printf("\t\tSorry entered department (%s) is invalid. Try again\n",
member.department);
c++;
continue;
}
else{
break;
}
}
if(c == 3){
printf("You have tried too many times...\n");
printf("Thank you for using PerPro. Goodbye!\n");
exit(0);
}
for(int i = 0; i<FSIZE; i++){
if(members[i].id == 0){
members[i] = member;
break;
}
}
printf("Thanks!\n\n");
}
void addStudent(student studs[], student stud){
int c = 0;
stud.name = malloc(SSIZE * sizeof(char));
stud.nid = malloc(3 * sizeof(char));
printf("\n\nEnter the student's info: \n");
printf("\tName of the student: ");
getchar();
fgets(stud.name, SSIZE, stdin);
stud.name[strcspn(stud.name, "\n")] = '\0';
for (int i = 0; i < strlen(stud.name); i++) {
stud.name[i] = toupper(stud.name[i]);
}
while(c<3){
printf("\tID: ");
if(scanf("%2s%d", stud.nid, &stud.id) !=2 || strlen(stud.nid) != 2){
int firstDigit = stud.id/100000;
if(stud.id<100000 || stud.id > 999999 || firstDigit != 0){
printf("\t\tSorry entered ID (%s%d) is invalid. Try again.\n", stud.nid,
stud.id);
c++;
while (getchar() != '\n');
continue;
}
}
else{
break;
}
}
if(c == 3){
printf("You have tried too many times...\n");
printf("Thank you for using PerPro. Goodbye!\n");
free(stud.name);
free(stud.nid);
exit(0);
}
c=0;
while(c<3){
printf("\tGPA: ");
scanf("%f", &stud.gpa);
if(!(stud.gpa>0 && stud.gpa<=4)){
printf("\t\tSorry entered gpa (%.2f) is invalid. Try again.\n", stud.gpa);
c++;
continue;
}
else{
break;
}
}
if(c == 3){
printf("You have tried too many times...\n");
printf("Thank you for using PerPro. Goodbye!\n");
free(stud.name);
free(stud.nid);
exit(0);
}
c=0;
while(c<3){
printf("\tCredit Hours: ");
scanf("%d", &stud.credits);
if(stud.credits<0){
printf("\t\tSorry entered credit hours (%d) is invalid. Try again\n",
stud.credits);
c++;
continue;
}
else{
break;
}
}
if(c == 3){
printf("You have tried too many times...\n");
printf("Thank you for using PerPro. Goodbye!\n");
free(stud.name);
free(stud.nid);
exit(0);
}
for(int i = 0; i<SSIZE; i++){
if(studs[i].id == 0){
studs[i].name = malloc(strlen(stud.name) + 1);
studs[i].nid = malloc(strlen(stud.nid) + 1);
strcpy(studs[i].name, stud.name);
strcpy(studs[i].nid, stud.nid);
studs[i].id = stud.id;
studs[i].gpa = stud.gpa;
studs[i].credits = stud.credits;
printf("Thanks!\n\n");
return;
}
}
}
void printInvoice(student studs[]){
char *nid2;
int id2;
float total = 0;
float discount = 0;
int found = 0;
nid2 = malloc(3 * sizeof(char));
char *tempnid2 = malloc(3 * sizeof(char));
printf("\tEnter the student's id: ");
scanf("%2s%d", nid2, &id2);
for (int i = 0; i < strlen(nid2); i++) {
nid2[i] = toupper(nid2[i]);
}
for(int i = 0; i<SSIZE; i++){
for(int j = 0; j<strlen(tempnid2); j++){
tempnid2[j] = toupper(nid2[j]);
}
if(studs[i].id != 0 && strcmp(studs[i].nid, nid2)==0 || strcmp(nid2, tempnid2)
== 0 && studs[i].id == id2){
found = 1;
printf("\tHere is the tuition invoice for %s:\n\n\n", studs[i].name);
printf("-----------------------------------------------------------------\
n");
char *tempName = malloc(strlen(studs[i].name) + 1);
strcpy(tempName, studs[i].name);
for(int j = 0; j<strlen(tempName); j++){
tempName[j] = toupper(tempName[j]);
}
for (int j = 0; j < 2; j++) {
nid2[j] = toupper(nid2[j]);
}
printf("\t%s\t\t", tempName);
printf("%2s%d\n", nid2, studs[i].id);
printf("\tCredit Hours: %d ($236.45/credit hour)\n\tFees:$52\n\n\n",
studs[i].credits);
if(studs[i].gpa>=3.85){
total = (studs[i].credits * 236.45 + 52);
discount=(total * 0.25);
total = total-discount;
printf("\tTotal Payment: $%.2f\t\t\t($%.2f discount applied)", total,
discount);
}
else{
total = (studs[i].credits * 236.45 + 52);
printf("\tTotal Payment: $%.2f\t\t\t($%.2f discount applied)", total,
discount);
}
printf("\n-----------------------------------------------------------------\
n");
break;
}
}
if(found == 0){
printf("\tSorry-student not found!\n\n");
}
}
void printFaculty(faculty members[]){
char *nid2;
int id2;
int found = 0;
nid2 = malloc(3 * sizeof(char));
char *tempnid2 = malloc(3 * sizeof(char));
printf("\tEnter the faculty's id: ");
scanf("%2s%d", nid2, &id2);
for (int i = 0; i < strlen(nid2); i++) {
nid2[i] = toupper(nid2[i]);
}
for(int i = 0; i<FSIZE; i++){
for(int j = 0; j<strlen(tempnid2); j++){
tempnid2[j] = toupper(nid2[j]);
}
if(members[i].id != 0 && strcmp(members[i].nid, nid2)==0 || strcmp(nid2,
tempnid2) == 0 && members[i].id == id2){
found = 1;
printf("Faculty found:\n\n");
printf("-----------------------------------------------------------------\
n");
char *tempName = malloc(strlen(members[i].name) + 1);
char *tempDepartment = malloc(strlen(members[i].department) + 1);
char *tempRank = malloc(strlen(members[i].rank) + 1);
strcpy(tempName, members[i].name);
strcpy(tempDepartment, members[i].department);
strcpy(tempRank, members[i].rank);
for(int j = 0; j<strlen(tempName); j++){
tempName[j] = toupper(tempName[j]);
}
for(int j = 0; j<strlen(tempDepartment); j++){
tempDepartment[j] = toupper(tempDepartment[j]);
}
for(int j = 0; j<strlen(tempRank); j++){
tempRank[j] = toupper(tempRank[j]);
}
printf("\t%s\n", tempName);
printf("\t%s department, %s", members[i].department, members[i].rank);
printf("\n-----------------------------------------------------------------\
n");
break;
}
}
if(found == 0){
printf("\tSorry %2s%d doesn't exist !\n\n", nid2, id2);
}
}
void swapFaculty(faculty *a, faculty *b) {
faculty temp = *a;
*a = *b;
*b = temp;
}
void swapStudents(student *a, student *b) {
student temp = *a;
*a = *b;
*b = temp;
}
void finalReport(faculty members[], student studs[]){
char yn;
char choice;
printf("\tWould you like to print the final report (Y/N): ");
while (getchar() != '\n');
scanf("%c", &yn);
if(toupper(yn) == 'Y'){
printf("\nEnter\n");
printf("\t\tN or n to sort the faculty by name\n");
printf("\t\tD or d to sort the faculty by department\n");
printf("\t\tR or r to sort the faculty the rank\n");
printf("\tMake your sort selection: ");
while (getchar() != '\n');
scanf("%c", &choice);
for (int i = 0; i < FSIZE - 1; i++) {
for (int j = 0; j < FSIZE - 1 - i; j++) {
if (members[j].id == 0 || members[j + 1].id == 0) continue;
if (toupper(choice) == 'N' && members[j].name && members[j + 1].name) {
if (strcmp(members[j].name, members[j + 1].name) > 0) {
swapFaculty(&members[j], &members[j + 1]);
}
}
else if (toupper(choice) == 'D' && members[j].department && members[j +
1].department) {
if (strcmp(members[j].department, members[j + 1].department) > 0) {
swapFaculty(&members[j], &members[j + 1]);
}
}
else if (toupper(choice) == 'R' && members[j].rank && members[j +
1].rank) {
if (strcmp(members[j].rank, members[j + 1].rank) > 0) {
swapFaculty(&members[j], &members[j + 1]);
}
}
}
}
printf("\nEnter\n");
printf("\t\tN or n to sort the students by name\n");
printf("\t\tG or g to sort the students by gpa\n");
printf("\tMake your sort selection: ");
while (getchar() != '\n');
scanf("%c", &choice);
for (int i = 0; i < SSIZE - 1; i++) {
for (int j = 0; j < SSIZE - 1 - i; j++) {
if (studs[j].id == 0 || studs[j + 1].id == 0) continue;
if (toupper(choice) == 'N' && studs[j].name && studs[j + 1].name) {
if (strcmp(studs[j].name, studs[j + 1].name) > 0) {
swapStudents(&studs[j], &studs[j + 1]);
}
}
else if (toupper(choice) == 'G') {
if (studs[j].gpa < studs[j + 1].gpa) {
swapStudents(&studs[j], &studs[j + 1]);
}
}
}
}
printf("\n\nHere is your report...");
printf("\n\n------\tL I S T O F F A C U L T Y\t------");
for (int i = 0; i < FSIZE; i++) {
if (members[i].id != 0 && members[i].name) {
printf("\n\t%s", members[i].name);
if (members[i].department) printf(" - %s", members[i].department);
}
}
printf("\n\n------\tL I S T O F S T U D E N T S\t------");
for (int i = 0; i < SSIZE; i++) {
if (studs[i].id != 0 && studs[i].name) {
printf("\n\t%s", studs[i].name);
printf(" (GPA = %.2f)", studs[i].gpa);
}
}
}
}
int menu (){
int option, c = 0;
printf("Choose one of the options: \n");
printf("1-Add a new faculty member\n");
printf("2-Add a new student\n");
printf("3-Print tuition invoice for a student\n");
printf("4-Print information of a faculty\n");
printf("5-Exit Program\n");
while(c < 3){
printf("\t\tEnter your Selection: ");
if (scanf("%d", &option) != 1) {
while (getchar() != '\n');
if(c<2){
printf("\t\tInvalid entry - please try again.\n");
}
c++;
continue;
}
if(option > 0 && option < 6){
return option;
}
else{
if(c<2){
printf("\t\tInvalid entry - please try again. \n");
}
c++;
}
}
printf("\n\nYou have tried too many times...");
return -1;
}
int main(){
faculty members[FSIZE] = {0};
faculty member;
for (int i = 0; i < FSIZE; i++) {
members[i].nid = NULL;
members[i].name = NULL;
members[i].department = NULL;
members[i].rank = NULL;
members[i].id = 0;
}
student studs[SSIZE] = {0};
student stud;
char *math = "MATH";
char *cs = "CS";
char *science = "SCIENCE";
int option;
printf("\t\t\tWelcome to PerPro\n\n\n");
while (option != 6) {
option = menu();
if (option == -1) {
break;
}
if(option == 1){
addFaculty(members, member);
}
if(option == 2){
addStudent(studs, stud);
}
if(option == 3){
printInvoice(studs);
}
if(option == 4){
printFaculty(members);
}
if(option == 5){
finalReport(members, studs);
option = 6;
}
}
printf("\nThank you for using PerPro. Goodbye!");
}
