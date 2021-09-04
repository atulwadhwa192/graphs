#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct Edge{
  int data;
  struct Edge* e;
  struct Connector* c;
}edge;
typedef struct Connector{
    int data;
    struct Connector* next;
}connect;
void traversal(edge* e1){
    if(e1==NULL){
        cout<<"Empty graph"<<endl;
    }
    else{
        while(e1!=NULL){
            cout<<e1->data<<"-> ";
            connect* c1=e1->c;
            if(c1==NULL){
                cout<<"EMPTY"<<endl;
            }
            else{
                while(c1->next!=NULL){
                    cout<<c1->data<<"-> ";
                    c1=c1->next;
                }
                cout<<c1->data;
            }
            cout<<endl;
            e1=e1->e;
        }
    }
}
edge* insert_edge(edge* head,int data){
    edge* node=(edge*)malloc(sizeof(edge));
    node->data=data;
    node->c=NULL;
    node->e=NULL;
    if(head==NULL){
        return node;
    }
    else{
        while(head->e!=NULL){
            head=head->e;
        }
        head->e=node;
        return head;
    }
}
void connect_edge(edge* head,int data,int connect_edge){
    while(head!=NULL && head->data!=data){
        head=head->e;
    }
    if(head==NULL){
        cout<<"Element not found/Invalid Entry"<<endl;
    }
    else{
        connect* c1=(connect*)malloc(sizeof(connect));
        c1->data=connect_edge;
        c1->next=NULL;
        if(head->c==NULL){
            head->c=c1;
        }
        else{
            connect* c2=head->c;
            while(c2->next!=NULL){
                c2=c2->next;
            }
            c2->next=c1;
        }
    }
}
int main()
{
    edge* e1=NULL;
    // connect* c1=(connect*)malloc(sizeof(connect));
    int n;
    // cout<<"Enter the number of edges"<<endl;
    // cin>>n;
    for(int i=0;i<4;i++){
        if(e1==NULL){
            e1=insert_edge(e1,i);
        }
        else{
            insert_edge(e1,i);
        }
    }
    connect_edge(e1,0,1);
    connect_edge(e1,0,2);
    connect_edge(e1,1,0);
    connect_edge(e1,1,3);
    connect_edge(e1,2,0);
    connect_edge(e1,3,1);
    connect_edge(e1,3,2);
    traversal(e1);
    // cout<<e1->c->data;
    return 0;
}
