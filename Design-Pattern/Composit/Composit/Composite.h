#ifndef Composite_h
#define Composite_h

class Composite : public Component
{
public:
	Composite() = default;
	void Operation()
	{
		for (auto it = vcom.begin(); it != vcom.end(); it++)
		{
			(*it)->Operation();
		}
	}
	void Add(Component* com) { vcom.push_back(com); }
	void Remove(Component* com) 
	{
		for (auto it = vcom.begin(); it != vcom.end(); it++)
		{
			if (*it == com)
			{
				it = vcom.erase(it, it + 1);
				std::cout << "erase component" << std::endl;
			}
		}
	}
	Component* getChild(int index) 
	{
		if ((size_t)index >= vcom.size())
			return new EmptyLeaf();
		return vcom[index]; 
	}
private:
	std::vector<Component*> vcom;
};

#endif