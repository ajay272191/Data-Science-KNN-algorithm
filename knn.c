
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
	char featureType[size];
	struct{
		int data;
	}feature[max];

}testData[max];
struct{
	int value;
	int index;
	
}distance[max];
struct{
	char type[size];
	int  count;
}class[max];
int trainee,test,k;
int numFeature=3,classCount;
int scan();
int  sorting();
int classDataAssignment();
int setAndAssignClass(int testIndex);
int dissimilarity(int testIndex);
int classAssignment(int k, int testIndex);
int main(){

	scan();
	classDataAssignment();
	int testIndex=0;
	printf("k value: ");
	//k=3;
	scanf(" %d",&k);
	for(testIndex;testIndex<test;testIndex++){
	
		dissimilarity(testIndex);
		sorting();
		classAssignment(k,testIndex);
	}
return 0;
}
int classAssignment(int k, int testIndex){
	int assignmentIndex;
	if(k==1){
		assignmentIndex=distance[k-1].index;
		strcpy(testData[testIndex].featureType,traineeData[assignmentIndex].featureType);
		printf("test Data:%d :: %d %d %d ",testIndex+1,testData[testIndex].feature[0].data,testData[testIndex].feature[1].data,testData[testIndex].feature[2].data);
		printf("\tassigned class: %s\n",testData[testIndex].featureType);
	}
	else{

		setAndAssignClass(testIndex);
	}
	
}
int  sorting(){
    int min,mindx;
    int tempIndex;

    
    for(int i=1;i<trainee;i++)
    {
        min=distance[i].value;
        mindx=i;
        while(mindx>0 && distance[mindx-1].value>min)
        {
            distance[mindx].value=distance[mindx-1].value;

	    tempIndex=distance[mindx].index;
	    distance[mindx].index=distance[mindx-1].index;
	    distance[mindx-1].index=tempIndex;
            mindx--;
        }
        distance[mindx].value=min;
	//distance[mindx].index=mindx;
    }	//printf("sorted distance\n");
	for(int i=0;i<trainee;i++){
		//printf("value: %d index: %d\n",distance[i].value,distance[i].index);
	}
    
return 0;
}


int setAndAssignClass(int testIndex){

	char featureType[size];
	int featureIndex;
	for(int i=0;i<classCount;i++){
		class[i].count=0;
		for(int j=0;j<k;j++){
			featureIndex=distance[j].index;
			if(strcmp(class[i].type,traineeData[featureIndex].featureType)==0){
				class[i].count++;
			}
		}
	}
	int maxProbability=0;
	for(int i=0;i<classCount;i++){
		
		if(class[i].count>maxProbability){
			maxProbability=class[i].count;
			strcpy(featureType,class[i].type);			
		}
	}
	strcpy(testData[testIndex].featureType,featureType);
	printf("test Data:%d :: %d %d %d ",testIndex+1,testData[testIndex].feature[0].data,testData[testIndex].feature[1].data,testData[testIndex].feature[2].data);
	printf("\tassigned class:: %s\n",testData[testIndex].featureType);
	
}
int dissimilarity(int testIndex){

	int howFar;
	for(int i=0;i<trainee;i++){
		howFar=0;
		for(int j=0;j<numFeature;j++){

			howFar+=pow((traineeData[i].feature[j].data - testData[testIndex].feature[j].data),2);
		}
		distance[i].value=sqrt(howFar);
		distance[i].index=i;
		//printf("distance %d: index: %d\n",distance[i].value,distance[i].index);
	}
	
}
int scan(){

	FILE *fp;

	fp=fopen("traineeData.txt","r");
	if(fp==NULL){
		perror("error:");
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

	}fclose(fp);


	fp=fopen("testData.txt","r");
	if(fp==NULL){
		perror("error:");
		exit(0);
	}
	printf("test data set  :\n\n");
	fscanf(fp," %d %d %d",&testData[test].feature[0].data,&testData[test].feature[1].data,&testData[test].feature[2].data);
	printf("test Data:%d :: %d %d %d\n",test+1,testData[test].feature[0].data,testData[test].feature[1].data,testData[test].feature[2].data);
	test++;	
	while(1){

		
		fscanf(fp," %d %d %d",&testData[test].feature[0].data,&testData[test].feature[1].data,&testData[test].feature[2].data);
		if(feof(fp)) break;
		printf("test Data:%d :: %d %d %d\n",test+1,testData[test].feature[0].data,testData[test].feature[1].data,testData[test].feature[2].data);
		test++;	
	}fclose(fp);
	//printf("trainee %d test %d\n",trainee,test);
return 0;
}

int classDataAssignment(){

	int indexFlag;
	//printf("type of classes in Trainee data set are:\n");
	for(int i=0;i<trainee;i++){
		indexFlag=0;
		for(int j=0;j<trainee;j++){

			if(strcmp(traineeData[i].featureType,class[j].type)==0){
				indexFlag=1;j=trainee;}
		}
		if(indexFlag==0){
			strcpy(class[classCount].type,traineeData[i].featureType);
			//printf(" %s\n",class[classCount].type);
			classCount++;
		}
	}
	//printf("\nnumber of classes Is: %d",classCount);
return 0;
}













