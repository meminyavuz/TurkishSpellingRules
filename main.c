#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

//Mehmet Emin Yavuz - 210229051


char text[100000];

int mainMenu(){ //ana men� fonksiyonu
	
	int menuStatus=0; //men�n�n kontrol� i�in tan�mlanan de�i�ken
	int menuDecision; //kullan�c�n�n verece�i men� karar�
	char exitDecision; //kullan�c�n programdan ��kmak istemesi durumu i�in tan�mlanan de�i�ken
	
	while(menuStatus==0){ //men�ye d�n�� i�in yap�lan ko�ullu d�ng� i�lemi
	
	
		
		printf("\n******MAIN MENU******\n\n");
		printf("1. CONNEX�ON\n");
		printf("2. MAJOR VOWEL HARMONY\n");
		printf("3. MINOR VOWEL HARMONY\n");
		printf("4. CONSONANT AFF�N�TY\n");
		printf("5. STRONG-SOFT CONSONANT(S)\n");
		printf("6. PLURAL WORD(S)\n");
		printf("7. NUMBER OF SENTENCE(S)\n");
		printf("8. NUMBER OF WORD(S)\n");
		printf("9. NUMBER OF LETTER(S)\n");
		printf("10. WORD SEARCH\n");
		printf("11. EXIT\n\n");
		
		printf("Is There a Rule You Want Checked?[1-11]: ");
		scanf("%d",&menuDecision);	
		
		switch(menuDecision){ //switch case y�ntemiyle men� kurulumu, fonksiyon �a��rma i�lemleri ve men�den ��k�� kontrol�
		
			case 1:
				connexion();
				break;		
		
			case 2:
				majorVowelHarmony();	
				break;
				
			case 3:
				minorVowelHarmony();
				break;
					
			case 4:
				consonantAffinity();
				break;
				
			case 5:
				strongSoftConsonants();
				break;
					
			case 6:
				pluralWords();
				break;
				
			case 7:
				numberOfSentences();
				break;
		
			case 8:
				numberOfWords();
				break;
		
			case 9:
				numberOfLetters();
				break;
				
			case 10:
				wordSearch();
				break;
			
			case 11:
				printf("Do you want to exit the program?[Y/y:Yes--N/n:No]: ");
				scanf("%s",&exitDecision);	
					
				if(exitDecision=='Y' || exitDecision=='y'){
					exit(0); 
					break;
				}
				
				else if(exitDecision=='N' || exitDecision=='n'){
					break;
				}
				else{
					printf("Please Enter a Valid Character!");
					break;
				}	
				
			default: 
				printf("Please Enter a Valid Character!\n\n"); //olabilecek 11 durumdan daha farkl� bir durum se�ilmesi istenmesi halinde verilecek hata cevab�.
				break;		
		}	
	}
}

int backtoMainMenu(){ //bellek �i�irmemek ad�na yap�lan men�ye d�n�� fonksiyonu
	
	int backtoMenuStatus=0; //men�ye d�n�� durumu d�ng�lerin kontrol alt�na al�nmas� i�in tan�mland�
	char backtoMenuDecision; //men�ye d�n�� karar�
	char exitDecision; //programdan ��k��a verilen eminlik cevab� i�in tan�mland�
	
	
	while(backtoMenuStatus==0){
	
	printf("\n\nDo you want to go to the main menu?[Y/y:Yes--N/n:No]: ");
	scanf("%s",&backtoMenuDecision);
	
	
		
		int exitConfirmation=0; //bu de�i�kenin burada tan�mlanmas�n�n nedeni ise d�ng� ba�a d�n�p tekrar etti�inde bu de�i�kenin 0 da tutulmas� istenmesi
	
		if(backtoMenuDecision=='Y' || backtoMenuDecision=='y'){
			mainMenu();
			backtoMenuStatus=1;		
		}
		
		else if(backtoMenuDecision=='N' || backtoMenuDecision=='n'){
			
			while(exitConfirmation==0){	 
			
					printf("Do you want to exit the program?[Y/y:Yes--N/n:No]: ");
					scanf("%s",&exitDecision);
				
					if(exitDecision == 'Y' || exitDecision == 'y'){
						exit(0); //programdan direkt ��k�� i�in yaz�lan kod par�as�
						break;
					}
				
					else if(exitDecision=='N' || exitDecision=='n'){
						exitConfirmation=1;
						mainMenu();
					}
				
					else{
						printf("Please Enter a Valid Character!\n\n");
						exitConfirmation=0;	
					}
			
			}
		
		}
			else{
				printf("Please Enter a Valid Character!\n\n");	
				
		}
	}
}

