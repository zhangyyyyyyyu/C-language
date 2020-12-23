#include<iostream>
using namespace std;//!bug:cout,cin���ô���
#define MaxVNum 100//���������!bug:define���ø��ֺ�
#define MaxSize 100


typedef struct Painter{//ʵ��
    int id;
	char name[20];
	int age;
	char sex[10];
	char city[20];
	int careerAge;
}Painter;

typedef struct PainterNode{//��������
    Painter data;
	struct PainterNode *next;
}PainterNode, *LinkList;

int InitList(LinkList &L){//�����ʼ��
    L=new PainterNode;
	L->next=NULL;
	return 1;
}

int InsertList(LinkList &L, Painter painter){//1.ʵ����Ӳ���
    PainterNode *p, *s;
	p=L;
	while(p->next)
		p=p->next;//��ȫ����Ϣ����

	s=new PainterNode;
	s->data=painter;
	s->next=NULL;

	p->next=s;
	return 1;
}

int DeleteList(LinkList &L, int id){//2.ʵ��ɾ������������idɾ����
	PainterNode *p;//pΪid���ڽڵ��ǰ���ڵ�ָ��
	p=L;
	while(p->next){
		if(p->next->data.id==id)
			break;
		p=p->next;
	}
    
	if(p->next!=NULL)
	    p->next=p->next->next;
	else{
	    cout<<"Ҫɾ���Ľ�㲻���ڣ�";
		return 0;
	}
}

void EditList(LinkList &L, int id){//3.�޸�painter��Ϣ������Id��
    Painter painter;
	PainterNode *p;
    p=L->next;
	while(p){
		if(p->data.id==id){ 
			DeleteList(L,id);
            cout<<"***������������Ϣ***"<<endl;
			cout<<"������id��";
			cin>>painter.id;
			cout<<"������������";
			cin>>painter.name;
			cout<<"���������䣺";
			cin>>painter.age;
			cout<<"�������Ա�";
			cin>>painter.sex;
			cout<<"���������ڳ��У�";
			cin>>painter.city;
			cout<<"������������ޣ�";
			cin>>painter.careerAge;
			InsertList(L, painter);//����bug:ͬһ�������в��ܵ������Ͳ�ͬ��һ��voidһ��int�ͳ�bug���ĺ���
		}else
            cout<<"��������ȷ��id�ţ�";
		p=p->next;
	}

}

void LocateListId(LinkList L, int id){//4.��ѯpainter����Ϣ������id��ѯ��
	PainterNode *p;
	p=L->next;
	while(p){
		if(p->data.id==id){
			cout<<"id��"<<p->data.id<<endl;
			cout<<"������"<<p->data.name<<endl;
			cout<<"���䣺"<<p->data.age<<endl;
			cout<<"�Ա�"<<p->data.sex<<endl;
			cout<<"���ڳ��У�"<<p->data.city<<endl;
			cout<<"�������ޣ�"<<p->data.careerAge<<endl;
		}else{
			cout<<"��ѯ�����������id��";
		}
		p=p->next;
	}
}

int GetListNum(LinkList L){//5.ͳ��painter�ĸ���
	int num=0;
	PainterNode *p;
	p=L;
	while(p->next){
		num++;	
		p=p->next;
	}
	return num;
}

void DisplayList(LinkList L){//6.ʵ������б����
    PainterNode *p;
	p=L->next;
	while(p){
	    cout<<"id:"<<p->data.id<<endl;
		cout<<"����"<<p->data.name<<endl;
		cout<<"���䣺"<<p->data.age<<endl;
		cout<<"�Ա�"<<p->data.sex<<endl;
		cout<<"���ڳ��У�"<<p->data.city<<endl;
		cout<<"�������ޣ�"<<p->data.careerAge<<endl;
		p=p->next;
	}
}
//------
void DisplayMenu(){
	cout<<"painter��Ϣ����ϵͳ���ܲ˵�"<<endl;
	cout<<"1.����painter"<<endl;
	cout<<"2.ɾ��painter"<<endl;
	cout<<"3.�޸�painter"<<endl;
	cout<<"4.��ѯpainter��Ϣ"<<endl;
	cout<<"5.ͳ��painter����"<<endl;
	cout<<"6.���painter�б�"<<endl;
	cout<<"7.�˳�"<<endl;							
}
//----------------------------------����Ϊpainter����

