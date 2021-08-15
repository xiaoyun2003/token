#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
//char i[100]="int a=12;string b=\"12\";if(a==12){b=\"13\";}";
char i[100];
//例子:int a=12;string b="12";if(a==12){b="13";}
//
printf("请输入代码:\n");
gets(i);
	char* key[7]={"int","string","float","if","else","for","while"};	
	int syn=0;
	int q=0;
	int p;	
	do{
		p=0;
	char token[100]={};
	while(i[q]==' ') q++;
	if(i[q]>='0' && i[q]<='9' || i[q]>='a' && i[q]<='z'){
	while(i[q]>='0' && i[q]<='9' || i[q]>='a' && i[q]<='z'){
		token[p++]=i[q++];
	}
	//判断是否为整数
	//num 9 id 8
	if(atoi(token)==0){
	syn=8;	
	}else{
	syn=9;	
	}


for(int i=0;i<7;i++){
	if(strcmp(token,key[i])==0){
	syn=i+1;
	break;	
	}
}
	
		}else{
	
			switch(i[q]){
			case '(':
			syn=10;
			token[p++]=i[q++];
			break;
			case ')':
			syn=11;
			token[p++]=i[q++];
			break;
			case '+':
			syn=12;
			token[p++]=i[q++];
			break;
			case  '-':
			syn=13;
			token[p++]=i[q++];
			break;
			case '*':
			syn=14;
			token[p++]=i[q++];
			break;
			case '/':
			syn=15;
			token[p++]=i[q++];
			break;
			case '{':
			syn=16;
			token[p++]=i[q++];
			break;
			case '}':
			syn=17;
			token[p++]=i[q++];
			break;
			case '=':
			token[p++]=i[q++];
			syn=18;
			if(i[q]=='='){
				token[p]==i[q];
				syn=19;
			}
			break;
			case '>':token[p++]=i[q++];
			syn=20;
			if(i[q]=='='){
				token[p]==i[q];
				syn=21;
			}
			break;	
			case '<':token[p++]=i[q++];
			syn=22;
				if(i[q]=='='){
				token[p]==i[q];
				syn=23;
			}
			break;
			case ';':
			syn=24;
			token[p++]=i[q++];
			break;
			case '"':
			syn=25;
			token[p++]=i[q++];
			break;
			case '\n':
			syn=27;
			q++;
			break;
			case '\0':
			syn=-2;
			 break;
		default:
				syn=-1;
			}	
		}
		
		switch(syn){
		case -1:printf("未知的字符:%d\n",(int)token[q-1]);
		break;
		default:
		printf("(%d,%s)\n",syn,token);
		}
	}while(syn>0);
}