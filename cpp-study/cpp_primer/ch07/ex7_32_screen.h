#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	Window_mgr();
	void clear(ScreenIndex);

private:
	std::vector<Screen> screens;

};

class Screen {
public:
	friend void Window_mgr::clear(ScreenIndex);
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
	char get() const { return contents[cursor]; }
	char get(pos, pos) const;
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	void do_display(std::ostream &os) const {os << contents;}
};

inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
	contents[r*width + col] = ch;
	return *this;
}

inline char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

Window_mgr::Window_mgr() : screens{Screen(24, 80, ' ')} { }

void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}
