//Dynamic Array based Open Set class implementation.

//Including necessary libraries.
#include <concepts>

//Open Set class declaration.
template<std::totally_ordered T>
class OpenSet{
  private:
    T** oset;
    int arrSize;
    int max;
  public:
    //Constructor.
    OpenSet();
    //Destructor.
    ~OpenSet();
    //Methods.
    void add(T*);
    T* removeLowestF();
};

//Open Set class implementation.

//Constructor.
template<std::totally_ordered T>
OpenSet<T>::OpenSet(){
  //Array size set initially to 100,
  //will be increased when needed.
  this->oset = new T*[100];
  this->arrSize = 0;
  this->max = 100;
}

//Destructor.
template<std::totally_ordered T>
OpenSet<T>::~OpenSet(){
  //This will only free up memory for the pointers 
  //and the array. Actual objects will need to be 
  //deleted elsewhere.
  delete[] this->oset;
}

template<std::totally_ordered T>
void OpenSet<T>::add(T* data){
  //If the array is full create a new one,
  //fill it with the data the old one has
  //and replace it with the new one.
  if(this->arrSize == this->max){
    T** newArr = new T*[this->max * 2];

    for(int i = 0; i < this->max; i++){
      newArr[i] = this->oset[i];
    }

    this->oset = newArr;
    this->max = this->max * 2;
  }

  //Putting the data in the available spot in the heap.
  this->oset[this->arrSize] = data;
  
  //Heapifying loop, using min-heap logic.
  int i = this->arrSize;
  while(true){
    //Check parent.
    if(data->getFVal() < this->oset[(i - 1) / 2].getFVal()){
      T* temp = this->oset[(i - 1) / 2];
      this->oset[(i - 1) / 2] = data;
      this->oset[i] = temp;
      i = (i - 1) / 2;
    }
    //If we are here the data is in the right spot.
    else{
      break;
    }
  }
  
  this->arrSize++;
}
