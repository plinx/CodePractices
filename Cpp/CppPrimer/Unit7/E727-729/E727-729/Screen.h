#ifndef _SCREEN_H
#define _SCREEN_H

#include <string>
using std::string;

class Screen {
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos wd, pos ht, char c) : width(wd), height(ht), contents(wd * ht, c) {}

	Screen &move(pos, pos);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &o) { do_display(o); return *this; }
	Screen const &display(std::ostream &o) const { do_display(o); return *this; }

private:
	void do_display(std::ostream &o) const { o << contents; }

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

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
	contents[r*width + c] = ch;
	return *this;
}

#endif // !_SCREEN_H
