/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


struct date{
	int day, month, year;

	};

struct date extractDate(struct node*head){

	int day = 0, month = 0, year = 0;
	struct date d1;
	d1.day = -1;
	d1.month = -1;
	d1.year = -1;
	if (head == NULL)
		return d1;

	struct node* temp = head;

	day = temp->data;
	temp = temp->next;
	day = day * 10 + temp->data;
	temp = temp->next;

	month = temp->data;
	temp = temp->next;
	month = month * 10 + temp->data;
	temp = temp->next;

	year = temp->data;
	temp = temp->next;
	while (temp){
		year = year * 10 + temp->data;
		temp = temp->next;
		}

	
	d1.day = day;
	d1.month = month;
	d1.year = year;

	return d1;

	}

int getYearDays(struct date date1, struct date date2){

	int days = 0;
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (date1.year > date2.year){
		days += (date1.year - date2.year) * 365;
		if (date1.month > date2.month){
			int i = date2.month;
			while (i < date1.month){
				days += months[i];
				i++;
				}

			}
		else{
			int i = date1.month;
			while (i < date2.month){
				days += months[i];
				i++;
				}


			}


		}
	else{
		days += (date2.year - date1.year) * 365;
		if (date1.month > date2.month){
			int i = date2.month;
			while (i < date1.month){
				days += months[i];
				i++;
				}

			}
		else{
			int i = date1.month;
			while (i < date2.month){
				days += months[i];
				i++;
				}


			}


		}

	if (date1.year % 4 == 0)
		days += 1;
	if (date2.year % 4 == 0)
		days += 1;

	return days;
	}

int countDates(struct date date1, struct date date2){
	int days = 0;

	if (date1.year == date2.year){
		if (date1.month == date2.month){

			if (date1.day < date2.day)
				return date2.day - date1.day - 1;
			else
				return date1.day - date2.day - 1;

			}
		else{


			}

		}
	else{

		days += getYearDays(date1, date2);

		}

	return days;
	}


int between_days(struct node *date1head, struct node *date2head){

	if (date1head == NULL || date2head == NULL)
		return -1;

	struct date date1 = extractDate(date1head);
	struct date date2 = extractDate(date2head);

	return countDates(date1, date2);


	}