void DisplayChoose(){
	cout<<"��ѡ����Ҫ�򿪵�painter���ܣ�"<<endl;
    cout<<"1.painter����ϵͳ���ܲ˵�"<<endl;
	cout<<"2.painterͼ�ṹ���ݴ������"<<endl;
}

void InputPainter(Painter &painter){
    cout<<"������id��";
	cin>>painter.id;
	cout<<"������������";
	cin>>painter.name;
	cout<<"���������䣺";
	cin>>painter.age;
	cout<<"�������Ա�";
	cin>>painter.sex;
	cout<<"���������ڳ��У�";
	cin>>painter.city;
	cout<<"������������ޣ�";
	cin>>painter.careerAge;
}

//---------------------------------����Ϊpainterͼ
void DisplayTu(){
	cout<<"painteeͼ�ṹ���ݴ������"<<endl;
	cout<<"1.����painterͼ"<<endl;
	cout<<"2.������ȱ�����ʽ��ӡ����painter"<<endl;
	cout<<"3.���չ�ȱ�����ʽ��ӡ����painter"<<endl;
	cout<<"4.�˳�"<<endl;
}
//------
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
	Painter data;
	ArcNode *firstarc;
}VNode,AdjList[MaxVNum];

typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;
  
int LocateGraph(ALGraph G, int id){
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertices[i].data.id==id)
			break;
	if(i==G.vexnum)
		i=-1;
	return i;
}

void CreateUDG(ALGraph &G){//1.����painterͼ
	int i,j,k;
	int id;
    ArcNode *s;
	cout<<"�����붥������������";
	cin>>G.vexnum;
	cout<<"�����������������";
	cin>>G.arcnum;

	for(k=0;k<G.vexnum;k++){
		InputPainter(G.vertices[k].data);
        G.vertices[k].firstarc=NULL;
	}

    for(k=0;k<G.arcnum;k++){
		cout<<"�����뵱ǰ�ߵ�һ��painter��id��";
		cin>>id;
		i=LocateGraph(G,id);

		cout<<"�����뵱ǰ�ߵ���һ��painter��id��";
		cin>>id;
		j=LocateGraph(G,id);

		//Ϊ[i]����ָ��j�ı߽�㣬�ҵ�����ͷ�巨
        s=new ArcNode;
		s->adjvex=j;
		s->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=s;
		//Ϊ[j]����ָ��i�ı߽�㣬�ҵ�����ͷ�巨
		s=new ArcNode;
		s->adjvex=i;
		s->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=s;
	}

}

typedef struct SqStack{//����ջ!bug:typedef�ĺ����Ͳ�Ҫ��()
	int *base;
	int *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S){//ջ�ĳ�ʼ��
	S.base=new int[MaxSize];
	if(!S.base)
		return -1;
	S.top=S.base;
	S.stacksize=MaxSize;
	return 1;
}

int EmptyStack(SqStack S){//�ж�ջ�շ�
    if(S.top==S.base)
		return 1;
	else 
		return 0;
}

int Push(SqStack &S, int e){//ѹջ
	if(S.top-MaxSize==S.base)
		return 0;
	else{
		*(S.top)=e;
		S.top++;
		return 1;
	}
}

int Pop(SqStack &S, int &e){//��ջ
    if(S.base==S.top)
		return 0;
	else{
		S.top--;
		e=*(S.top);
	    return 1;
	}
}

void DisplayPainter(Painter p){
	cout<<"id:"<<p.id<<endl;
	cout<<"������"<<p.name<<endl;
	cout<<"���䣺"<<p.age<<endl;
	cout<<"�Ա�"<<p.sex<<endl;
	cout<<"���ڳ��У�"<<p.city<<endl;
	cout<<"�������ޣ�"<<p.careerAge<<endl;
}

