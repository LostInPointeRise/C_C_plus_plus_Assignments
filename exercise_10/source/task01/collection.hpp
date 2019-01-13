  
 
#ifndef COLLECTION_HPP
#define COLLECTION_HPP
 

template<class T> 

class Collection{

    public:

        virtual void add(T value) = 0; 

        virtual T remove() = 0; 

        virtual bool isEmpty() = 0; 

        virtual bool contains(T obj) = 0; 

        virtual void clear() = 0; 

        virtual int getSize() = 0; 

};
#endif  // end of class Collection
 