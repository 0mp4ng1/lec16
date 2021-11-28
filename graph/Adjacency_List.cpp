#include <stdio.h>
#include <string>
#include <queue>

// 철수 : 1, 영희 : 2, 동건 : 3, 준호 : 4, 재상 : 5, 승우 : 6
#define SIZE 6

struct Node{
    int id;
    Node* link;

    Node(int id_, Node* link_){
        id = id_;
        link = link_;
    }

    int getId(){
        return id;
    }

    void setId(int id_){
        id = id_;
        return;
    }

    Node* getLink(){
        return link;
    }

    void setLink(Node* link_){
        link = link_;
        return;
    }
};

std::string V[SIZE+1];
Node* graph[SIZE+1];

//////////AdjList//////////////
void reset(){
    for(int i=1;i<=SIZE;i++){
        graph[i] = NULL; 
    }
    return;
}

void getVertex(int idx){
    printf("%s ",V[idx].c_str());
    return;
}

void insertVertex(int idx, const char* name){
    V[idx] = std::string(name);
    return;
}

void insertEdge(int i, int j){
    graph[i] = new Node(j, graph[i]);
    return;
}

Node* linkedVertex(int i){
    return graph[i];
}

 void display(){
        for(int i=1; i<=SIZE; i++){
            getVertex(i);
            printf(": ");
            Node* node = graph[i];
            while(node != NULL){
                getVertex(node->getId());
                node = node->getLink();
            }
            printf("\n");
        }
        printf("\n");
    }


bool visited[SIZE];

void resetVisited(){
    for(int i=1;i<=SIZE;i++){
        visited[i] = false;
    }
    return;
}

//////////DFS//////////////
void aDFS(int i){
    visited[i] = true;
    getVertex(i);

    for(Node *p = graph[i]; p!=NULL; p = p->getLink()){
        if(!visited[p->getId()])
            aDFS(p->getId());
    }
    return;
}

void DFS(){
    printf("////////////DFS////////////\n");
    
    resetVisited();

    for(int i=1;i<=SIZE;i++){
        if(!visited[i]) aDFS(i);
    }

    printf("\n\n");
    return;

}

//////////BFS//////////////
void BFS(int i){
    printf("////////////BFS////////////\n");
    resetVisited();

    visited[i] = true;
    getVertex(i);


    std::queue<int> queue;
    queue.push(i);

    while(!queue.empty()){
        i = queue.front();
        queue.pop();

        for(Node *p = graph[i]; p!=NULL; p = p->getLink()){
            int pId = p->getId();
            if(!visited[pId]){
                getVertex(pId);
                visited[pId] = true;
                queue.push(pId);
            }
        }
    }
    printf("\n");
    return;
}

int main(){
    
    reset();

    insertVertex(1, "철수");
    insertVertex(2, "영희");
    insertVertex(3, "동건");
    insertVertex(4, "준호");
    insertVertex(5, "재상");
    insertVertex(6, "승우");


    insertEdge(1,2);
    insertEdge(1,3);
    insertEdge(1,4);
    insertEdge(1,6);

    insertEdge(2,1);
    insertEdge(2,3);

    insertEdge(3,2);
    insertEdge(3,5);

    insertEdge(4,1);
    insertEdge(4,6);

    insertEdge(5,6);
    insertEdge(6,5);

    display();

    DFS();
    BFS(1);

    return 0;
}



