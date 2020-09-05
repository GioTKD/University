#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct iscritti{
	int matr;
	struct iscritti* nexxt;
};
typedef struct iscritti iscritti;
 
struct appello{
int gg;
int mm;
struct iscritti* isc;
struct appello* next;
};
typedef struct appello appello;
 
struct materia{
char name[20];
int cfu;
int voto;
int anno;
struct appello* app;
struct materia* sux;
};
typedef struct materia materia;
 
struct studente{
char nome[20];
char cognome[20];
char password[20];
int matricola;
int cf;
int anno;
struct studente* pross;
struct materia* ma;
};
typedef struct studente studente;
 
struct professore{
char nomm[20];
char cogn[20];
char id[20];
char pw[20];
struct professore* succ;
};
typedef struct professore professore;



				//		**********RICERCHE**********
materia* cerca_mat(materia* head,char n[20]){
 
    materia* p;
    p = head;
    printf("Inserisci il nome della materia\n");
    scanf("%s",n);
    while(p != NULL){
		if(p == NULL){
			printf("Materia non trovata");
			return 0;
		}
        if(strcmp(p->name,n)==0){
            printf("\nTROVATA\n");
            return p;
        }else{
            p = p->sux;
        }
    }
}

void stampa_appp(appello *p){
	
	while(p != NULL){
	
		printf("%d/%d\n", p->gg, p->mm);
		p = p->next;
	}
}

void stampa_app(materia* head){
	
	appello* temp = NULL;
	
	while(head != NULL){
		printf("%s %d\n",head->name,head->cfu);
		
		stampa_appp(head->app);
		head = head->sux;
	}
}

appello* cerca_app(appello* head){
	
	int ggg;
	int mmm;
	printf("Inserisci il giorno\n");
	scanf("%d",&ggg);
	printf("Inserisci il mese\n");
	scanf("%d",&mmm);
	while(head != NULL){
		if(head == NULL){
			printf("appello non esistente");
			break;
		}
		if(head->gg == ggg && head->mm == mmm){
			printf("\nTROVATO\n");
			return(head);
		}else{
			printf("NON TROVATO\n");
			head = head->next;
		}
	}
}
 
 
				//		************INSERIMENTI**********
studente* reg_stud(studente** head,int k){
    studente* p = (studente*)malloc(sizeof(studente));
    p->ma = NULL;
    studente* r = *head;
    studente* q = *head;
    studente* t = *head;
    printf("Inserisci il tuo nome\n");
    scanf("%s",p->nome);
 
 
    printf("inserisci il tuo cognome\n");
    scanf("%s",p->cognome);
 
 
    printf("Scegli la tua password\n");
    scanf("%s",p->password);
    p->matricola = k;
    p->cf = 0;
 
    p->anno = 1;
    printf("LA TUA MATRICOLA E' %d\n\n\n\n",p->matricola);
 
 
    while((q != NULL)&&(q->matricola < p->matricola)){
 
        r = q;
        q = q->pross;
 
 
    }
    if(q ==*head)
        *head = p;
    else{
        r ->pross = p;
    }
        p->pross =q;
 
}

professore* reg_prof(professore** head,FILE* fp){
 
    professore* p = (professore*)malloc(sizeof(professore));
    professore* r = *head;
    professore* q = *head;
 
    printf("\nInserisci il tuo nome\n");
    scanf("%s",p->nomm);
 
    printf("Inserisci il tuo cognome\n");
    scanf("%s",p->cogn);
 
    printf("Inserisci il tuo id\n");
    scanf("%s",p->id);
 
    printf("Inserisci la tua password\n");
    scanf("%s",p->pw);
 
 
    while((q != NULL)&&(q->cogn<p->cogn)){
        r = q;
        q = q->succ;
    }
    if(q==*head)
        *head=p;
    else{
        r->succ = p;
    }
        p->succ = q;
        fp = fopen("prof.txt","a+");
    if(fp == NULL){
            printf("ERRORE !");
        exit(1);
    }
    else{
        fprintf(fp,"%s %s %s %s\n",p->nomm,p->cogn,p->id,p->pw);
 
    }
 
}

