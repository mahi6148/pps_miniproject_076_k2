#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct vicar_airline
{
int passport[6];
char name[15];
int seat_num;
char email[15];
struct vicar_airline *following;
}
*begin, *stream;
struct vicar_airline *dummy;
void main()
{
void reserve(int x), cancel(), display(), savefile();
int choice;
begin = stream = NULL;
int num = 1;
do
{
printf("Welcome To Vicar Airlines Online Booking Hub\n");
printf("1. Reservation\n");
printf("2. Cancel\n");
printf("3. Display Records\n");
printf("4. Exit\n");
printf("Enter Your Choice\n");
scanf("%d", &choice);
switch (choice)
{
case 1:
reserve(num);
num++;
break;
case 2:
cancel();
break;
case 3:
display();
break;
case 4:
{
savefile();
break;
}
default:
printf("ENTER VALID CHOICE(1-4)");
printf("Press Any Key To Go Back To Main Menu");
}
getch();
} while (choice != 4);
}
void details()
{
printf("Enter Your Passport Number: ");
scanf("%s", stream->passport);
printf("Enter your name: ");
scanf("%s", stream->name);
printf("Enter your email address: ");
scanf("%s", stream->email);
}
void details();
void reserve(int x)
{
stream = begin;
if (begin == NULL)
{
// first user
begin = stream = (struct vicar_airline*)malloc(sizeof(struct vicar_airline));
details();
stream->following = NULL;
printf("Seat Booking Successful!\n");
printf("Your Seat Number Is: Seat A-%d", x);
stream->seat_num = x;
return;
}
else if (x > 15)
{
printf("\nSeats Full");
return;
}
else
{
// next user
while (stream->following)
stream = stream->following;
stream->following = (struct vicar_airline *)malloc(sizeof(struct vicar_airline));
stream = stream->following;
details();
stream->following = NULL;
printf("\nSeat Booking Succesful!");
printf("\nYour Seat Number Is: Seat A-%d", x);
stream->seat_num = x;
return;
}
}
void savefile()
{
FILE *fpointer = fopen("Vicar Records", "w");
if (!fpointer)
{
printf("\n Error In Opening File!");
return;
}
stream = begin;
//fprintf(fpointer, "Passport No.\t\t\tName\t\t\tEmail\n");
while (stream)
{
fprintf(fpointer, "%-6s", stream->passport);
fprintf(fpointer, "%-15s", stream->name);
fprintf(fpointer, "%-15s", stream->email);
fprintf(fpointer, "\n");
stream = stream->following;
}
printf("Details Have Been Saved To A File (Vicar Records)");
fclose(fpointer);
}
void display()
{
stream = begin;
while (stream)
{
printf("\nPassport Number : %-6s", stream->passport);
printf("\nName : %-15s", stream->name);
printf("\nEmail addressddress: %-15s", stream->email);
printf("\nSeat number: A-%d", stream->seat_num);
stream = stream->following;
}
}
void cancel()
{
stream = begin;
char passport[6];
printf("\nEnter Passort Nmber to Delete Record?:");
scanf("%s", passport);
if (strcmp(begin->passport, passport) == 0)
{
dummy = begin;
begin = begin->following;
free(dummy);
printf("Booking Has Been Deleted\n");
return;
}
while (stream->following)
{
if (strcmp(stream->following->passport, passport) == 0)
{
dummy = stream->following;
stream->following = stream->following->following;
free(dummy);
printf("Has Been Deleted\n");
getch();
return;
}
stream = stream->following;
}
printf("Passport Number Is Wrong Please Check Your Passport\n");
}
