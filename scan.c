#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 20
#define max  100
struct{

	char featureType[size];
	struct{
	
		int data;
	}feature[max];

}traineeData[max];
struct{

	char featureType[size];
	struct{
	
		int data;
	}feature[max];

}testData[max];
int trainee,test;
int main(){

	FILE *fp;

	fp=fopen("traineeData.txt","r");
	if(fp==NULL){
		printf("error:opening in file");
		exit(0);
	}
	printf("trainee data set  :\n");
fscanf(fp," %d %d %d %s",&traineeData[trainee].feature[0].data,&traineeData[trainee].feature[1].data,&traineeData[trainee].feature[2].data,traineeData[trainee].featureType);
printf(" %d %d %d %s\n",traineeData[trainee].feature[0].data,traineeData[trainee].feature[1].data,traineeData[trainee].feature[2].data,traineeData[trainee].featureType);
trainee++;
	while(1){
			
fscanf(fp," %d %d %d %s",&traineeData[trainee].feature[0].data,&traineeData[trainee].feature[1].data,&traineeData[trainee].feature[2].data,traineeData[trainee].featureType);
if(feof(fp)) break;
printf(" %d %d %d %s\n",traineeData[trainee].feature[0].data,traineeData[trainee].feature[1].data,traineeData[trainee].feature[2].data,traineeData[trainee].featureType);
trainee++;

	}


	fp=fopen("testData.txt","r");
	if(fp==NULL){
		printf("error:opening in file");
		exit(0);
	}
	printf("test data set  :\n\n");
	fscanf(fp," %d %d %d",&testData[test].feature[0].data,&testData[test].feature[1].data,&testData[test].feature[2].data);
	printf("%d %d %d\n",testData[test].feature[0].data,testData[test].feature[1].data,testData[test].feature[2].data);
	test++;	
	while(1){

		
		fscanf(fp," %d %d %d",&testData[test].feature[0].data,&testData[test].feature[1].data,&testData[test].feature[2].data);
		if(feof(fp)) break;
		printf("%d %d %d\n",testData[test].feature[0].data,testData[test].feature[1].data,testData[test].feature[2].data);
		test++;	
	}
printf("trainee %d test %d\n",trainee,test);
return 0;
}












