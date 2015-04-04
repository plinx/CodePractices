#ifndef _SCREEN_H
#define _SCREEN_H

#include <string>
using std::string;

class Screen {
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos wd, pos ht) : width(wd), height(ht) {}
	Screen(pos wd, pos ht, char c) : width(wd), height(ht), contents(wd * ht, c) {}

	char get() const { return contents[cursor]; }
	char get(pos, pos) const;
	Screen &move(pos, pos);

private:
	pos cursor = 0;
	pos width = 0, height = 0;
	string contents;
};

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

#endif // !_SCREEN_H
