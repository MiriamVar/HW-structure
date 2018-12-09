#include <stdio.h>

typedef struct date{
	int d;
	int m;
	int y;
}
date;

typedef struct student{
	char fname[20];
	char lname[25];
	char gender[1];
	struct date dob;
}
student;

//(\b[a-z]+[ ]){2}[MF][ ]([1-9]|[1-2][0-9]|3[0-1])[ ]([1-9]|1[0-2])[ ](1[0-9]{3}|2(00[0-9]|01[0-8]))

int main(){
	FILE*f;
	struct student students[100];
	f=fopen("osoby.txt","r");
	
	int i=0;
	while(fscanf(f,"%s", &students[i].fname)!= EOF){
		fscanf(f,"%s", &students[i].lname);
		fscanf(f,"%s", &students[i].gender);
		fscanf(f,"%d", &students[i].dob.d);
		fscanf(f,"%d", &students[i].dob.m);
		fscanf(f,"%d", &students[i].dob.y);
		printf("%s %s %s %d %d %d\n", students[i].fname,students[i].lname,students[i].gender,students[i].dob.d,students[i].dob.m,students[i].dob.y);
		i++;
			
	}
	//iba zeny
	int j;
	printf("\nIba zeny:\n");
	for(j=0;j<i;j++){
		if(students[j].gender[0]=='F'){
			printf("%s %s \n", students[j].fname,students[j].lname);
		}
	}
	
	
	
	//menej ako 18 rokov
	int k, age=0;
	printf("\nNeplnoleti:\n");
	for(k=0;k<i;k++){
		age=2018-(students[k].dob.y);
		if(age<18){
			printf("%s %s %d\n", students[k].fname, students[k].lname,students[k].dob.y);
		}
	}
	
	//decembrovi ludia
	int l;
	printf("\nNarodeni v decembri:\n");
	for(l=0;l<i;l++){
		if(students[l].dob.m==12){
			printf("%s %s\n", students[l].fname, students[l].lname);
		}
	}
	
	
	//znamenie Panna
	int m;
	printf("\nNarodeny v znameni PANNA:\n");
	for(m=0;m<i;m++){
		if(students[m].dob.m==8){
			if (students[m].dob.d>=23 && students[m].dob.d<=31)
				printf("%s %s\n",students[m].fname, students[m].lname);
		}
		if(students[m].dob.m==9){
			if (students[m].dob.d>=1 && students[m].dob.d<=22)
				printf("%s %s\n",students[m].fname, students[m].lname);
		}
	}
	
	//podla datumu
	int n;
	for(m=0;m<i-1;m++){
		for(n=0;n<i-1-m;n++){
			if(students[n].dob.d>students[n+1].dob.d){
				struct student temp=students[n];
				students[n]=students[n+1];
				students[n+1]=temp;
			}
		}
	}
	for(m=0;m<i-1;m++){
		for(n=0;n<i-1-m;n++){
			if(students[n].dob.m>students[n+1].dob.m){
				struct student temp=students[n];
				students[n]=students[n+1];
				students[n+1]=temp;
			}
		}
	}
	for(m=0;m<i-1;m++){
		for(n=0;n<i-1-m;n++){
			if(students[n].dob.y>students[n+1].dob.y){
				struct student temp=students[n];
				students[n]=students[n+1];
				students[n+1]=temp;
			}
		}
	}
	printf("\nZoradeni podla datumu: \n");
	int r;
	for(r=0;r<i;r++){
		printf("%s %s %d %d %d\n", students[r].fname,students[r].lname,students[r].dob.d, students[r].dob.m,students[r].dob.y);
	
	}

	fclose(f);
}
