#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
sem_t d,p,mutex;
int flag=0;
char buffer[1000];
void *consultDoctor(){
	sem_wait(&p);
	//printf("Enter Patient Process\n");
	
	printf("By Patient - Enter Your Symptoms : ");
	fgets(buffer,1000,stdin);
	
	strcat(buffer," ");
	sleep(1);
        sem_post(&d);
	sem_post(&p);
	
}

void *treatPatient(){
	sem_wait(&d);
	printf("By Doctor - Enter Treatment as per Disease : ");
	char tmp[1000];
	fgets(tmp,1000,stdin);
	
	strcat(buffer,tmp);
	sleep(1);
	sem_post(&mutex);
        sem_post(&d);
         
	
}

void *noteTreatment(){
	sem_wait(&mutex);
	
        //printf("Enter Patient Process to all detail\n");
	printf("\nPrescription :-\n");
	sleep(1);
	printf("%s",buffer);
        
	sem_post(&p);
        sem_post(&mutex);
  
        
}

int main(){
	printf("************** Doctor Patient Management ************\n ");
	pthread_t p1,p2,p3;
        
        int i=1;
        
        printf("Doctor Takes 20-30 min for one patient.He is in the clinic for 3 hrs.\nSo he can attend 5-6 patient around.\n\n");
        //scanf("%d",n);        
        
        int m=1;
        if(m<=5){
        printf("Doctor can attend only 5 patient a day.\n");
          while(i<=5){
        if(m==5)
        printf("\n--Last patient--\n\n");
        printf("\npatient %d\n\n",i);
        sem_init(&d,0,0);
	sem_init(&p,0,1);
	sem_init(&mutex,0,0);

	
        pthread_create(&p1,NULL,consultDoctor,NULL);
	pthread_join(p1,NULL);
	
        pthread_create(&p2,NULL,treatPatient,NULL);
	pthread_join(p2,NULL);
        pthread_create(&p3,NULL,noteTreatment,NULL);
	pthread_join(p3,NULL);
        i++;
        

}
                }
   

        printf("Enough for today.\n\nPlease come tomorrow.\n---Thank you.---");
	return 0;
}























