#ifndef FlyweightFactory_h
#define FlyweightFactory_h

class FlyweightFactory
{
public:
	FlyweightFactory() = default;
	~FlyweightFactory() = default;
	Flyweight* getFlyweight(const int key)
	{
		for (auto it = flyweight.begin(); it != flyweight.end(); it++)
		{
			if ((*it)->getState() == key)
			{
				std::cout << "State " << key << " already created by user." << std::endl;
				return *it;
			}
		}
		auto weight = new ConcreteFlyweight(key);
		flyweight.push_back(weight);
		return weight;
	}
private:
	std::vector<Flyweight*> flyweight;
};

#endif