materia* ins_mat(materia** head,materia*p){
	materia* q = *head;
	materia* r = *head;
	p = (materia*)malloc(sizeof(materia));
	p->app =NULL;
	printf("\nInserisci il nome della materia\n");
    scanf("%s",p->name);
 
    printf("Inserisci l'anno accademico\n");
    scanf("%d",&(p->anno));
 
    printf("Inserisci il peso in CFU");
    scanf("%d",&(p->cfu));
	
	p->voto = 0;
	   while((q != NULL)&&strcmp(q->name,p->name)<0){
        r = q;
   q = q->sux;
   
   }
   if(q == NULL){
	   p->sux = NULL;
   
   if(q==*head)
    *head = p;
   else{
    r->sux = p;
   }
   }
   if((q != NULL)&&strcmp(q->name,p->name)>0){
	   if(q == *head){
	    *head = p;
	   }
   else{
    r->sux = p;
   }
    p->sux = q;
   }
}

appello* inss_app(appello** head){
	appello* p;
	p = (appello*)malloc(sizeof(appello));
	int g;
	int m;
	printf("GIORNO\n");
	scanf("%d",&g);
	
	printf("MESE\n");
	scanf("%d",&m);
	p->gg = g;
	p->mm = m;
	p->isc = NULL;
	p->next = *head;
	*head = p;
	
}

void ins_app(materia* m){
	char n[20];
    printf("Inserisci il nome della materia\n");
    scanf("%s",n);
    while(m != NULL){
        if(strcmp(m->name,n)==0){
            printf("\nTROVATA\n");
			inss_app(&m->app);
			return;
        }else{
            m = m->sux;
        }
    }
}

 iscritti* ins_isc(iscritti** head,int n){
	iscritti* p;
	p = (iscritti*)malloc(sizeof(iscritti));
	p->matr = n; 
	p->nexxt = *head;
	*head = p;
	
	printf("%d", p->matr);
}
 



				//		**********LOGIN**********
studente*  log_stu(studente* p){
 
    int ma;
    char ps[20];
 
    printf("Inserisci la tua matricola\n");
    scanf("%d",&ma);
 
    printf("Inserisci password\n");
    scanf("%s",ps);
 
    while(p!=NULL){
 
            if(ma == p->matricola && (strcmp(ps,p->password)) == 0){
                printf("\n\n\nLogin effettuato\n\n\n");
                return p;
            }
            else{
 
                p = p->pross;
 
            }
    }
return p;
 
 
}

professore* log_prof(professore* p){
    char idd[20];
    char ps[20];
 
    printf("Inserisci il tuo id\n");
    scanf("%s",idd);
 
    printf("Inserisci la tua password\n");
    scanf("%s",ps);
 
    while(p != NULL){
 
        if((strcmp(idd,p->id))==0 &&(strcmp(ps,p->pw))==0){
 
        printf("\n\nLOGIN EFFETTUATO\n\n");
        return p;
        }
 
    else{
 
        p = p->succ;
        }
    }
return p;
}



				//		**********FUNZIONI STUDENTE**********

void canc(studente** head){
	

 
studente*r = *head;
studente* q = *head;
int mat;
 
printf("Inserisci la tua matricola\n");
scanf("%d",&mat);
while((q != NULL)&&(q->matricola != mat)){
 
    r = q;
    q = q->pross;
}
if(q == NULL){
    printf("UTENTE NON ESISTENTE");
    return;
}else{
if(q == *head)
    *head = (*head)->pross;
else{
 
    r->pross = q->pross;
    free(q);
    printf("UTENTE ELIMINATO");
}
}
 
}

void libretto(studente* head){
materia* temp = NULL;
        printf("Nome: %s Cognome: %s \n",head->nome,head->cognome);     //CREDO SIA SISTEMATO
        temp = head->ma;
        while(temp != NULL){
        printf("%s %d %d\n ",temp->name,temp->voto,temp->cfu);
        temp = temp->sux;
 
}
 
}

void laurea(studente* p){
 
int mat;
materia* m;
appello* a = NULL;
char lau[10]="laurea";
 
printf("Inserisci la tua matricola");
scanf("%d",&mat);
while(p->matricola != mat){
        if(p== NULL)
        printf("UTENTE NON ESISTENTE");
        else{
        p = p->pross;
        }
}
 
    if(p->cf >30){
        printf("\nLAUREATO !\n");
    }
    else{
        printf("NON HAI ABBASTANZA CREDITI\n");
        return;
 
    }
 
 
}