void DepthTraverseGraph(ALGraph G){//2.��ȱ������е�painter
    int id,v,i;
	SqStack S;
	ArcNode *p;
	int visited[MaxVNum];
	cout<<"�������ʼ���id:";
	cin>>id;
	v=LocateGraph(G, id);
	for(i=0;i<G.vexnum;i++)
		visited[i]=0;
	InitStack(S);
	visited[v]=1;
	Push(S, v);
	while(!EmptyStack(S)){//��ջ����
		Pop(S, v);
        DisplayPainter(G.vertices[v].data);
		p=G.vertices[v].firstarc;
		while(p){
			if(visited[p->adjvex]==0){
				Push(S, p->adjvex);
			    visited[p->adjvex]=1;
			}
			p=p->nextarc;
		}
	}
	i=0;
}	

typedef struct Queue{//���еĴ����ṹ
    int *base;
	int front,rear;
}SeQueue;

int InitQueue(SeQueue &Q){
    Q.base=new int[MaxSize];
	if(!Q.base)
		return 0;
	Q.front=0;
	Q.rear=0;//ͷβָ�붼Ϊ0������Ϊ��
	return 1;
}

int EmptyQueue(SeQueue &q){ //�ж��Ƿ�Ϊ����
	if(q.rear==q.front)
		return 1;
	return 0;
}

int EnQueue(SeQueue &Q,int e){//���
	if((Q.rear+1)%MaxSize==Q.front)
		return 0;
	Q.base[Q.rear]=e;//��Ԫ�ؼ��ڶ�β
	Q.rear=(Q.rear+1)%MaxSize;//��βָ��+1
	return 1;
}

int DeQueue(SeQueue &Q,int &e)
{//����
	if(Q.front==Q.rear)
		return 0;
	e=Q.base[Q.front];//��Ԫ�ز����β
	Q.front=(Q.front+1)%MaxSize;//��βָ��+1
	return 1;
}

void BFS(ALGraph G){//3.������ȱ�����ʽ��ӡpainter
    int visited[MaxVNum];
	ArcNode *p;
	int i,v,id;
    Queue Q;
	cout<<"�������ʼ���id:";
	cin>>id;
	v=LocateGraph(G, id);
    for(i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    InitQueue(Q);  //��ʼ������ 
   	visited[v]=1;
	EnQueue(Q, v);
	while(!EmptyQueue(Q)){//��ջ����
		DeQueue(Q, v);
        DisplayPainter(G.vertices[v].data);
		p=G.vertices[v].firstarc;
		while(p){
			if(visited[p->adjvex]==0){
				EnQueue(Q, p->adjvex);
			    visited[p->adjvex]=1;
			}
			p=p->nextarc;
		}
	}
}

int main(){
	int choose;

	int id;
	int choice;
	int num;
    Painter painter;
	LinkList L;
	InitList(L);//Ϊ����������ݷ�װ

	ALGraph G;//Ϊͼ�Ľṹ��װ
    
    while(1){//�Ƚ���1������
		DisplayChoose();
		cout<<"���ѡ�";
		cin>>choose;
		if(choose==1){//2������
			DisplayMenu();
			cout<<"����ѡ�";
			cin>>choice;
			switch(choice){
			   case 1:
				   InputPainter(painter);
				   InsertList(L,painter);
				   break;
			   case 2:
				   cout<<"Ҫɾ���ڵ��id��:";
				   cin>>id;
				   DeleteList(L, id);
				   break;
			   case 3:
				   cout<<"Ҫ�޸ĵĽ��id�ǣ�";
				   cin>>id;
				   EditList(L, id);
				   break;
			   case 4:
				   cout<<"Ҫ���ҽ���id�ǣ�";
				   cin>>id;
				   LocateListId(L, id);
				   break;
			   case 5:
				   num=GetListNum(L);
				   cout<<num;
				   break;
			   case 6:
				   DisplayList(L);
				   break;
			   case 7:
				   return 0;
				   break;
			   default:
				 cout<<"������ĺ��벻��ȷ��"<<endl;
			}
		}else if(choose==2){//2������
             DisplayTu();
		   	 cout<<"����ѡ�";
	      	 cin>>choice;
			 switch(choice){
			   case 1:
				   CreateUDG(G);
				   break;
			   case 2:
				   DepthTraverseGraph(G);
				   break;
			   case 3:
				   BFS(G);
				   break;
			   case 4:
				   return 0;
				   break;
			   default:
				   cout<<"������ĺ��벻��ȷ��"<<endl;
			}
		}else
			cout<<"������ĺ��벻��ȷ��"<<endl;
	}
	return 0;
}