int printConnexion(){ //bulunan ulamalar� yazd�rmak i�n fonksiyon
	
	char consonant[25]="bcdfghjklmnprs�tvyz"; //�ns�z harflerin belirlenip tan�mlanmas�
	char vowels[17]="aei�o�u�AE�IO�U�"; //�nl� harflerin belirlenip tan�mlanmas�
	char wordseparation[]=" "; //metnin kesilece�i yerlerin tan�mlanmas�
	char *splitword=strtok(text,wordseparation); //strtok kullanarak metnin par�alanmas�
	char *backofspace, *spacefront; //ulamalar iki kelimeden olu�tu�u i�in gereken 2 kelimenin tan�mlanmas�
	
	backofspace=splitword;
	
	while(splitword!=NULL){ //d�ng� metinlerin kelimelere b�l�nemedi�i yerde sonlanacak
	
		splitword=strtok(NULL,wordseparation); //bo�luktan sonraki kelimenin al�nmas� i�in yap�lan strtok i�lemi
		spacefront=splitword; //spacefront par�alanan kelimeye atanacak
		
			if((strchr(consonant, (int)backofspace[strlen(backofspace)-1])!=NULL) && (strchr(vowels, (int)spacefront[0])!=NULL)){ //strchr y�ntemiyle istenen karakterlerin par�alanan kelimelerde olup olmad��� aranacak
				printf("%s %s, ",backofspace,spacefront);
			}
			
		backofspace=spacefront; //bu i�lemin yap�lmas�n�n nedeni sondaki kelimeyi ba�taki kelime durumuna getirmek ve bu i�lemin iki kelimeyle yap�lmas�n�n devaml�l���n� sa�lamak
	}
	
}

int connexion(){ //ulama bulmak i�in fonksiyon	
	
	int connexioncounter=0; //ulama bulundu�unda artacak sayac�n tan�mlanmas�
	int i;	

	for(i=0;i<strlen(text);i++){
		if(text[i]==' '){
			if(text[i-1]=='b' || text[i-1]=='c' || text[i-1]=='�' || text[i-1]=='d' || text[i-1]=='f' || text[i-1]=='g' || text[i-1]=='�' || text[i-1]=='h' || text[i-1]=='j' || text[i-1]=='k' || text[i-1]=='l' || text[i-1]=='m' || text[i-1]=='n' || text[i-1]=='n' || text[i-1]=='p' || text[i-1]=='r' || text[i-1]=='s' || text[i-1]=='�' || text[i-1]=='t' || text[i-1]=='v' || text[i-1]=='y' || text[i-1]=='z'){
				if(text[i+1]=='a' || text[i+1]=='e' || text[i+1]=='�' || text[i+1]=='i' || text[i+1]=='u' || text[i+1]=='�' || text[i+1]=='o' || text[i+1]=='�' || text[i+1]=='A' || text[i+1]=='E' || text[i+1]=='I' || text[i+1]=='�' || text[i+1]=='U' || text[i+1]=='�' || text[i+1]=='O' || text[i+1]=='�'){
					connexioncounter++;		
				}	
			}
		}
	}
		
	printf("%d Connexion Found!\n",connexioncounter);
	printf("\n");
	
	printConnexion();
	backtoMainMenu();
		
}		

