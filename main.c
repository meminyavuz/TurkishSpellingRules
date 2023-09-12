#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

//Mehmet Emin Yavuz - 210229051


char text[100000];

int mainMenu(){ //ana menü fonksiyonu
	
	int menuStatus=0; //menünün kontrolü için tanýmlanan deðiþken
	int menuDecision; //kullanýcýnýn vereceði menü kararý
	char exitDecision; //kullanýcýn programdan çýkmak istemesi durumu için tanýmlanan deðiþken
	
	while(menuStatus==0){ //menüye dönüþ için yapýlan koþullu döngü iþlemi
	
	
		
		printf("\n******MAIN MENU******\n\n");
		printf("1. CONNEXÝON\n");
		printf("2. MAJOR VOWEL HARMONY\n");
		printf("3. MINOR VOWEL HARMONY\n");
		printf("4. CONSONANT AFFÝNÝTY\n");
		printf("5. STRONG-SOFT CONSONANT(S)\n");
		printf("6. PLURAL WORD(S)\n");
		printf("7. NUMBER OF SENTENCE(S)\n");
		printf("8. NUMBER OF WORD(S)\n");
		printf("9. NUMBER OF LETTER(S)\n");
		printf("10. WORD SEARCH\n");
		printf("11. EXIT\n\n");
		
		printf("Is There a Rule You Want Checked?[1-11]: ");
		scanf("%d",&menuDecision);	
		
		switch(menuDecision){ //switch case yöntemiyle menü kurulumu, fonksiyon çaðýrma iþlemleri ve menüden çýkýþ kontrolü
		
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
				printf("Please Enter a Valid Character!\n\n"); //olabilecek 11 durumdan daha farklý bir durum seçilmesi istenmesi halinde verilecek hata cevabý.
				break;		
		}	
	}
}

