#ifndef Builder_h
#define Builder_h

class Builder
{
public:
	virtual ~Builder() = 0;

	Pixel* getPixel() { return pixel; }
	void createPixel() { pixel = new Pixel(); }

	virtual void BuildX(int x) = 0;
	virtual void BuildY(int y) = 0;
	virtual void BuildColor() = 0;
protected:
	Builder() = default;
	Pixel* pixel;
};
Builder::~Builder() = default;

class BlackBuilder : public Builder
{
public:
	void BuildX(int x) { pixel->setX(x); }
	void BuildY(int y) { pixel->setY(y); }
	void BuildColor() { pixel->setColor(0); }
};

class WhiteBuilder : public Builder
{
public:
	void BuildX(int x) { pixel->setX(x); }
	void BuildY(int y) { pixel->setY(y); }
	void BuildColor() { pixel->setColor(255); }
};

#endif