int majorVowelHarmony(){ //b�y�k-k���k �nl� uyumu bulup yazd�rmak i�in fonksiyon

	char split[]=" ,.!?:;"; //kelimeleri par�alara ay�racak karakterlerin belirlenip bir dizide tan�mlanmas�
	char *wordseparation=strtok(text,split); //bu karakterler arac�l���yla metni kelime par�alar�na ay�rma i�lemi
	int lightvowelscounter=0,boldvowelscounter=0; //ince ve kal�n �nl�lerin sayac�
	int i;
	
	printf("Words that match major vowel harmony!\n");
	
	for(i=0;i<strlen(wordseparation);i++){//kal�n �nl�lerin bulunup sayac�n artt�r�lmas� i�in ko�ulland�rma bu d�ng� ilk kelime i�in yap�ld�
		if(wordseparation[i]=='E' || wordseparation[i]=='�' || wordseparation[i]=='�' || wordseparation[i]=='�' || wordseparation[i]=='e' || wordseparation[i]=='i' || wordseparation[i]=='�' || wordseparation[i]=='�'){
			lightvowelscounter++;
		}	
	}
		
	for(i=0;i<strlen(wordseparation);i++){ //ince �nl�lerin bulunup sayac�n artt�r�lmas� i�in ko�ulland�rma
		if(wordseparation[i]=='A' || wordseparation[i]=='I' || wordseparation[i]=='O' || wordseparation[i]=='U' || wordseparation[i]=='a' || wordseparation[i]=='�' || wordseparation[i]=='o' || wordseparation[i]=='u'){
			boldvowelscounter++;
		}
	}
	
	if(lightvowelscounter!=0 && boldvowelscounter!=0){ //e�er iki saya� birden artm��sa bu kelimeler yazd�r�lmayacak ve saya�lar s�f�rlanacak
		lightvowelscounter=0;
		boldvowelscounter=0;
	}
	
	else{
		printf("%s, ",wordseparation); //e�er iki saya� birden artmam��sa bu kelimeler yazd�r�lacak ve saya�lar s�f�rlanacak
		lightvowelscounter=0;
		boldvowelscounter=0;
	}
	
	while(wordseparation!=NULL){ //bu kural�n t�m kelimelere uygulanmas� i�in a��lan d�ng�
		
		wordseparation=strtok(NULL,split); //bo�luktan itibaren di�er kelimenin bulunup ayr�lmas�
		
		for(i=0;i<strlen(wordseparation);i++){ //ilk d�ng�deki i�lermlerin ayn�s� uyguland�
			if(wordseparation[i]=='E' || wordseparation[i]=='�' || wordseparation[i]=='�' || wordseparation[i]=='�' || wordseparation[i]=='e' || wordseparation[i]=='i' || wordseparation[i]=='�' || wordseparation[i]=='�'){
				lightvowelscounter++;
			}	
		}
	
		for(i=0;i<strlen(wordseparation);i++){
			if(wordseparation[i]=='A' || wordseparation[i]=='I' || wordseparation[i]=='O' || wordseparation[i]=='U' || wordseparation[i]=='a' || wordseparation[i]=='�' || wordseparation[i]=='o' || wordseparation[i]=='u'){
				boldvowelscounter++;
			}
		}
		if(lightvowelscounter!=0 && boldvowelscounter!=0){
			lightvowelscounter=0;
			boldvowelscounter=0;
		}
		
		else{
			printf("%s, ",wordseparation);
			lightvowelscounter=0;
			boldvowelscounter=0;
			
		} 		
	}
	
}

