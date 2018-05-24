#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 30
#define max  400
struct{
	char featureType[size];
	struct{	
		int data;
	}feature[max];

}traineeData[max];
struct{

	char type[size];
	int  count;
}class[max];
int trainee,test,k;
int numFeature=3,classCount;
int classDataAssignment();
int main(){

	FILE *fp;
	fp=fopen("traineeData.txt","r");
	if(fp==NULL){
		perror("error:");
		exit(0);
	}
	while(1){
			
		fscanf(fp," %d %d %d %s",&traineeData[trainee].feature[0].data,&traineeData[trainee].feature[1].data,&traineeData[trainee].feature[2].data,traineeData[trainee].featureType);
		if(feof(fp)) break;
		printf(" %d %d %d %s\n",traineeData[trainee].feature[0].data,traineeData[trainee].feature[1].data,traineeData[trainee].feature[2].data,traineeData[trainee].featureType);
		trainee++;

	}fclose(fp);

classDataAssignment();

}
int classDataAssignment(){

	int indexFlag;
	printf("type of classes in Trainee data set are:\n");
	for(int i=0;i<trainee;i++){
		indexFlag=0;
		for(int j=0;j<trainee;j++){

			if(strcmp(traineeData[i].featureType,class[j].type)==0){
				indexFlag=1;j=trainee;}
		}
		if(indexFlag==0){
			strcpy(class[classCount].type,traineeData[i].featureType);
			printf(" %s\n",class[classCount].type);
			classCount++;
		}
	}
	printf("total number of classes Is: %d",classCount);
return 0;
}











