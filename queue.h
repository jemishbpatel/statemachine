#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  QUEUE_SIZE 10000
struct eventInfo
{
	int  eventNumber;
};

class Queue
{
public:
	Queue();
	~Queue();

	int enqueue( eventInfo & info );
	int dequeue( eventInfo & info );
	bool isFull( );
	bool isEmpty( );
	eventInfo & front();
private:
	eventInfo data[ QUEUE_SIZE ];
	int  head;
	int  tail;
};

Queue::Queue()
{
	head = 0;
	tail = 0;
}

Queue::~Queue()
{
}

bool Queue::isEmpty()
{
	return ( head == tail ) ? true : false;
}
bool Queue::isFull()
{
	return ( QUEUE_SIZE == tail ) ? true : false;
}

int Queue::enqueue( eventInfo & info )
{
	int ret = 0;
	if ( !isFull() ) {
		data[ tail ].eventNumber = info.eventNumber;
		tail++;
	} else {
		return -1;
	}
	return ret;
}

int Queue::dequeue( eventInfo & info)
{
	int ret = 0;
	if ( !isEmpty() ){
		info.eventNumber = data[ head ].eventNumber;
		head++;
	} else {
		return -1;
	}
	return ret;
}