void iscr_pross(studente* p){
int mat;
 
printf("Inserisci la tua matricola");
scanf("%d",&mat);
 
while(p->matricola != mat){
        if(p == NULL)
        printf("Utente non esistente");
        else{
        p = p->pross;
        }
 
}
 
if(p->cf > 6){
 
    printf("Puoi passare al prossimo anno");
    p->anno = p->anno+1;
 
}
else{
 
    printf("NON HAI ABBASTANZA CREDITI");
 
 
}
return;
 
}

void iscr_esame(studente* p,materia* head){
	appello* a;
	materia* m = head;
	char n[20];
	stampa_app(head);
		m=cerca_mat(m,n);
		if(m == NULL){
			printf("Materia non esistente");
			return;
		}
		a=cerca_app(m->app);
		if(a != NULL)
		ins_isc(&a->isc,p->matricola);
}
 
 int max(studente* head){
	 int k=0;
	 while(head != NULL){
		 if(head->matricola>k)
			 k = head->matricola;
		 head = head->pross;
	 }
    return k+1;
   
}
 
 
				//		**********FUNZIONI PROFESSORE**********
				
void stampa(studente* head){
while (head != NULL){
printf("%s %s %d",head->nome,head->cognome,head->matricola);
head = head->pross;
}
}
 
void mat(materia** head, materia m){
 
        materia* p=(materia*)malloc(sizeof(materia));					//LA UTILIZZO PER INSERIRE NELLA SOTTOLISTA MATERIA DELLO STUDENTE
        strcpy(p->name,m.name);
        p->voto = m.voto;
        p->cfu = m.cfu;
        p->sux = *head;
        *head = p;
 
 
}

void conf_voto(studente* p){
 
    //p = (studente*)malloc(sizeof(studente));
    //a = (appello*)malloc(sizeof(appello));
    materia m;
    int matricol;
    int cfu;
    printf("Inserisci la matricola dello studente\n");
    scanf("%d",&matricol);
 
    while(p != NULL){
 
        if(matricol == p->matricola){
 
            printf("Inserisci il nome della materia\n");
            scanf("%s",m.name);
            printf("Inserisci il voto\n");
            scanf("%d",&m.voto);
            printf("Inserisci i CFU della materia superata\n");
            scanf("%d",&m.cfu);
            p->cf = p->cf+m.cfu;
            printf("**CFU AGGIUNTI CON SUCCESSO**\n");
            mat(&(p->ma),m);
            return;
        }
        else{
 
            p = p->pross;
        }
 
    }
 
}


			//			**********SALVATAGGI**********
			
int conta_lib(materia* head){
    int count = 0;
    if(head != NULL){
        count++;
        head = head->sux;
    }
    return count;
}
 		
void salva_stud(studente* head){
    FILE* f;
    int zero = 0;
    if(f =fopen("data.txt","w")){
        while(head != NULL){
            //printf("\n\n%d\n\n",head->anno);
            fprintf(f,"%s\n%s\n%s\n%d\n%d\n%d\n",head->nome,head->cognome,head->password,head->matricola,head->cf,head->anno);
            materia* p = head->ma;
            if(p != NULL){
                int count = conta_lib(p);
                fprintf(f,"%d\n",count);
                while(p!=NULL){
                    fprintf(f,"%s %d %d\n",p->name,p->voto,p->cfu);
                    //printf("%s %d %d\n",p->name,p->voto,p->cfu);
                    p = p->sux;
                }
            }else{
                fprintf(f,"%d\n",zero);
                //printf("Non ci materie");
            }
            head = head->pross;
        }
    }else{
        printf("ERROR");
        return;
    }
    printf("Salvato con successo !");
    fclose(f);
}

int conta(appello* head){
    int count=0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}
 
 int conta_iscr(iscritti* head){
	int count = 0;
	while(head != NULL){
		count++;
		head = head->nexxt;
	}
	return count;
}


