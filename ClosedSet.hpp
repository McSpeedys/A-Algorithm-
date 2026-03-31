//Simple vector based closed set class.

//Including necessary libraries.
//Including concepts to use totally_ordered.
#include <concepts>
//Including vector and memory to use in tandem to ensure memory safety
//when we handle pointers in the set.
#include <vector>
#include <<memory>

//ClosedSet class declaration.
template<std::totally_ordered T>
class ClosedSet{
  private:
    std::vector<std::unique_ptr<T>> cset;
  public:
    //Constructor.
    ClosedSet();
    //Destructor.
    ~ClosedSet();
    //Methods.
    void add(T*);
    bool contains(T*);
};

//ClosedSet class implementation.

//Constructor.
//Doesn't do anything since we declare the vector in the class.
template<std::totally_ordered T>
ClosedSet<T>::ClosedSet(){}

//Destructor
template<std::totally_ordered T>
ClosedSet<T>::~ClosedSet(){
  //First clear the vector and then free its memory.
  this->cset.clear();
  this->cset.shrink_to_fit();
}

template<std::totally_ordered T>
void ClosedSet<T>::add(T* data){
  this->cset.push_back(data);
}

template<std::totally_ordered T>
bool ClosedSet<T>::contains(T* data){
  //Initiate an iterater and search through the vector for the data.
  std::vector<T*>::iterator search = std::find(
      this->cset.begin(), this->cset.end(), data
  );
  
  //Check if it was found or not.
  return search != this->cset.end();
}
