#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct word {
	char w[20];
}word;

typedef struct epitem {
	word key;
	struct epitem* next;
}epitem;

typedef struct showitem {
	int season;
	int ep;
	struct showitem *next;
	struct epitem*nextkw;
}showitem;

void remove_new_line(char* string)
{
	size_t length;
	if ((length = strlen(string)) >0)
	{
		if (string[length - 1] == '\n')
			string[length - 1] = '\0';
	}
}

epitem* getkey(FILE* epi)
{
	epitem* current;
	epitem* head;
	head = (epitem*)malloc(1 * sizeof(epitem));
	current = head;
	current->next = NULL;
	while ((fgets(&(current->key.w), 20, epi)) != NULL)
	{
		remove_new_line(&(current->key.w));
		current->next = (epitem*)malloc(1 * sizeof(epitem));
		current = current->next;
		current->next = NULL;
	}
	*(current->key.w) = '\0';
	return head;
}


void getfiles(showitem** black, showitem** sher)
{
	showitem* current;

	FILE* blacks1e1;
	FILE* blacks1e2;
	FILE* blacks1e3;
	FILE* blacks2e1;
	FILE* blacks2e2;
	FILE* blacks2e3;

	FILE* shers1e1;
	FILE* shers1e2;
	FILE* shers1e3;
	FILE* shers2e1;
	FILE* shers2e2;
	FILE* shers2e3;

	blacks1e1 = fopen("blackmirror_season1episode1.txt", "r");
	if (blacks1e1 == NULL)
	{
		printf("Couldn't open file blacks1e1!");
		return;
	}
	*black = (showitem*)malloc(sizeof(showitem));
	(*black)->next = NULL;
	(*black)->season = 1;
	(*black)->ep = 1;
	(*black)->nextkw = getkey(blacks1e1);
	fclose(blacks1e1);


	blacks1e2 = fopen("blackmirror_season1episode2.txt", "r");
	if (blacks1e2 == NULL)
	{
		printf("Couldn't open file blacks1e2!");
		return;
	}
	(*black)->next = (showitem*)malloc(1 * sizeof(showitem));
	current = (*black)->next;
	current->next = NULL;
	current->season = 1;
	current->ep = 2;
	current->nextkw = getkey(blacks1e2);
	fclose(blacks1e2);

	blacks1e3 = fopen("blackmirror_season1episode3.txt", "r");
	if (blacks1e3 == NULL)
	{
		printf("Couldn't open file blacks1e3!");
		return;
	}
	current->next = (showitem*)malloc(1 * sizeof(showitem));
	current = current->next;
	current->next = NULL;
	current->season = 1;
	current->ep = 3;
	current->nextkw = getkey(blacks1e3);
	fclose(blacks1e3);

	blacks2e1 = fopen("blackmirror_season2episode1.txt", "r");
	if (blacks2e1 == NULL)
	{
		printf("Couldn't open file blacks2e1!");
		return;
	}
	current->next = (showitem*)malloc(1 * sizeof(showitem));
	current = current->next;
	current->next = NULL;
	current->season = 2;
	current->ep = 1;
	current->nextkw = getkey(blacks2e1);
	fclose(blacks2e1);

	blacks2e2 = fopen("blackmirror_season2episode2.txt", "r");
	if (blacks2e2 == NULL)
	{
		printf("Couldn't open file blacks2e2!");
		return;
	}
	current->next = (showitem*)malloc(1 * sizeof(showitem));
	current = current->next;
	current->next = NULL;
	current->season = 2;
	current->ep = 2;
	current->nextkw = getkey(blacks2e2);
	fclose(blacks2e2);

	blacks2e3 = fopen("blackmirror_season2episode3.txt", "r");
	if (blacks2e3 == NULL)
	{
		printf("Couldn't open file blacks2e3!");
		return;
	}
	current->next = (showitem*)malloc(1 * sizeof(showitem));
	current = current->next;
	current->next = NULL;
	current->season = 2;
	current->ep = 3;
	current->nextkw = getkey(blacks2e3);
	fclose(blacks2e3);


	shers1e1 = fopen("sherlock_season1episode1.txt", "r");
	if (shers1e1 == NULL)
	{
		printf("Couldn't open file shers1e1!");
		return;
	}
	(*sher) = (showitem*)malloc(1 * sizeof(showitem));
	(*sher)->next = NULL;
	(*sher)->season = 1;
	(*sher)->ep = 1;
	(*sher)->nextkw = getkey(shers1e1);
	fclose(shers1e1);

	shers1e2 = fopen("sherlock_season1episode2.txt", "r");
	if (shers1e2 == NULL)
	{
		printf("Couldn't open file shers1e2!");
		return;
	}
	(*sher)->next = (showitem*)malloc(1 * sizeof(showitem));
	current = (*sher)->next;
	current->next = NULL;
	current->season = 1;
	current->ep = 2;
	current->nextkw = getkey(shers1e2);
	fclose(shers1e2);

	shers1e3 = fopen("sherlock_season1episode3.txt", "r");
	if (shers1e3 == NULL)
	{
		printf("Couldn't open file shers1e3!");
		return;
	}
	current->next = (showitem*)malloc(1 * sizeof(showitem));
	current = current->next;
	current->next = NULL;
	current->season = 1;
	current->ep = 3;
	current->nextkw = getkey(shers1e3);
	fclose(shers1e3);

	shers2e1 = fopen("sherlock_season2episode1.txt", "r");
	if (shers2e1 == NULL)
	{
		printf("Couldn't open file shers2e1!");
		return;
	}
	current->next = (showitem*)malloc(1 * sizeof(showitem));
	current = current->next;
	current->next = NULL;
	current->season = 2;
	current->ep = 1;
	current->nextkw = getkey(shers2e1);
	fclose(shers2e1);

	shers2e2 = fopen("sherlock_season2episode2.txt", "r");
	if (shers2e2 == NULL)
	{
		printf("Couldn't open file shers2e2!");
		return;
	}
	current->next = (showitem*)malloc(1 * sizeof(showitem));
	current = current->next;
	current->next = NULL;
	current->season = 2;
	current->ep = 2;
	current->nextkw = getkey(shers2e2);
	fclose(shers2e2);

	shers2e3 = fopen("sherlock_season2episode3.txt", "r");
	if (shers2e3 == NULL)
	{
		printf("Couldn't open file shers2e3!");
		return;
	}
	current->next = (showitem*)malloc(1 * sizeof(showitem));
	current = current->next;
	current->next = NULL;
	current->season = 2;
	current->ep = 3;
	current->nextkw = getkey(shers2e3);
	fclose(shers2e3);

}

