#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>




template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */


  Heap(int m=2, PComparator c = PComparator()) : mAryVal(m), comparator(c) 
	{
	}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){
		
	}

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item){
		heapVector.push_back(item);

		// heapifyUP here

		this->heapifyUp(heapVector.size() - 1);
	}

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const{
		return heapVector.empty();
	}

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const{
		return heapVector.size();
	}

private:
  /// Add whatever helper functions and data members you need below

std::vector<T> heapVector;
int mAryVal;
PComparator comparator;
void heapifyUp(int index);
void heapifyDown(int index);



};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Error. Heap is empty.");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

	return heapVector.front();

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
			
			throw std::underflow_error("Error. Heap is empty.");


  }

	heapVector[0] = heapVector.back();
	heapVector.pop_back();

	//heapify down here

if(!heapVector.empty()){
	this->heapifyDown(0);

}

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(int index){

	if(index <= 0){
		return;
	}
	int parentIndex = (index-1)/mAryVal;

	if(comparator(heapVector[index], heapVector[parentIndex])){
		std::swap(heapVector[index], heapVector[parentIndex]);

		index = parentIndex;
		this->heapifyUp(index);
	}

return;


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(int index){



	int leftIndex = mAryVal*index+1;

	if(leftIndex >= heapVector.size()){
		return;
	}

	if(leftIndex < 0 || leftIndex >= heapVector.size()){
		return;
	}

	int bestIndex = leftIndex;

for(int x = 1; x < mAryVal; x++){

	int child = leftIndex + x;
	if (child >= heapVector.size()){
		break;
	}

	if(comparator(heapVector[child], heapVector[bestIndex])){
		bestIndex = child;	
	}
}


	if(comparator(heapVector[bestIndex], heapVector[index])){
		std::swap(heapVector[index], heapVector[bestIndex]);
		heapifyDown(bestIndex);
	}

	return;
}



#endif

