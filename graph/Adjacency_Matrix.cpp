#include <stdio.h>
#include <string>
#include <queue>

// 철수 : 1, 영희 : 2, 동건 : 3, 준호 : 4, 재상 : 5, 승우 : 6
#define SIZE 6

std::string V[SIZE+1];
int graph[SIZE+1][SIZE+1];


//////////AdjMat//////////////
void reset(){
    for(int i=1;i<=SIZE;i++){
        for(int j=1;j<=SIZE;j++){
            graph[i][j] = 0; 
        }
    }
    return;
}

void getVertex(int idx){
    printf("%s ",V[idx].c_str());
    return;
}

int getEdge(int i, int j){
    return graph[i][j];
}

void insertVertex(int idx, const char* name){
    V[idx] = std::string(name);
    return;
}

void setEdge(int i, int j){
    graph[i][j] = 1;
    return;
}

void insertEdge(int i, int j){
    setEdge(i,j);
    return;
}

 bool isLinked(int i, int j){
    return getEdge(i, j) != 0;
}

void display(){
        printf("    ");
        for(int i=0; i<SIZE; i++){
            getVertex(i);
        }
        printf("\n");

        for(int i=1; i<=SIZE; i++){
            getVertex(i);
            printf(": ");
            for(int j=0; j<SIZE; j++){
                printf("%d   ",getEdge(i, j));
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

    for(int j=1;j<=SIZE;j++){
        if(isLinked(i,j) && !visited[i])
            aDFS(j);
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

        for(int j=1;j<=SIZE;j++){
            if(isLinked(i,j) && !visited[j]){
                visited[j] = true;
                getVertex(j);
                queue.push(j);
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