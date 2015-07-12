#ifndef State_h
#define State_h

class Machine
{
	friend class State;
public:
	Machine() = default;
	Machine(State* s) : _state(s) {}
	void ChangeState(State* s) { _state = s; }
	void Operation();
	void test() { std::cout << "Machine running test ..." << std::endl; }
private:
	State* _state;
};

class State
{
public:
	virtual void Operation(Machine* m) = 0;
	virtual void test() {}
};

class State1 : public State
{
public:
	void Operation(Machine* m);
	void test() { std::cout << "state1 test" << std::endl; }
};

class State2 :public State
{
public:
	void Operation(Machine* m);
	void test() { std::cout << "state2 test" << std::endl; }
};

void Machine::Operation()
{
	this->_state->Operation(this);
}

void State1::Operation(Machine* m)
{
	m->test();
	std::cout << "State1 Operation ..." << std::endl;
	std::cout << "Change to State2 ..." << std::endl;
	m->ChangeState(new State2());
}

void State2::Operation(Machine* m)
{
	m->test();
	std::cout << "State2 Operation ..." << std::endl;
	std::cout << "Change to State1 ..." << std::endl;
	m->ChangeState(new State1());
}

#endif