void searchkeywords(showitem* current, word kw[], int numkw) {
	int is = 0;
	int i;
	epitem* currentep = (current->nextkw);
	int match = 0;
	epitem* currentephead = currentep;

	while (current != NULL)
	{
		for (i = 0; i < numkw; i++)
		{
			match = 0;
			currentep = currentephead;
			while (currentep != NULL)
			{
				if (strcmp(kw[i].w, currentep->key.w) == 0)
				{
					match = 1;
				}
				currentep = currentep->next;
			}
			if (match == 0)
			{
				break;
			}
		}

		if (match == 1)
		{
			printf("season: %d \t episode: %d\n", current->season, current->ep);
			is = 1;
			match = 0;
		}
		current = current->next;
		if (current == NULL)
		{
			break;
		}
		currentep = (current->nextkw);
		currentephead = currentep;
	}
	if (is == 0)
	{
		printf("There are no matching episodes.\n");

	}
	
}


int main()
{
	showitem* black;
	showitem* sher;
	showitem* currentshow;
	word keywords[20];
	char showtitle[16];
	int i = 0;
	int numkw;


	getfiles(&black, &sher);

choosetitle:
	*showtitle = '\0';
	printf("Please choose a show: black mirror, sherlock.\n");
	gets(&showtitle);
	printf("Your chosen show: %s\n", showtitle);

	if (strcmp(showtitle, "black mirror") == 0)
	{
		currentshow = black;
	}
	else if (strcmp(showtitle, "sherlock") == 0)
	{
		currentshow = sher;
	}
	else {
		printf("Invalid title. Please choose another one.\n");
		goto choosetitle;
	};

	printf("How many keywords do you want to search for?\n");
	scanf("%d", &numkw);

	printf("Please give a maximum of %d keywords.\n", numkw);
	for (i = 0; i < numkw; i++) {
		scanf("%s", keywords[i].w);
	}
	
	searchkeywords(currentshow, keywords, numkw);
	free(black->next->next->next->next->next->next);
	free(black->next->next->next->next->next);
	free(black->next->next->next->next);
	free(black->next->next->next);
	free(black->next->next);
	free(black->next);
	free(black);
	
	free(sher->next->next->next->next->next->next);
	free(sher->next->next->next->next->next);
	free(sher->next->next->next->next);
	free(sher->next->next->next);
	free(sher->next->next);
	free(sher->next);
	free(sher);


	return 0;
}
