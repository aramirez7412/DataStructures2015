/*******************************************************************************
 * This template header will define a priority queue
 *
 ******************************************************************************/
#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

template<class type>
class PriorityQueue
{
private:


public:

	/***************************************************************************
	 *                              getSize()
	 * _________________________________________________________________________
	 * Returns the size of the priority queue
	 *
	 *
	 *	Returns an integer value
	 *
	 *	Additional specifications. This is a const functions and does not modify
	 *  data
	 ***************************************************************************/
	int getSize() const;

	/***************************************************************************
	 *  							isEmpty()
     * _________________________________________________________________________
	 *
	 *  Returns a boolean value that will be true if the queue is empty
	 *
	 *
	 *  Returns a boolean value
	 *
	 * Additonal Specifications: This is a const function and does not modify
	 * 						     any data
	 ***************************************************************************/
	bool isEmpty() const;

	/***************************************************************************
	 * 					insert(const type & insertedData)
	 * _________________________________________________________________________
	 *
	 * This method will insert data into the priority queue in a position
	 * relative to the associated key
	 *
	 ***************************************************************************/
	void insert(const type & insertedData);


	/***************************************************************************
	 * 							  const type& min()
	 * _________________________________________________________________________
	 *
	 * returns the reference of the min value (node at the top of the priority
	 * queue)
	 **************************************************************************/
	const type& min(); //possibly throw an exception due to an
					   //empty list


	/***************************************************************************
	 * 							void removeMin()
	 * _________________________________________________________________________
	 *
	 * Will remove the top of the priority queue
	 ***************************************************************************/
	void removeMin(); //possible exception throw due to an empty
					  // Queue
};


//Get Size
template<class type>
int PriorityQueue<type>::getSize() const
{

}

//checks if the queue is empty
template<class type>
bool PriorityQueue<type>::isEmpty() const
{

}

//insert into the priority queue
template<class type>
void PriorityQueue<type>::insert(const type & insertedData)
{
	//WILL utilize the comparator functions/methods that are written
	//In this case there is a time and level of urgency associated with each
	//insertion


}

//Remove the minimum value from the queue
template<class type>
void PriorityQueue<type>::removeMin()
{

}
#endif /* PRIORITYQUEUE_H_ */