int backtoMainMenu(){ //bellek þiþirmemek adýna yapýlan menüye dönüþ fonksiyonu
	
	int backtoMenuStatus=0; //menüye dönüþ durumu döngülerin kontrol altýna alýnmasý için tanýmlandý
	char backtoMenuDecision; //menüye dönüþ kararý
	char exitDecision; //programdan çýkýþa verilen eminlik cevabý için tanýmlandý
	
	
	while(backtoMenuStatus==0){
	
	printf("\n\nDo you want to go to the main menu?[Y/y:Yes--N/n:No]: ");
	scanf("%s",&backtoMenuDecision);
	
	
		
		int exitConfirmation=0; //bu deðiþkenin burada tanýmlanmasýnýn nedeni ise döngü baþa dönüp tekrar ettiðinde bu deðiþkenin 0 da tutulmasý istenmesi
	
		if(backtoMenuDecision=='Y' || backtoMenuDecision=='y'){
			mainMenu();
			backtoMenuStatus=1;		
		}
		
		else if(backtoMenuDecision=='N' || backtoMenuDecision=='n'){
			
			while(exitConfirmation==0){	 
			
					printf("Do you want to exit the program?[Y/y:Yes--N/n:No]: ");
					scanf("%s",&exitDecision);
				
					if(exitDecision == 'Y' || exitDecision == 'y'){
						exit(0); //programdan direkt çýkýþ için yazýlan kod parçasý
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

int printConnexion(){ //bulunan ulamalarý yazdýrmak içn fonksiyon
	
	char consonant[25]="bcdfghjklmnprsþtvyz"; //ünsüz harflerin belirlenip tanýmlanmasý
	char vowels[17]="aeiýoöuüAEÝIOÖUÜ"; //ünlü harflerin belirlenip tanýmlanmasý
	char wordseparation[]=" "; //metnin kesileceði yerlerin tanýmlanmasý
	char *splitword=strtok(text,wordseparation); //strtok kullanarak metnin parçalanmasý
	char *backofspace, *spacefront; //ulamalar iki kelimeden oluþtuðu için gereken 2 kelimenin tanýmlanmasý
	
	backofspace=splitword;
	
	while(splitword!=NULL){ //döngü metinlerin kelimelere bölünemediði yerde sonlanacak
	
		splitword=strtok(NULL,wordseparation); //boþluktan sonraki kelimenin alýnmasý için yapýlan strtok iþlemi
		spacefront=splitword; //spacefront parçalanan kelimeye atanacak
		
			if((strchr(consonant, (int)backofspace[strlen(backofspace)-1])!=NULL) && (strchr(vowels, (int)spacefront[0])!=NULL)){ //strchr yöntemiyle istenen karakterlerin parçalanan kelimelerde olup olmadýðý aranacak
				printf("%s %s, ",backofspace,spacefront);
			}
			
		backofspace=spacefront; //bu iþlemin yapýlmasýnýn nedeni sondaki kelimeyi baþtaki kelime durumuna getirmek ve bu iþlemin iki kelimeyle yapýlmasýnýn devamlýlýðýný saðlamak
	}
	
}

int connexion(){ //ulama bulmak için fonksiyon	
	
	int connexioncounter=0; //ulama bulunduðunda artacak sayacýn tanýmlanmasý
	int i;	

	for(i=0;i<strlen(text);i++){
		if(text[i]==' '){
			if(text[i-1]=='b' || text[i-1]=='c' || text[i-1]=='ç' || text[i-1]=='d' || text[i-1]=='f' || text[i-1]=='g' || text[i-1]=='ð' || text[i-1]=='h' || text[i-1]=='j' || text[i-1]=='k' || text[i-1]=='l' || text[i-1]=='m' || text[i-1]=='n' || text[i-1]=='n' || text[i-1]=='p' || text[i-1]=='r' || text[i-1]=='s' || text[i-1]=='þ' || text[i-1]=='t' || text[i-1]=='v' || text[i-1]=='y' || text[i-1]=='z'){
				if(text[i+1]=='a' || text[i+1]=='e' || text[i+1]=='ý' || text[i+1]=='i' || text[i+1]=='u' || text[i+1]=='ü' || text[i+1]=='o' || text[i+1]=='ö' || text[i+1]=='A' || text[i+1]=='E' || text[i+1]=='I' || text[i+1]=='Ý' || text[i+1]=='U' || text[i+1]=='Ü' || text[i+1]=='O' || text[i+1]=='Ö'){
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

int majorVowelHarmony(){ //büyük-küçük ünlü uyumu bulup yazdýrmak için fonksiyon

	char split[]=" ,.!?:;"; //kelimeleri parçalara ayýracak karakterlerin belirlenip bir dizide tanýmlanmasý
	char *wordseparation=strtok(text,split); //bu karakterler aracýlýðýyla metni kelime parçalarýna ayýrma iþlemi
	int lightvowelscounter=0,boldvowelscounter=0; //ince ve kalýn ünlülerin sayacý
	int i;
	
	printf("Words that match major vowel harmony!\n");
	
	for(i=0;i<strlen(wordseparation);i++){//kalýn ünlülerin bulunup sayacýn arttýrýlmasý için koþullandýrma bu döngü ilk kelime için yapýldý
		if(wordseparation[i]=='E' || wordseparation[i]=='Ý' || wordseparation[i]=='Ö' || wordseparation[i]=='Ü' || wordseparation[i]=='e' || wordseparation[i]=='i' || wordseparation[i]=='ö' || wordseparation[i]=='ü'){
			lightvowelscounter++;
		}	
	}
		
	for(i=0;i<strlen(wordseparation);i++){ //ince ünlülerin bulunup sayacýn arttýrýlmasý için koþullandýrma
		if(wordseparation[i]=='A' || wordseparation[i]=='I' || wordseparation[i]=='O' || wordseparation[i]=='U' || wordseparation[i]=='a' || wordseparation[i]=='ý' || wordseparation[i]=='o' || wordseparation[i]=='u'){
			boldvowelscounter++;
		}
	}
	
	if(lightvowelscounter!=0 && boldvowelscounter!=0){ //eðer iki sayaç birden artmýþsa bu kelimeler yazdýrýlmayacak ve sayaçlar sýfýrlanacak
		lightvowelscounter=0;
		boldvowelscounter=0;
	}
	
	else{
		printf("%s, ",wordseparation); //eðer iki sayaç birden artmamýþsa bu kelimeler yazdýrýlacak ve sayaçlar sýfýrlanacak
		lightvowelscounter=0;
		boldvowelscounter=0;
	}
	
	while(wordseparation!=NULL){ //bu kuralýn tüm kelimelere uygulanmasý için açýlan döngü
		
		wordseparation=strtok(NULL,split); //boþluktan itibaren diðer kelimenin bulunup ayrýlmasý
		
		for(i=0;i<strlen(wordseparation);i++){ //ilk döngüdeki iþlermlerin aynýsý uygulandý
			if(wordseparation[i]=='E' || wordseparation[i]=='Ý' || wordseparation[i]=='Ö' || wordseparation[i]=='Ü' || wordseparation[i]=='e' || wordseparation[i]=='i' || wordseparation[i]=='ö' || wordseparation[i]=='ü'){
				lightvowelscounter++;
			}	
		}
	
		for(i=0;i<strlen(wordseparation);i++){
			if(wordseparation[i]=='A' || wordseparation[i]=='I' || wordseparation[i]=='O' || wordseparation[i]=='U' || wordseparation[i]=='a' || wordseparation[i]=='ý' || wordseparation[i]=='o' || wordseparation[i]=='u'){
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

int minorVowelHarmony(){ //küçük ünlü uyumu bulup yazdýrmak için fonksiyon
	
	char split[]=" ,.!?:;";
	char *wordseparation=strtok(text,split);
	int i,j;
	int rule1=0,rule2=0,rulebreaker=0; //küçük ünlü uyumunda olan 2 kural ve 1 kural bozucu için sayaç deðiþkenlerinin tanmýmlanmasý
	
	printf("Words that match minor vowel harmony!\n");
	
	for(i=0;i<strlen(wordseparation);i++){ //küçük ünlü uyumu için açýlan döngü ve koþullandýrma iþlemleri bu döngü ilk kelime için yapýldý
		if(wordseparation[i]=='a' || wordseparation[i]=='e' || wordseparation[i]=='ý' || wordseparation[i]=='i' || wordseparation[i]=='A' || wordseparation[i]=='E' || wordseparation[i]=='I' || wordseparation[i]=='Ý'){
			j=i+1;
			for(j;j<strlen(wordseparation);j++){
				if(wordseparation[j]=='a' || wordseparation[j]=='e' || wordseparation[j]=='ý' || wordseparation[j]=='i'){
					rule1++;
				}
				else if(wordseparation[j]=='o' || wordseparation[j]=='ö' || wordseparation[j]=='u' || wordseparation[j]=='ü'){
					rulebreaker++; //kural bozucunun arttýðý yerlerde küçük ünlü uyumuna uymayan koþullar saðlanmýþ oluyor.
				}
			}		
		}
		
		if(wordseparation[i]=='o' || wordseparation[i]=='ö' || wordseparation[i]=='u' || wordseparation[i]=='ü' || wordseparation[i]=='O' || wordseparation[i]=='Ö' || wordseparation[i]=='U' || wordseparation[i]=='Ü'){
			j=i+1;
			for(j;j<strlen(wordseparation);j++){
				if(wordseparation[j]=='a' || wordseparation[j]=='e' || wordseparation[j]=='u' || wordseparation[j]=='ü'){
					rule2++;
				}
				else if(wordseparation[j]=='o' || wordseparation[j]=='ö' || wordseparation[j]=='ý' || wordseparation[j]=='i'){
					rulebreaker++;
				}
			}	
		}
	}
	
	if(rule1!=0 && rulebreaker==0){ //kural bozucunun artmadýðý yerlerde kelimeler yazdýrýlacak
		printf("%s, ",wordseparation);
	}
	
	else if(rule2!=0 && rulebreaker==0){ //kural bozucunun artmadýðý yerlerde kelimeler yazdýrýlacak
		printf("%s, ",wordseparation);
	}
	
	else{
		
	}
	
	rule1=0; //sayaçlarýn koþul sonrasý sýfýrlanmasý böylelikle diðer kelimeleri bulurken program doðru çalýþabilecek
	rule2=0; //sayaçlarýn koþul sonrasý sýfýrlanmasý böylelikle diðer kelimeleri bulurken program doðru çalýþabilecek
	rulebreaker=0; //sayaçlarýn koþul sonrasý sýfýrlanmasý böylelikle diðer kelimeleri bulurken program doðru çalýþabilecek
	
	
	while(wordseparation!=NULL){
		
		wordseparation=strtok(NULL,split);
		
		for(i=0;i<strlen(wordseparation);i++){
			if(wordseparation[i]=='a' || wordseparation[i]=='e' || wordseparation[i]=='ý' || wordseparation[i]=='i' || wordseparation[i]=='A' || wordseparation[i]=='E' || wordseparation[i]=='I' || wordseparation[i]=='Ý'){
				j=i+1;
				for(j;j<strlen(wordseparation);j++){
					if(wordseparation[j]=='a' || wordseparation[j]=='e' || wordseparation[j]=='ý' || wordseparation[j]=='i' || wordseparation[j]=='A' || wordseparation[j]=='E' || wordseparation[j]=='I' || wordseparation[j]=='Ý'){
						rule1++; 
					}
					else if(wordseparation[j]=='o' || wordseparation[j]=='ö' || wordseparation[j]=='u' || wordseparation[j]=='ü'){
						rulebreaker++; 
					}
				}
					
			}
			if(wordseparation[i]=='o' || wordseparation[i]=='ö' || wordseparation[i]=='u' || wordseparation[i]=='ü' || wordseparation[i]=='O' || wordseparation[i]=='Ö' || wordseparation[i]=='U' || wordseparation[i]=='Ü'){
				j=i+1;
				for(j;j<strlen(wordseparation);j++){
					if(wordseparation[j]=='a' || wordseparation[j]=='e' || wordseparation[j]=='u' || wordseparation[j]=='ü'){
						rule2++;
					}
					else if(wordseparation[j]=='o' || wordseparation[j]=='ö' || wordseparation[j]=='ý' || wordseparation[j]=='i'){
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
		
	rule1=0; //sayaçlarýn koþul sonrasý sýfýrlanmasý böylelikle diðer kelimeleri bulurken program doðru çalýþabilecek
	rule2=0; //sayaçlarýn koþul sonrasý sýfýrlanmasý böylelikle diðer kelimeleri bulurken program doðru çalýþabilecek
	rulebreaker=0; //sayaçlarýn koþul sonrasý sýfýrlanmasý böylelikle diðer kelimeleri bulurken program doðru çalýþabilecek
		
	}
}

int printConsonantAffinity(){ //ünsüz benzeþmesini yazdýrmak için fonksiyon

	char split[]=" ,.!?:;"; 
	char *wordseparation=strtok(text,split); 
	int i;
	
	for(i=0;i<strlen(wordseparation);i++){
		
		if(wordseparation[i]=='f' || wordseparation[i]=='s' || wordseparation[i]=='t' || wordseparation[i]=='k' || wordseparation[i]=='ç' || wordseparation[i]=='þ' || wordseparation[i]=='h' || wordseparation[i]=='p'){
			if(wordseparation[i+1]=='f' || wordseparation[i+1]=='s' || wordseparation[i+1]=='t' || wordseparation[i+1]=='k' || wordseparation[i+1]=='ç' || wordseparation[i+1]=='þ' || wordseparation[i+1]=='h' || wordseparation[i+1]=='p'){
				printf("%s, ",wordseparation);		
			}
		}
	}
	
	while(wordseparation!=NULL){
		
		wordseparation=strtok(NULL,split);
		
		for(i=0;i<strlen(wordseparation);i++){
		
			if(wordseparation[i]=='f' || wordseparation[i]=='s' || wordseparation[i]=='t' || wordseparation[i]=='k' || wordseparation[i]=='ç' || wordseparation[i]=='þ' || wordseparation[i]=='h' || wordseparation[i]=='p'){
				if(wordseparation[i+1]=='f' || wordseparation[i+1]=='s' || wordseparation[i+1]=='t' || wordseparation[i+1]=='k' || wordseparation[i+1]=='ç' || wordseparation[i+1]=='þ' || wordseparation[i+1]=='h' || wordseparation[i+1]=='p'){
					printf("%s, ",wordseparation);		
				}
			}
		}
	}	
}

int consonantAffinity(){ //ünsüz benzeþmesini bulmak için fonksiyon
	
	int consonantaffinitycounter=0;
	int i;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]=='f' || text[i]=='s' || text[i]=='t' || text[i]=='k' || text[i]=='ç' || text[i]=='þ' || text[i]=='h' || text[i]=='p'){
			if(text[i+1]=='f' || text[i+1]=='s' || text[i+1]=='t' || text[i+1]=='k' || text[i+1]=='ç' || text[i+1]=='þ' || text[i+1]=='h' || text[i+1]=='p'){
				consonantaffinitycounter++;
			}
		}
	}
	printf("%d Consonant Affinity Found!\n",consonantaffinitycounter);
	
	printConsonantAffinity();	
}

int strongSoftConsonants(){ //sert-yumuþak ünsüzleri bulmak için fonksiyon
	
	int strongconsonantcounter=0;
	int softconsonantcounter=0;
	int i;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]=='f' || text[i]=='s' || text[i]=='t' || text[i]=='k' || text[i]=='ç' || text[i]=='þ' || text[i]=='h' || text[i]=='p' || text[i]=='F' || text[i]=='S' || text[i]=='T' || text[i]=='K' || text[i]=='Ç' || text[i]=='Þ' || text[i]=='H' || text[i]=='P'){
			strongconsonantcounter++;	
		}
		else if(text[i]=='b' || text[i]=='c' || text[i]=='d' || text[i]=='g' || text[i]=='ð' || text[i]=='j' || text[i]=='l' || text[i]=='m' || text[i]=='n' || text[i]=='r' || text[i]=='v' || text[i]=='y' || text[i]=='z' || text[i]=='B' || text[i]=='C' || text[i]=='D' || text[i]=='G' || text[i]=='J' || text[i]=='L' || text[i]=='M' || text[i]=='N' || text[i]=='R' || text[i]=='V' || text[i]=='Y' || text[i]=='Z'){
			softconsonantcounter++;
		}
	}
	
	printf("The number of strong consonants in your text: %d\n",strongconsonantcounter);
	printf("The number of soft consonants in your text: %d\n",softconsonantcounter);
	
	backtoMainMenu();
	
}

int printPluralWords(){ //çoðul kelimeleri yazdýrmak için fonksiyon
	
	char split[]=" ,.!?:;"; //kelimelerin bölüneceði karakterleri belirlemek için tanýmlama
	char *wordseparation=strtok(text,split); //strtok kullanarak yapýlan cümleyi kelimelerine parçalama iþlemi
	int i;
	 	
	for(i=0;i<strlen(wordseparation);i++){ //açýlan döngü ilk kelimeyi de eklemek için yapýldý
		if(wordseparation[i]=='l'){
			if(wordseparation[i+1]=='e' || wordseparation[i+1]=='a'){
				if(wordseparation[i+2]=='r'){		
						printf("%s, ",wordseparation);			
				}
			}
		}	
	}
		
	while(wordseparation!=NULL){ //metin bitimine kadar kontrolün saðlanmasý ve yazdýrýlmasý için yapýlan döngü
	
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

int pluralWords(){ //çoðul kelime bulma fonksiyonu
	
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

int numberOfSentences(){ //cümle sayýsý bulma fonksiyonu
	
	int numberofsentences=0;
	int	punctuationmarkcounter=0;
	int pointscounter=0;
	int i;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]=='?' || text[i]=='!' || text[i]==';' || text[i]==':' ){ //cümleyi bitiren karakterlerin koþullanmasý	
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

int numberOfWords(){ //kelime sayýsý bulma fonksiyonu
	
	int i;
	int spacecounter=0;
	int numberofwords;
	
	for(i=0;i<strlen(text);i++){ //cümledeki boþluk sayýsý bulma 
		if(text[i]==' '){
			spacecounter++;
		}
	}
	numberofwords=spacecounter+1; //parmak arasý yöntemiyle kelime sayýsý bulma
	
	printf("Number Of Words In Your Text: %d\n\n",numberofwords);
	
	backtoMainMenu();
}

int numberOfLetters(){ //harf sayýsý bulma fonksiyonu
			
	
	int numberofletters = strlen(text); //girilen metnin uzunluðunu atama
	int i;
	
	for(i=0;i<strlen(text);i++){
		if(text[i]==' ' || text[i]=='.' || text[i]=='?' || text[i]=='!' || text[i]==',' || text[i]=='-' || text[i]==';' || text[i]==':' || text[i]=='"' || text[i]=='(' || text[i]==')' || text[i]=='"' || text[i]=='1' || text[i]=='2' || text[i]=='3' || text[i]=='4' || text[i]=='5' || text[i]=='6' || text[i]=='7' || text[i]=='8' || text[i]=='9' || text[i]=='0'){ //cümkede harf sayýlmayacak karakterlerin belirlenmesi	
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
	
	ptrWord=strstr(text,word); //strstr ile string içinde string aramasý yapýldý
	
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
