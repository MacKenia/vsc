#ifndef TREE_H
#define TREE_H

template <typename T>
class Tree
{
private:
    T *p, *q;
public:
    T DestoryTree(T *t);
    T CreateTree(T *t);
    T ClearTree(T *t);
    bool TreeEmpty(T *t);
    int TreeDepth(T *t);
    T* Root(T *t);
    T* Value(T *t);
    T* Assign(T *t, )
    
};

#endif