void salva_app(materia* head){
    FILE* f;
    int zero = 0;
    if(f =fopen("app.txt","w")){
        while(head != NULL){
            fprintf(f,"%s\n%d\n%d\n%d\n",head->name,head->cfu,head->voto,head->anno);
            appello* p = head->app;
			iscritti* is;
            if(p != NULL){				
                int count = conta(p);
                fprintf(f,"%d\n",count);
                while(p != NULL){
                    fprintf(f,"%d %d\n",p->gg,p->mm);
					is = p->isc;
				if(is != NULL){
				int countt = conta_iscr(is);
				fprintf(f,"%d\n",countt);
			while(is != NULL){
				fprintf(f,"%d\n",is->matr);
				is = is->nexxt;				
			}
			}else{
				fprintf(f,"%d\n",zero);
				printf("Nessuno studente iscritto");
			}
					p = p->next;
                }
            
			}else{
                fprintf(f,"%d\n",zero);
                printf("Non ci sono appelli");
				fprintf(f,"%d\n",zero);
				printf("Nessuno studente iscritto");
            }
			
            head = head->sux;
        }
    }else{
        printf("ERROR");
        return;
    }
    printf("Salvato con successo !");
    fclose(f);
}

			//			**********CARICAMENTI**********
			
void inser_lib(studente** head,studente elem,materia* mat){
    studente* p;
    studente* r = *head;
    studente* q = *head;
    p = (studente*)malloc(sizeof(studente));
    p->ma = mat;
    strcpy(p->nome,elem.nome);
    strcpy(p->cognome,elem.cognome);
    strcpy(p->password,elem.password);
    p->matricola = elem.matricola;
    p->cf = elem.cf;
    p->anno = elem.anno;
    while((q != NULL)&&(q->matricola < p->matricola)){
        r = q;
        q = q->pross;
    }
    if(q == *head)
    *head = p;
    else{
        r->pross = p;
    }
    p->pross = q;
}
 
void mats(materia** head, materia ma){
    materia* m;
    m = (materia*)malloc(sizeof(materia));
    strcpy(m->name,ma.name);
    m->cfu = ma.cfu;
    m->voto = ma.voto;
    m->anno = ma.voto;
    m->sux = *head;
    *head = m;
}
 			
