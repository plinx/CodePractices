#ifndef Product_h
#define Product_h

// Product is Pixel
class Pixel
{
public:
	Pixel() = default;
	~Pixel() = default;

	void setX(int ix) { x = ix; }
	void setY(int iy) { y = iy; }
	void setColor(int icolor) { color = icolor; }
	void print()
	{
		std::cout << "Pixel : x = " << x << "; y = " << y << "; color = " << color << "." << std::endl;
	}
private:
	int x, y, color;
};

#endif