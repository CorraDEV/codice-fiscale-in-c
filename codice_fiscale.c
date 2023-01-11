#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 20

main()
{
	char nome[N], cognome[N], luogo[5], sesso;
	char codice_fiscale[17], sub_nome[4] = "";
	char sub_cognome[4] = "", sub_numero[3] = "";
	char mese_codice, sub_giorno[3] = "";
	char sub_anno[5] = "", anno_codice[3] = "";
	char giorno_codice[3] = "", codice_pari[8] = "";
	char codice_dispari[9] = "", stringa_giorno[3]= "";
	char stringa_mese[3]= "";
	char giorno[3], mese[3], anno[5];
	int i, conta_consonanti = 0;
	int giorno_int = 0, mese_int = 0, anno_int = 0; 
	int conta_lettere = 0, pari = 0, dispari = 0;
	int val_pari = 0, val_dispari = 0;
	int val_ultimo_carattere, controllo = 0;
	long somma_pari = 0, somma_dispari = 0, somma;
	char ultimo_carattere; 
	time_t s, val = 1;
    struct tm* current_time;
    
    s = time(NULL);
    
    current_time = localtime(&s);
	
	do{
		printf("\ninserisci il tuo nome: ");
		fflush(stdin);
		gets(nome);
		
		if(strlen(nome)>N || strlen(nome)<1)
			printf("\nerrore: nome non valido\n");
	}while(strlen(nome)>N || strlen(nome)<1);
	
	do{
		printf("\ninserisci il tuo cognome: ");
		fflush(stdin);
		gets(cognome);
		
		if(strlen(cognome)>N || strlen(cognome)<1)
			printf("\n\nerrore: cognome non valido");
	}while(strlen(cognome)>N || strlen(cognome)<1);
	
	do{
		printf("\ninserisci codice catastale del tuo luogo di nascita: ");
		gets(luogo);	
		
		if(strlen(luogo) == 4)
		{
			i = 0;
			controllo = 0;
			
			while(luogo[i] != '\0' && controllo == 0)
			{
				if(i==0)
				{
					if(luogo[i] < 65 || (luogo[i] > 90 && luogo[i] < 97) || luogo[i] > 122)
						controllo = 1;
				}	
				else
				{
					if(luogo[i] < 48 || luogo[i] > 57)
						controllo = 1;
				}
				i++;
			}
		}
		else
			controllo = 1;
		
		if(controllo == 1)
			printf("\n\nerrore: codice catastale non valido");
			
	}while(controllo == 1);
	
	do{
		printf("\ninserisci il tuo sesso: ");
		fflush(stdin);
		scanf("%c",&sesso);
		
		if(sesso != 'M' && sesso != 'm' && sesso != 'F' && sesso != 'f')
			printf("\nerrore: sesso non valido");		
	}while(sesso != 'M' && sesso != 'm' && sesso != 'F' && sesso != 'f');
	
	do{
		do{
			printf("\ninserisci giorno di nascita: ");
			fflush(stdin);
			gets(giorno);							
			
			if(strlen(giorno)<=2)
			{
				i = 0;
				controllo = 0;
					
				while(giorno[i] != '\0' && controllo == 0)
				{
					if(giorno[i] < 48 || giorno[i] > 57)
						controllo = 1;					
			
					i++;
				}
				
				if(controllo == 0)
				{
					i = 0;
					giorno_int = 0;
					
					while(giorno[i] != '\0')
					{
						giorno_int = giorno_int * 10 + (giorno[i] - 48);				
						i++;
					}				
					
					if(giorno_int > 31 || giorno_int <= 0)
						controllo = 1;			
				}
			}
			else
				controllo = 1;
			
			if(controllo == 1)
				printf("\n\nerrore: giorno non valido");
			
		}while(controllo == 1);
		
		do{
			printf("\ninserisci mese di nascita: ");
			fflush(stdin);
			gets(mese);			
			
			if(strlen(mese) <= 2)
			{
				i = 0;
				controllo = 0;
				
				while(mese[i] != '\0' && controllo == 0)
				{
					if(mese[i] < 48 || mese[i] > 57)
						controllo = 1;					
			
					i++;
				}
				
				if(controllo == 0)
				{
					i = 0;
					mese_int = 0;
					
					while(mese[i] != '\0')
					{
						mese_int = mese_int * 10 + (mese[i] - 48);				
						i++;
					}
					
					if(mese_int > 12 || mese_int <= 0)
						controllo = 1;			
				}
			}
			else
				controllo = 1;
			
			if(controllo == 1)
				printf("\n\nerrore: mese non valido");
			
		}while(controllo == 1);
			
		do{
			printf("\ninserisci anno di nascita: ");
			gets(anno);	
			
			if(strlen(anno) == 4)
			{
				i = 0;
				controllo = 0;
				
				while(anno[i] != '\0' && controllo == 0)
				{
					if(anno[i] < 48 || anno[i] > 57)
						controllo = 1;					
			
					i++;
				}
				
				if(controllo == 0)
				{
					i = 0;
					anno_int = 0;
					
					while(anno[i] != '\0')
					{
						anno_int = anno_int * 10 + (anno[i] - 48);				
						i++;
					}
					
					if(anno_int>current_time->tm_year + 1900 || anno_int < 1900)
						controllo = 1;			
				}
			}
			else
				controllo = 1;
			
			if(controllo == 1)
				printf("\n\nerrore: anno non valido");
			else
			{
				anno_codice[0] = anno[strlen(anno)-2];
				anno_codice[1] = anno[strlen(anno)-1];
			}
				
		}while(controllo == 1);
		
		if(anno_int==current_time->tm_year + 1900 && (mese_int > current_time->tm_mon || (mese_int == current_time->tm_mon && giorno_int == current_time->tm_mday)))
			printf("\n\nerrore: data non valida");
		
	}while(anno_int==current_time->tm_year + 1900 && (mese_int > current_time->tm_mon || (mese_int == current_time->tm_mon && giorno_int == current_time->tm_mday)));
	
	for(i=0;cognome[i]!='\0';i++)
	{
		if((cognome[i] >= 65 && cognome[i] <= 90) || (cognome[i] >= 97 && cognome[i] <= 122) && conta_lettere < 3)
		{
			if(cognome[i] !='A' && cognome[i] !='a' && cognome[i] !='E' && cognome[i] !='e' && cognome[i] !='I' && cognome[i] !='i' && cognome[i] !='O' && cognome[i] !='o' && cognome[i] !='U' && cognome[i] !='u')
			{
				sub_cognome[conta_lettere] = cognome[i];
				conta_lettere++;
			}
		}
	}
	
	if(conta_lettere < 3)
	{
		for(i=0;cognome[i] != 0;i++)
		{
			if(cognome[i] =='A' || cognome[i] == 'a' || cognome[i] =='E' || cognome[i] =='e' || cognome[i] =='I' || cognome[i] =='i' || cognome[i] =='O' || cognome[i] =='o' || cognome[i] =='U' || cognome[i] =='u')
			{
				sub_cognome[conta_lettere] = cognome[i];
				conta_lettere++;
			}
		}
		if(conta_lettere < 3)
		{
			for(i=conta_lettere;conta_lettere < 3;i++)
			{	
				sub_cognome[i] = 'X';
				conta_lettere++;
			}
		}
	}
	
	conta_lettere = 0;
	
	for(i=0;nome[i]!='\0';i++)
	{
		if((nome[i] >= 65 && nome[i] <= 90) || (nome[i] >= 97 && nome[i] <= 122) && conta_lettere < 3)
		{
			if(nome[i] !='A' && nome[i] !='a' && nome[i] !='E' && nome[i] !='e' && nome[i] !='I' && nome[i] !='i' && nome[i] !='O' && nome[i] !='o' && nome[i] !='U' && nome[i] !='u')
			{
				conta_consonanti++;
				
				if(conta_consonanti != 2)
				{
					sub_nome[conta_lettere] = nome[i];
					conta_lettere++;
				}
			}
		}
	}
	
	if(conta_consonanti <= 3)
	{
		conta_lettere = 0;
		
		for(i=0;nome[i]!='\0';i++)
		{
			if((nome[i] >= 65 && nome[i] <= 90) || (nome[i] >= 97 && nome[i] <= 122) && conta_lettere < 3)
			{
				if(nome[i] !='A' && nome[i] !='a' && nome[i] !='E' && nome[i] !='e' && nome[i] !='I' && nome[i] !='i' && nome[i] !='O' && nome[i] !='o' && nome[i] !='U' && nome[i] !='u')
				{																			
					sub_nome[conta_lettere] = nome[i];
					conta_lettere++;
				}
			}
		}
	}
	
	if(conta_lettere < 3)
	{
		for(i=0;nome[i] != 0;i++)
		{
			if(nome[i] =='A' || nome[i] == 'a' || nome[i] =='E' || nome[i] =='e' || nome[i] =='I' || nome[i] =='i' || nome[i] =='O' || nome[i] =='o' || nome[i] =='U' || nome[i] =='u')
			{
				sub_nome[conta_lettere] = nome[i];
				conta_lettere++;
			}
		}
		if(conta_lettere < 3)
		{
			for(i=conta_lettere;conta_lettere < 3;i++)
			{	
				sub_nome[i] = 'X';
				conta_lettere++;
			}
		}
	}
		
	switch(mese_int)
	{
		case 1:
				mese_codice = 'a';
				break;
		case 2:
				mese_codice = 'b';
				break;
		case 3:
				mese_codice = 'c';
				break;
		case 4:
				mese_codice = 'd';
				break;
		case 5:
				mese_codice = 'e';
				break;		
		case 6:
				mese_codice = 'h';
				break;
		case 7:
				mese_codice = 'l';
				break;
		case 8:
				mese_codice = 'm';
				break;
		case 9:
				mese_codice = 'p';
				break;
		case 10:
				mese_codice = 'r';
				break;
		case 11:
				mese_codice = 's';
				break;
		case 12:
				mese_codice = 't';
				break;
	}
	
	if(sesso == 'F' || sesso == 'f')
		giorno_int += 40;
	
	if(giorno_int < 10)
	{
		giorno_codice[0] = '0';
		giorno_codice[1] = giorno_int + 48;
		giorno_codice[2] = '\0';
	}	
	else
		strcpy(giorno_codice, giorno);			
	
	strcpy(codice_fiscale, sub_cognome);
	strcat(codice_fiscale, sub_nome);
	strcat(codice_fiscale, anno_codice);
	strncat(codice_fiscale, &mese_codice, 1);
	strcat(codice_fiscale, giorno_codice);
	strcat(codice_fiscale, luogo);
	
	for(i=0;i<strlen(codice_fiscale);i++)
	{
		if(codice_fiscale[i] >= 97 && codice_fiscale[i] <= 122)
			codice_fiscale[i] -= 32;
	}
	
	for(i=0;i<strlen(codice_fiscale);i++)
	{
		if(i%2 == 0)
		{	
			codice_dispari[dispari] = codice_fiscale[i]; 
			dispari++;
		}	
		else
		{
			codice_pari[pari] = codice_fiscale[i];
			pari++;
		}
	}
	
	i = 0;
	
	while(i<strlen(codice_pari))
	{
		switch(codice_pari[i])
		{
			case '0':
					val_pari = 0;
					break;
			case '1':
					val_pari = 1;
					break;
			case '2':
					val_pari = 2;
					break;
			case '3':
					val_pari = 3;
					break;
			case '4':
					val_pari = 4;
					break;
			case '5':
					val_pari = 5;
					break;
			case '6':
					val_pari = 6;
					break;
			case '7':
					val_pari = 7;
					break;
			case '8':
					val_pari = 8;
					break;
			case '9':
					val_pari = 9;
					break;
			case 'A':
					val_pari = 0;
					break;
			case 'B':
					val_pari = 1;
					break;
			case 'C':
					val_pari = 2;
					break;
			case 'D':
					val_pari = 3;
					break;
			case 'E':
					val_pari = 4;
					break;
			case 'F':
					val_pari = 5;
					break;
			case 'G':
					val_pari = 6;
					break;
			case 'H':
					val_pari = 7;
					break;
			case 'I':
					val_pari = 8;
					break;
			case 'J':
					val_pari = 9;
					break;
			case 'K':
					val_pari = 10;
					break;
			case 'L':
					val_pari = 11;
					break;
			case 'M':
					val_pari = 12;
					break;		
			case 'N':
					val_pari = 13;
					break;		
			case 'O':
					val_pari = 14;
					break;
			case 'P':
					val_pari = 15;
					break;
			case 'Q':
					val_pari = 16;
					break;
			case 'R':
					val_pari = 17;
					break;
			case 'S':
					val_pari = 18;
					break;
			case 'T':
					val_pari = 19;
					break;
			case 'U':
					val_pari = 20;
					break;
			case 'V':
					val_pari = 21;
					break;
			case 'W':
					val_pari = 22;
					break;
			case 'X':
					val_pari = 23;
					break;
			case 'Y':
					val_pari = 24;
					break;
			case 'Z':
					val_pari = 25;
					break;
		} 
		somma_pari += val_pari;
		i++;
	}
	
	i = 0;
	
	while(i<strlen(codice_dispari))
	{		
		switch(codice_dispari[i])
		{
			case '0':
					val_dispari = 1;
					break;
			case '1':
					val_dispari = 0;
					break;
			case '2':
					val_dispari = 5;
					break;
			case '3':
					val_dispari = 7;
					break;
			case '4':
					val_dispari = 9;
					break;
			case '5':
					val_dispari = 13;
					break;
			case '6':
					val_dispari = 15;
					break;
			case '7':
					val_dispari = 17;
					break;
			case '8':
					val_dispari = 19;
					break;
			case '9':
					val_dispari = 21;
					break;
			case 'A':
					val_dispari = 1;
					break;
			case 'B':
					val_dispari = 0;
					break;
			case 'C':
					val_dispari = 5;
					break;
			case 'D':
					val_dispari = 7;
					break;
			case 'E':
					val_dispari = 9;
					break;
			case 'F':
					val_dispari = 13;
					break;
			case 'G':
					val_dispari = 15;
					break;
			case 'H':
					val_dispari = 17;
					break;
			case 'I':
					val_dispari = 19;
					break;
			case 'J':
					val_dispari = 21;
					break;
			case 'K':
					val_dispari = 2;
					break;
			case 'L':
					val_dispari = 4;
					break;
			case 'M':
					val_dispari = 18;
					break;		
			case 'N':
					val_dispari = 20;
					break;		
			case 'O':
					val_dispari = 11;
					break;
			case 'P':
					val_dispari = 3;
					break;
			case 'Q':
					val_dispari = 6;
					break;
			case 'R':
					val_dispari = 8;
					break;
			case 'S':
					val_dispari = 12;
					break;
			case 'T':
					val_dispari = 14;
					break;
			case 'U':
					val_dispari = 16;
					break;
			case 'V':
					val_dispari = 10;
					break;
			case 'W':
					val_dispari = 22;
					break;
			case 'X':
					val_dispari = 25;
					break;
			case 'Y':
					val_dispari = 24;
					break;
			case 'Z':
					val_dispari = 23;
					break;
		}
		somma_dispari += val_dispari;
		i++;
	}
	
	somma = somma_pari + somma_dispari;
	val_ultimo_carattere = somma % 26;
	
	switch(val_ultimo_carattere)
	{
		case 0:
				ultimo_carattere = 'A';
				break;
		case 1:
				ultimo_carattere = 'B';
				break;
		case 2:
				ultimo_carattere = 'C';
				break;
		case 3:
				ultimo_carattere = 'D';
				break;
		case 4:
				ultimo_carattere = 'E';
				break;
		case 5:
				ultimo_carattere = 'F';
				break;
		case 6:
				ultimo_carattere = 'G';
				break;
		case 7:
				ultimo_carattere = 'H';
				break;
		case 8:
				ultimo_carattere = 'I';
				break;
		case 9:
				ultimo_carattere = 'J';
				break;
		case 10:
				ultimo_carattere = 'K';
				break;
		case 11:
				ultimo_carattere = 'L';
				break;
		case 12:
				ultimo_carattere = 'M';
				break;
		case 13:
				ultimo_carattere = 'N';
				break;
		case 14:
				ultimo_carattere = 'O';
				break;
		case 15:
				ultimo_carattere = 'P';
				break;
		case 16:
				ultimo_carattere = 'Q';
				break;
		case 17:
				ultimo_carattere = 'R';
				break;
		case 18:
				ultimo_carattere = 'S';
				break;
		case 19:
				ultimo_carattere = 'T';
				break;
		case 20:
				ultimo_carattere = 'U';
				break;
		case 21:
				ultimo_carattere = 'V';
				break;
		case 22:
				ultimo_carattere = 'W';
				break;
		case 23:
				ultimo_carattere = 'X';
				break;
		case 24:
				ultimo_carattere = 'Y';
				break;
		case 25:
				ultimo_carattere = 'Z';
				break;
	}
	
	strncat(codice_fiscale, &ultimo_carattere, 1);
	
	printf("\n%s\n\n",codice_fiscale);	
	
	system("pause");
}