studente* carica_lib(materia** testa){
    FILE* fpx = fopen("data.txt","r");
    studente dat;
    studente* head;
    int count;
    int num;
    head = NULL;
    if(fpx == NULL){
        printf("ERROR");
        exit(1);
    }else{
        while(fscanf(fpx,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n",dat.nome,dat.cognome,dat.password,&dat.matricola,&dat.cf,&dat.anno,&count)!= EOF){
            materia* p;
            p = NULL;
            materia max;
            if(count!=0){
                for(int j =0;j<count;j++){
                    fscanf(fpx,"%s %d %d",max.name,&max.voto,&max.cfu);
                    mats(&p,max);
                }
            }
            inser_lib(&head,dat,p);
            //inser_stud
        }
    }
    return head;
}
 
void inser_prof(professore** head, professore elem){
    professore* p;
    professore* r = *head;
    professore* q = *head;
    p = (professore*)malloc(sizeof(professore));
    strcpy(p->nomm,elem.nomm);
    strcpy(p->cogn,elem.cogn);
    strcpy(p->id,elem.id);
    strcpy(p->pw,elem.pw);
    while((q != NULL)&&(q->cogn<p->cogn)){
        r =q;
        q = q->succ;
    }
    if(q==*head)
        *head=p;
    else{
        r->succ = p;
    }
    p->succ =q;
   
}
 
professore* carica_prof(professore** head){
    FILE* f = fopen("prof.txt","r");
    professore* p= NULL;
    professore dat;
    if(f == NULL){
        printf("Errore file non esistente!");
        exit(1);
    }else{
        while(!feof(f)){
            fscanf(f,"%s\n%s\n%s\n%s\n",dat.nomm,dat.cogn,dat.id,dat.pw);
        }
        inser_prof(&p,dat);
    }
    return p;
}

void apxx(appello** head,appello ap,iscritti* is){
    appello* a;
    a = (appello*)malloc(sizeof(appello));
    a->isc = is;
	a->gg = ap.gg;
    a->mm = ap.mm;
    a->next = *head;
    *head = a;
   
}

void inser_mat(materia** head,materia elem,appello* ap){
        materia* p;
        materia* r = *head;
        materia* q = *head;
        p = (materia*)malloc(sizeof(materia));
        p->app = ap;
        strcpy(p->name,elem.name);
        p->cfu = elem.cfu;
        p->voto = elem.voto;																															//SEG FAULT
        p->anno = elem.anno;
        while((q != NULL)&&(q->name<p->name)){
            r = q;
            q = q->sux;
        }
        if(q == *head)
        *head=p;
        else{
            r->sux = p;
        }
        p->sux = q;
    }

void iscrr(iscritti** head,iscritti is){
	iscritti* a;
	a = (iscritti*)malloc(sizeof(iscritti));
	a->matr = is.matr;
	a->nexxt = *head;
	*head = a;
}

materia* carica_app(appello** testa){
    FILE* fpx = fopen("app.txt","r");
    materia dat;
    materia* head;
	iscritti iss;
    int count;
	int countt;
    int num;
    head = NULL;
    if(fpx == NULL){
        printf("ERROR");
        exit(1);
    }else{
        while(fscanf(fpx,"%s\n%d\n%d%d\n%d\n",dat.name,&dat.cfu,&dat.voto,&dat.anno,&count)!=EOF){
        appello* p;																										//SEG FAULT
        p = NULL;
        appello ap;
        if(count !=0){
            for(int j =0;j<count;j++){
                fscanf(fpx,"%d %d\n", &ap.gg,&ap.mm);								//INSERIRE UN ALTRO FOR PER IL COUNTT
               	fscanf(fpx,"%d\n",&countt);
				iscritti* is;
				is = NULL;
			if(countt != 0){
				for(int j = 0; j<countt;j++){
				fscanf(fpx,"%d\n",&iss.matr);
				
				iscrr(&is,iss);
			}
		}
                apxx(&p,ap,is);
            }
        } 

        inser_mat(&head,dat,p);
        }
    }
    return head;
}
 

			//			**********FUNZIONI PER PROVARE**********


int main(){
 
int scelta_prof = -1;
int login = -1;
int scelta_stud = -1;
studente* s =NULL;
studente* temp;
professore* tem;
professore* p = NULL;
materia* m = NULL;
materia* maa;
appello* a = NULL;
appello* ap = NULL;
iscritti* iss = NULL;
iscritti* isss = NULL;
FILE* fp = NULL;
int k = 1;
FILE* fpp = NULL;
FILE* fpx = NULL;
m = carica_app(&a);
s = carica_lib(&m);
p = carica_prof(&p);
char n[20];
 
k = max(s);
 
while(login != 0){
 
    printf("COME VUOI ACCEDERE ?\n");
    printf("1.LOGIN STUDENTE\n2.LOGIN PROFESSORE\n3.REGISTRA NUOVO STUDENTE\n4.REGISTRA NUOVO PROFESSORE\n0.PER USCIRE\n");
      scanf("%d",&login);
 
    switch(login){
 
case 1 :{
    s=log_stu(s);
    scelta_stud = -1;
    while(scelta_stud != 0){
        printf("\n****MENU STUDENTE****\n");
            printf("1.RINUNCIA AGLI STUDI\n");
            printf("2.LIBRETTO\n");
            printf("3.ISCRIVITI AD UN APPELLO\n");
            printf("4. PROCEDURA DI LAUREA\n");
            printf("5.ISCRIZIONE ANNI SUCCESSIVI\n");
            printf("0. PER USCIRE\n");
            scanf("%d",&scelta_stud);
        switch(scelta_stud){
 
        case 1:
            canc(&s);
        break;
 
        case 2 :
            libretto(s);
            break;
        case 3:
            iscr_esame(s,m);
            break;
        case 4:
            laurea(s);
            break;
        case 5:
            iscr_pross(s);
            break;
			
		case 6:
			stampa_app(m);
			break;
       
        }
 
    }
 
    break;
}
case 2:{
    tem =log_prof(p);
    scelta_prof = -1;
    while(scelta_prof != 0){
 
         printf("\n1.INSERISCI NUOVA MATERIA\n");
         printf("2.INSERISCI APPELLO\n");
         printf("3.CONFERMA VOTO APPELLO\n");
         printf("4.VISUALIZZA STUDENTI ISCRITTI\n");
         scanf("%d",&scelta_prof);
 
         switch(scelta_prof){
          case 1:
                    ins_mat(&m,maa);

                    break;
 
                case 2:
                    ins_app(m);
                    break;
                case 3:
                    conf_voto(s);
                    break;
                case 4:
                    stampa(s);
                    break;
				case 5:
				m=cerca_mat(m,n);
				a=cerca_app(m->app);
				break;
         }
 
 
    }
break;
}
case 3:
    reg_stud(&s,k);
    k = k+1;
    break;
case 4:
    reg_prof(&p,fp);
    break;
case 0 :
    printf("\n\n**ARRIVEDERCI**\n\n");
    salva_app(m);
    salva_stud(s);
    break;
    }
 
 
}
 
}

 