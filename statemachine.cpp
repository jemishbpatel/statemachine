#include <stdlib.h>
#include <stdio.h>
#include "statemachine.h"
StateMachine::StateMachine()
{
	initTransition( DISCONNECTED, CAMERA_CONNECTED,  &startCapture, CONNECTED );
	initTransition( DISCONNECTED, CAMERA_DISCONNECTED,  &doNothing, DISCONNECTED );
        initTransition( DISCONNECTED, START, &doNothing, DISCONNECTED );
        initTransition( DISCONNECTED, STOP, &doNothing, DISCONNECTED );
        initTransition( CONNECTED, CAMERA_DISCONNECTED, &stopCapture, DISCONNECTED );
	initTransition( CONNECTED, CAMERA_CONNECTED, &doNothing, CONNECTED);
        initTransition( CONNECTED, START, &startEncoding, ENCODING );
        initTransition( CONNECTED, STOP, &stopCapture, DISCONNECTED );
	initTransition( CAPTURING, CAMERA_CONNECTED, &doNothing, CAPTURING );
	initTransition( CAPTURING, CAMERA_DISCONNECTED, &stopCapture, DISCONNECTED );
	initTransition( CAPTURING, START, &startEncoding, ENCODING );
	initTransition( CAPTURING, STOP, &stopCapture, CONNECTED );
	initTransition( ENCODING, CAMERA_DISCONNECTED, &stopCapture, DISCONNECTED );
	initTransition( ENCODING, CAMERA_CONNECTED, &doNothing, ENCODING );
	initTransition( ENCODING, START, &doNothing, ENCODING );
	initTransition( ENCODING, STOP, &stopEncoding, CAPTURING );
	_currentState = DISCONNECTED;
}

StateMachine::~StateMachine()
{
}
void StateMachine::initTransition( state currentState, event currentEvent, onEvent actionOnEvent, state nextState )
{
	transitionTable[ currentState ][ currentEvent ].nextState = nextState;
	transitionTable[ currentState ][ currentEvent ].action = actionOnEvent;
}

void StateMachine::startCapture( void * args )
{
	int event = *(int*)args;
	switch( event )
	{
		case 0:
			printf("event :CAMERA_CONNECTED\n");
		break;
		case 1:
			printf("event: CAMERA_DISCONNECTED\n");
		break;
 		case 2:
			printf("event: START\n");
		break;
		case 3:
			printf("event: STOP\n");
		break;
		default:
			printf("event: Invalid Event");
		break;
	}
	printf("In function %s @line no %d and event number %d\n", __func__, __LINE__, event);
}

void StateMachine::doNothing( void * args )
{
	int event = *(int*)args;
	switch( event )
	{
		case 0:
			printf("event :CAMERA_CONNECTED\n");
		break;
		case 1:
			printf("event: CAMERA_DISCONNECTED\n");
		break;
 		case 2:
			printf("event: START\n");
		break;
		case 3:
			printf("event: STOP\n");
		break;
		default:
			printf("event: Invalid Event");
		break;
	}
	printf("In function %s @line no %d and event number %d\n", __func__, __LINE__, event);
}

void StateMachine::startEncoding( void * args )
{
	int event = *(int*)args;
	switch( event )
	{
		case 0:
			printf("event :CAMERA_CONNECTED\n");
		break;
		case 1:
			printf("event: CAMERA_DISCONNECTED\n");
		break;
 		case 2:
			printf("event: START\n");
		break;
		case 3:
			printf("event: STOP\n");
		break;
		default:
			printf("event: Invalid Event");
		break;
	}
	printf("In function %s @line no %d and event number %d\n", __func__, __LINE__, event );
}

void StateMachine::stopEncoding( void * args )
{
	int event = *(int*)args;
	switch( event )
	{
		case 0:
			printf("event :CAMERA_CONNECTED\n");
		break;
		case 1:
			printf("event: CAMERA_DISCONNECTED\n");
		break;
 		case 2:
			printf("event: START\n");
		break;
		case 3:
			printf("event: STOP\n");
		break;
		default:
			printf("event: Invalid Event");
		break;
	}
	printf("In function %s @line no %d and event number %d\n", __func__, __LINE__, event);
}

void StateMachine::stopCapture( void * args )
{
	int event = *(int*)args;
	switch( event )
	{
		case 0:
			printf("event :CAMERA_CONNECTED\n");
		break;
		case 1:
			printf("event: CAMERA_DISCONNECTED\n");
		break;
 		case 2:
			printf("event: START\n");
		break;
		case 3:
			printf("event: STOP\n");
		break;
		default:
			printf("event: Invalid Event");
		break;
	}
	printf("In function %s @line no %d and event number %d\n", __func__, __LINE__, event );
}

void StateMachine::postEvent( int eventNumber )
{
	if ( NULL != transitionTable[ _currentState ][ eventNumber ].action ) {
		transitionTable[ _currentState ][ eventNumber ].action( &eventNumber );
		_currentState = transitionTable[ _currentState ][ eventNumber ].nextState;
	}
}

int main( int argc , char * argv[] )
{
	int input;
	char choice;
	StateMachine stateMachine;
	do {
		scanf("%d", &input);
		getchar();
		stateMachine.postEvent( input );
		choice = getchar();
		getchar();
	} while( choice == 'y' );
	
	return 0;
}

