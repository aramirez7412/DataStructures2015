/*******************************************************************************
 * Node (Class)
 * -----------------------------------------------------------------------------
 * This template is designed to be used as the data container for any data
 * structure
 *******************************************************************************/
#ifndef BINARYNODE_H_
#define BINARYNODE_H_

/**************************************************************************
 * 							[N O D E ~ C L A S S]
 **************************************************************************/
template <class typeName>
class binaryNode
{/**************************************************************************
 * P R I V A T E
 * ------------------------------------------------------------------------
 * The private section begins here
 **************************************************************************/
private:
    binaryNode<typeName>*    _left;
    binaryNode<typeName>*    _right;
    typeName _data;

/**************************************************************************
 * P U B L I C
 * ------------------------------------------------------------------------
 * The public section begins here
 **************************************************************************/
public:

/*******************
 * M U T A T O R S *
 *******************/
    /**********************************************************************
     * C O N S T R U C T O R
     * --------------------------------------------------------------------
     * This is the Default constructor for the Node template
     **********************************************************************/
    binaryNode();

    /**********************************************************************
     * D E S T R U C T O R
     * --------------------------------------------------------------------
     * This is the Default constructor for the Node template
     **********************************************************************/
    ~binaryNode();

    /**********************************************************************
     * SetData
     * --------------------------------------------------------------------
     * This template method is used to set the data within the node
     **********************************************************************/
    void SetData(typeName _newData);

    /**********************************************************************
     * SetPointer
     * --------------------------------------------------------------------
     * This template method is used to set pointer in node
     **********************************************************************/
    void SetPointer(typeName _newPointer);

    /***************************************************************************
     * SetNext
     * -------------------------------------------------------------------------
     * This template method will set the next pointer.
     ***************************************************************************/
    void SetRight(binaryNode* newRight);

    /***************************************************************************
     * SetPrevious
     * -------------------------------------------------------------------------
     * This method will set the previous.
     ***************************************************************************/
    void SetLeft(binaryNode* newLeft);

    /***************************************************************************
     * Orphan
     * -------------------------------------------------------------------------
     * This method will isolate a node to be taken off the list.
     ***************************************************************************/
    void Orphan();

    /***************************************************************************
     * GetRefData
     * -------------------------------------------------------------------------
     * This method is used to return the reference data and was created to be
     * used with the subscript operator.
     ***************************************************************************/
    typeName& GetRefData();
/*********************
 * A C C E S S O R S *
 *********************/
    /**********************************************************************
     * GetData
     * --------------------------------------------------------------------
     * This method will return the data in the node
     **********************************************************************/
    typeName GetData()            const;

    /***************************************************************************
     * GetPrevious
     * -------------------------------------------------------------------------
     * Returns the previous node
     ***************************************************************************/
    binaryNode<typeName>*& GetLeft();

    /***************************************************************************
     * GetNext()
     * -------------------------------------------------------------------------
     * This well return a pointer to the next element
     ***************************************************************************/
    binaryNode<typeName>*&  GetRight();

//    Node<typeName> & operator =(const Node<typeName> someNode);

};


//template<class typeName>
//Node<typeName> & Node<typeName>::operator =(const Node<typeName> someNode)
//{
//	Node<typeName> temp;
//
//	temp._data = someNode._data;
//}



template<class typeName>
typeName& binaryNode<typeName>::GetRefData()
{
	return _data;
}
/**************************************************************************
 * Node Constructor
 * ------------------------------------------------------------------------
 * Initializes _next
 **************************************************************************/
template <class typeName>
binaryNode<typeName>::binaryNode()
{
    _left     = NULL;
    _right    = NULL;
    _data     = typeName();
}

/**************************************************************************
 * D E S T R U C T O R
 * ------------------------------------------------------------------------
 * This is the Default constructor for the Node template
 **************************************************************************/
template <class typeName>//Have to get back to this guy
binaryNode<typeName>::~binaryNode()
{
    delete _right;
}

/**************************************************************************
 * Orphan
 * ------------------------------------------------------------------------
 * Sets All pointers to NULL so when it is deleted it is not associated with
 * any other nodes.
 **************************************************************************/
template <class typeName>
void binaryNode<typeName>::Orphan()
{
    _right 	  = NULL;
    _left     = NULL;
}

/**************************************************************************
 * GetNext
 * ------------------------------------------------------------------------
 * Returns the next pointer
 **************************************************************************/
template <class typeName>
binaryNode<typeName>*& binaryNode<typeName>::GetRight()
{
    return _right;
}


template <class typeName>
binaryNode<typeName>*& binaryNode<typeName>::GetLeft()
{
    return _left;
}
/**************************************************************************
 * SetNext
 * ------------------------------------------------------------------------
 * Sets the _next pointer
 **************************************************************************/
template <class typeName>
void binaryNode<typeName>::SetRight(binaryNode* newRight)
{
    _right = newRight;
}

template <class typeName>
void binaryNode<typeName>::SetLeft(binaryNode* newLeft)
{
    _left = newLeft;
}

/**************************************************************************
 * SetData
 * ------------------------------------------------------------------------
 * Sets the data for the Node object
 **************************************************************************/
template <class typeName>
void binaryNode<typeName>::SetData(typeName newData)
{
    _data = newData;
}

/**************************************************************************
 * SetPointer
 * ------------------------------------------------------------------------
 * Sets the _next pointer to a pointer argument
 **************************************************************************/
template <class typeName>
void binaryNode<typeName>::SetPointer(typeName newPointer)
{
    _right = newPointer;
}

/**************************************************************************
 * GetData
 * ------------------------------------------------------------------------
 * Returns the data of the node
 **************************************************************************/
template <class typeName>
typeName binaryNode<typeName>::GetData() const
{
    return _data;
}



#endif /* BINARYNODE_H_ */
