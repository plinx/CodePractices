#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
using std::vector;
using std::string;

class Screen;

class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	vector<Screen> screens;
};

class Screen {
	friend class Window_mgr;
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

void Window_mgr::clear(ScreenIndex index)
{
	Screen &s = screens[index];	
	s.contents = string(s.height * s.width, ' ');

	std::cout << "screens[" << index << "] :";
	s.display(std::cout);
	std::cout << std::endl;
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

#endif