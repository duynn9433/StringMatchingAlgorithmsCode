//
// Created by nndng on 3/30/2022.
//

#ifndef STRINGMATCHINGALGORITHMS_GRAPH_H
#define STRINGMATCHINGALGORITHMS_GRAPH_H
struct _cell{
    int element;
    struct _cell *next;
};
typedef struct _cell *List;

struct _graph {
    int vertexNumber,
            edgeNumber,
            vertexCounter,
            initial,
            *terminal,
            *target,
            *suffixLink,
            *length,
            *position,
            *shift;
};

void error(const char *string);

typedef struct _graph *Graph;
typedef int boolean;

#define UNDEFINED -1

Graph newGraph(int v, int e);
Graph newAutomaton(int v, int e);
Graph newSuffixAutomaton(int v, int e);
int newVertex(Graph g);
int getInitial(Graph g);
boolean isTerminal(Graph g, int v);
void setTerminal(Graph g, int v);
int getTarget(Graph g, int v, unsigned char c);
void setTarget(Graph g, int v, unsigned char c, int t);
int getSuffixLink(Graph g, int v);
void setSuffixLink(Graph g, int v, int s);
int getLength(Graph g, int v);
void setLength(Graph g, int v, int ell);
int getPosition(Graph g, int v);
void setPosition(Graph g, int v, int p);
int getShift(Graph g, int v, unsigned char c);
void setShift(Graph g, int v, unsigned char c, int s);
void copyVertex(Graph g, int target, int source);
#endif //STRINGMATCHINGALGORITHMS_GRAPH_H