int minorVowelHarmony(){ //k���k �nl� uyumu bulup yazd�rmak i�in fonksiyon
	
	char split[]=" ,.!?:;";
	char *wordseparation=strtok(text,split);
	int i,j;
	int rule1=0,rule2=0,rulebreaker=0; //k���k �nl� uyumunda olan 2 kural ve 1 kural bozucu i�in saya� de�i�kenlerinin tanm�mlanmas�
	
	printf("Words that match minor vowel harmony!\n");
	
	for(i=0;i<strlen(wordseparation);i++){ //k���k �nl� uyumu i�in a��lan d�ng� ve ko�ulland�rma i�lemleri bu d�ng� ilk kelime i�in yap�ld�
		if(wordseparation[i]=='a' || wordseparation[i]=='e' || wordseparation[i]=='�' || wordseparation[i]=='i' || wordseparation[i]=='A' || wordseparation[i]=='E' || wordseparation[i]=='I' || wordseparation[i]=='�'){
			j=i+1;
			for(j;j<strlen(wordseparation);j++){
				if(wordseparation[j]=='a' || wordseparation[j]=='e' || wordseparation[j]=='�' || wordseparation[j]=='i'){
					rule1++;
				}
				else if(wordseparation[j]=='o' || wordseparation[j]=='�' || wordseparation[j]=='u' || wordseparation[j]=='�'){
					rulebreaker++; //kural bozucunun artt��� yerlerde k���k �nl� uyumuna uymayan ko�ullar sa�lanm�� oluyor.
				}
			}		
		}
		
		if(wordseparation[i]=='o' || wordseparation[i]=='�' || wordseparation[i]=='u' || wordseparation[i]=='�' || wordseparation[i]=='O' || wordseparation[i]=='�' || wordseparation[i]=='U' || wordseparation[i]=='�'){
			j=i+1;
			for(j;j<strlen(wordseparation);j++){
				if(wordseparation[j]=='a' || wordseparation[j]=='e' || wordseparation[j]=='u' || wordseparation[j]=='�'){
					rule2++;
				}
				else if(wordseparation[j]=='o' || wordseparation[j]=='�' || wordseparation[j]=='�' || wordseparation[j]=='i'){
					rulebreaker++;
				}
			}	
		}
	}
	
	if(rule1!=0 && rulebreaker==0){ //kural bozucunun artmad��� yerlerde kelimeler yazd�r�lacak
		printf("%s, ",wordseparation);
	}
	
	else if(rule2!=0 && rulebreaker==0){ //kural bozucunun artmad��� yerlerde kelimeler yazd�r�lacak
		printf("%s, ",wordseparation);
	}
	
	else{
		
	}
	
	rule1=0; //saya�lar�n ko�ul sonras� s�f�rlanmas� b�ylelikle di�er kelimeleri bulurken program do�ru �al��abilecek
	rule2=0; //saya�lar�n ko�ul sonras� s�f�rlanmas� b�ylelikle di�er kelimeleri bulurken program do�ru �al��abilecek
	rulebreaker=0; //saya�lar�n ko�ul sonras� s�f�rlanmas� b�ylelikle di�er kelimeleri bulurken program do�ru �al��abilecek
	
	
	while(wordseparation!=NULL){
		
		wordseparation=strtok(NULL,split);
		
		for(i=0;i<strlen(wordseparation);i++){
			if(wordseparation[i]=='a' || wordseparation[i]=='e' || wordseparation[i]=='�' || wordseparation[i]=='i' || wordseparation[i]=='A' || wordseparation[i]=='E' || wordseparation[i]=='I' || wordseparation[i]=='�'){
				j=i+1;
				for(j;j<strlen(wordseparation);j++){
					if(wordseparation[j]=='a' || wordseparation[j]=='e' || wordseparation[j]=='�' || wordseparation[j]=='i' || wordseparation[j]=='A' || wordseparation[j]=='E' || wordseparation[j]=='I' || wordseparation[j]=='�'){
						rule1++; 
					}
					else if(wordseparation[j]=='o' || wordseparation[j]=='�' || wordseparation[j]=='u' || wordseparation[j]=='�'){
						rulebreaker++; 
					}
				}
					
			}
			if(wordseparation[i]=='o' || wordseparation[i]=='�' || wordseparation[i]=='u' || wordseparation[i]=='�' || wordseparation[i]=='O' || wordseparation[i]=='�' || wordseparation[i]=='U' || wordseparation[i]=='�'){
				j=i+1;
				for(j;j<strlen(wordseparation);j++){
					if(wordseparation[j]=='a' || wordseparation[j]=='e' || wordseparation[j]=='u' || wordseparation[j]=='�'){
						rule2++;
					}
					else if(wordseparation[j]=='o' || wordseparation[j]=='�' || wordseparation[j]=='�' || wordseparation[j]=='i'){
						rulebreaker++;
					}
				}
				
			}
		}
		if(rule1!=0 && rulebreaker==0){
			printf("%s, ",wordseparation);
		}
		else if(rule2!=0 && rulebreaker==0){
			printf("%s, ",wordseparation);
		}
		else{
		
		}
		
	rule1=0; //saya�lar�n ko�ul sonras� s�f�rlanmas� b�ylelikle di�er kelimeleri bulurken program do�ru �al��abilecek
	rule2=0; //saya�lar�n ko�ul sonras� s�f�rlanmas� b�ylelikle di�er kelimeleri bulurken program do�ru �al��abilecek
	rulebreaker=0; //saya�lar�n ko�ul sonras� s�f�rlanmas� b�ylelikle di�er kelimeleri bulurken program do�ru �al��abilecek
		
	}
}

