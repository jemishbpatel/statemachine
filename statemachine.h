 
class StateMachine
{
public:
	StateMachine( );
	~StateMachine( );

	 enum state {
		DISCONNECTED,
		CONNECTED,
		CAPTURING,
		ENCODING,
		MAX_STATE
	};
	enum event {
		CAMERA_CONNECTED,
		CAMERA_DISCONNECTED,
		START,
		STOP,
		MAX_EVENTS
	};
	typedef void ( *onEvent )( void * );
	struct transition {
		state		nextState;
		onEvent		action;	
	};
	static void startCapture( void * args );
	static void doNothing( void * args );
	static void startEncoding( void * args );
	static void stopCapture( void * args );
	static void stopEncoding( void * args );

	transition transitionTable[ MAX_STATE ][ MAX_EVENTS ];
	void initTransition( state currentState, event currentEvent, onEvent actionOnEvent, state nextState );
	void postEvent( int eventnumber );
private:
	state _currentState;	
};
