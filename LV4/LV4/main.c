#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PBS.h"

#define MAX_STRING_LENGHT 100

int main()
{
	char string[MAX_STRING_LENGHT] = { '\0' };
	PBS* stablo = NULL;
	int i;

	printf("Unesite string svoga imena i prezimena: ");
	scanf("%99[^\n]", string);

	for (i = 0; i < strlen(string); i++)
	{
		if (string[i] == ' ') 
			continue;
		stablo = umetni_cvor(string[i], stablo);
	}
	
	printf("Preorder: ");
	ispisi_preorder(stablo);
	printf("\n");

	printf("Inorder: ");
	ispisi_inorder(stablo);
	printf("\n");

	printf("Postorder: ");
	ispisi_postorder(stablo);
	printf("\n");

	oslobodi_PBS(stablo);
}