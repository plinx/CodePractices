#ifndef Director_h
#define Director_h

class Director
{
public:
	Director() = default;
	~Director() = default;

	void setBuilder(Builder* pb) { builder = pb; }
	Pixel* getPixel() { return builder->getPixel(); }

	void constructPixel(int x, int y)
	{
		builder->createPixel();
		builder->BuildX(x);
		builder->BuildY(y);
		builder->BuildColor();
	}
private:
	Builder* builder;
};

#endif