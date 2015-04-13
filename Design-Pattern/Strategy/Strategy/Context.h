#ifndef Context_h
#define Context_h

class Context
{
public:
	Context(std::shared_ptr<Strategy>& s) : stg(s) {}
	~Context() = default;

	void DoAction() { stg->AlgInterface(); }
private:
	std::shared_ptr<Strategy> stg;
};

#endif