int printConsonantAffinity(){ //�ns�z benze�mesini yazd�rmak i�in fonksiyon

	char split[]=" ,.!?:;"; 
	char *wordseparation=strtok(text,split); 
	int i;
	
	for(i=0;i<strlen(wordseparation);i++){
		
		if(wordseparation[i]=='f' || wordseparation[i]=='s' || wordseparation[i]=='t' || wordseparation[i]=='k' || wordseparation[i]=='�' || wordseparation[i]=='�' || wordseparation[i]=='h' || wordseparation[i]=='p'){
			if(wordseparation[i+1]=='f' || wordseparation[i+1]=='s' || wordseparation[i+1]=='t' || wordseparation[i+1]=='k' || wordseparation[i+1]=='�' || wordseparation[i+1]=='�' || wordseparation[i+1]=='h' || wordseparation[i+1]=='p'){
				printf("%s, ",wordseparation);		
			}
		}
	}
	
	while(wordseparation!=NULL){
		
		wordseparation=strtok(NULL,split);
		
		for(i=0;i<strlen(wordseparation);i++){
		
			if(wordseparation[i]=='f' || wordseparation[i]=='s' || wordseparation[i]=='t' || wordseparation[i]=='k' || wordseparation[i]=='�' || wordseparation[i]=='�' || wordseparation[i]=='h' || wordseparation[i]=='p'){
				if(wordseparation[i+1]=='f' || wordseparation[i+1]=='s' || wordseparation[i+1]=='t' || wordseparation[i+1]=='k' || wordseparation[i+1]=='�' || wordseparation[i+1]=='�' || wordseparation[i+1]=='h' || wordseparation[i+1]=='p'){
					printf("%s, ",wordseparation);		
				}
			}
		}
	}	
}

int consonantAffinity(){ //�ns�z benze�mesini bulmak i�in fonksiyon
	
	int consonantaffinitycounter=0;
	int i;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]=='f' || text[i]=='s' || text[i]=='t' || text[i]=='k' || text[i]=='�' || text[i]=='�' || text[i]=='h' || text[i]=='p'){
			if(text[i+1]=='f' || text[i+1]=='s' || text[i+1]=='t' || text[i+1]=='k' || text[i+1]=='�' || text[i+1]=='�' || text[i+1]=='h' || text[i+1]=='p'){
				consonantaffinitycounter++;
			}
		}
	}
	printf("%d Consonant Affinity Found!\n",consonantaffinitycounter);
	
	printConsonantAffinity();	
}

int strongSoftConsonants(){ //sert-yumu�ak �ns�zleri bulmak i�in fonksiyon
	
	int strongconsonantcounter=0;
	int softconsonantcounter=0;
	int i;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]=='f' || text[i]=='s' || text[i]=='t' || text[i]=='k' || text[i]=='�' || text[i]=='�' || text[i]=='h' || text[i]=='p' || text[i]=='F' || text[i]=='S' || text[i]=='T' || text[i]=='K' || text[i]=='�' || text[i]=='�' || text[i]=='H' || text[i]=='P'){
			strongconsonantcounter++;	
		}
		else if(text[i]=='b' || text[i]=='c' || text[i]=='d' || text[i]=='g' || text[i]=='�' || text[i]=='j' || text[i]=='l' || text[i]=='m' || text[i]=='n' || text[i]=='r' || text[i]=='v' || text[i]=='y' || text[i]=='z' || text[i]=='B' || text[i]=='C' || text[i]=='D' || text[i]=='G' || text[i]=='J' || text[i]=='L' || text[i]=='M' || text[i]=='N' || text[i]=='R' || text[i]=='V' || text[i]=='Y' || text[i]=='Z'){
			softconsonantcounter++;
		}
	}
	
	printf("The number of strong consonants in your text: %d\n",strongconsonantcounter);
	printf("The number of soft consonants in your text: %d\n",softconsonantcounter);
	
	backtoMainMenu();
	
}

int printPluralWords(){ //�o�ul kelimeleri yazd�rmak i�in fonksiyon
	
	char split[]=" ,.!?:;"; //kelimelerin b�l�nece�i karakterleri belirlemek i�in tan�mlama
	char *wordseparation=strtok(text,split); //strtok kullanarak yap�lan c�mleyi kelimelerine par�alama i�lemi
	int i;
	 	
	for(i=0;i<strlen(wordseparation);i++){ //a��lan d�ng� ilk kelimeyi de eklemek i�in yap�ld�
		if(wordseparation[i]=='l'){
			if(wordseparation[i+1]=='e' || wordseparation[i+1]=='a'){
				if(wordseparation[i+2]=='r'){		
						printf("%s, ",wordseparation);			
				}
			}
		}	
	}
		
	while(wordseparation!=NULL){ //metin bitimine kadar kontrol�n sa�lanmas� ve yazd�r�lmas� i�in yap�lan d�ng�
	
		wordseparation=strtok(NULL,split);
		
		for(i=0;i<strlen(wordseparation);i++){
			if(wordseparation[i]=='l'){
				if(wordseparation[i+1]=='e' || wordseparation[i+1]=='a'){
					if(wordseparation[i+2]=='r'){	
						printf("%s, ",wordseparation);
						
					}
				}
			}	
		}	
	}				
}

int pluralWords(){ //�o�ul kelime bulma fonksiyonu
	
	int i=0;
	int pluralwordscounter=0;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]=='l'){
			if(text[i+1]=='e' || text[i+1]=='a'){
				if(text[i+2]=='r'){
					pluralwordscounter++;
				}
			}
		}
	}
	
	printf("%d Plural Word(s) Found!\n\n",pluralwordscounter);
	
	printPluralWords();
	backtoMainMenu();
}

int numberOfSentences(){ //c�mle say�s� bulma fonksiyonu
	
	int numberofsentences=0;
	int	punctuationmarkcounter=0;
	int pointscounter=0;
	int i;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]=='?' || text[i]=='!' || text[i]==';' || text[i]==':' ){ //c�mleyi bitiren karakterlerin ko�ullanmas�	
			punctuationmarkcounter++;
		}
		else if(text[i]=='.'){
			
			punctuationmarkcounter++;
			
			if(text[i+1]=='.'){
				pointscounter++;
			}
		}
		
		numberofsentences=punctuationmarkcounter-pointscounter;
				
	}
	
	printf("Number Of Sentences In Your Text: %d\n\n",numberofsentences);
	
	backtoMainMenu();
}

int numberOfWords(){ //kelime say�s� bulma fonksiyonu
	
	int i;
	int spacecounter=0;
	int numberofwords;
	
	for(i=0;i<strlen(text);i++){ //c�mledeki bo�luk say�s� bulma 
		if(text[i]==' '){
			spacecounter++;
		}
	}
	numberofwords=spacecounter+1; //parmak aras� y�ntemiyle kelime say�s� bulma
	
	printf("Number Of Words In Your Text: %d\n\n",numberofwords);
	
	backtoMainMenu();
}

int numberOfLetters(){ //harf say�s� bulma fonksiyonu
			
	
	int numberofletters = strlen(text); //girilen metnin uzunlu�unu atama
	int i;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]==' ' || text[i]=='.' || text[i]=='?' || text[i]=='!' || text[i]==',' || text[i]=='-' || text[i]==';' || text[i]==':' || text[i]=='"' || text[i]=='(' || text[i]==')' || text[i]=='"' || text[i]=='1' || text[i]=='2' || text[i]=='3' || text[i]=='4' || text[i]=='5' || text[i]=='6' || text[i]=='7' || text[i]=='8' || text[i]=='9' || text[i]=='0'){ //c�mkede harf say�lmayacak karakterlerin belirlenmesi	
			numberofletters--;	
		}		
	}
	
	printf("Number Of Letters In Your Text: %d\n\n",numberofletters);
				
	backtoMainMenu();
}

int wordSearch(){ //kelime arama fonksiyonu
	
	char word[20];
	char *ptrWord;
	
	printf("Please enter the word you want to search for!: ");
	scanf("%s",word);
	
	ptrWord=strstr(text,word); //strstr ile string i�inde string aramas� yap�ld�
	
	if(ptrWord) printf("The word you are looking for is found in the text!\n\n");
	else printf("The word you are looking for is not found in the text!\n\n");
	
	backtoMainMenu();	
}

int main() {
	
	setlocale(LC_ALL,"Turkish");
	
	
	printf("Please Enter a Text!: ");
	gets(text);
	
	mainMenu();
	
	return 0;
}
