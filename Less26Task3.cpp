#include <iostream>
#include <array>

class Display {

	private:
		int nDspLgt{ 80 }, nDspHgt{ 25 };

	public:

	std::array<int,2> getDspParam() {
		std::array<int,2> arrDspParam{ nDspLgt, nDspHgt};
		return arrDspParam;
	}

	void setDisplay() {
		std::cout << "Enter display lenght: ";
		std::cin >> nDspLgt;
		if (nDspLgt < 1) nDspLgt = { 1 };
		nDspLgt *= 2;
		std::cout << "Enter display haight: ";
		std::cin >> nDspHgt;
		if (nDspHgt < 1) nDspHgt = { 1 };
	}
	
	void getDisplay(class Window* window);
};

class Window {
private:
	int nWndX{ 0 }, nWndY{ 0 }, nWndLgt{ 0 }, nWndHgt{ 0 };
public:
	void setWindow(Display* display) {
		std::array<int,2> arrDspParam{ display->getDspParam() };
		int nDspLgt{ arrDspParam[0] };
		int nDspHgt{ arrDspParam[1] };

		std::cout << "Enter window X point: ";
		std::cin >> nWndX;
		if (nWndX < 0) nWndX = { 0 };
		if (nWndX > nDspLgt - 1) nWndX = { nDspLgt - 1 };
		std::cout << "Enter window Y point: ";
		std::cin >> nWndY;
		if (nWndY < 0) nWndY = { 0 };
		if (nWndY > nDspHgt - 1) nWndY = { nDspHgt - 1 };
		std::cout << "Enter window lenght: ";
		std::cin >> nWndLgt;
		if (nWndLgt < 1) nWndLgt = { 1 };
		nWndLgt *= 2;
		if ((nWndX + nWndLgt) > nDspLgt) nWndLgt = { nDspLgt - nWndX };
		std::cout << "Enter window haight: ";
		std::cin >> nWndHgt;
		if (nWndHgt < 1) nWndHgt = { 1 };
		if ((nWndY + nWndHgt) > nDspHgt) nWndHgt = { nDspHgt - nWndY };
	}
	void setMove(Display* display) {
		std::array<int, 2> arrDspParam{ display->getDspParam() };
		int nDspLgt{ arrDspParam[0] };
		int nDspHgt{ arrDspParam[1] };

		int nX{ 0 }, nY{ 0 };
		std::cout << "Enter vector X point: ";
		std::cin >> nX;
		nWndX += nX;
		if (nWndX < 0) nWndX = { 0 };
		if (nWndX > nDspLgt - 1) nWndX = { nDspLgt - 1 };

		std::cout << "Enter vector Y point: ";
		std::cin >> nY;
		nWndY += nY;
		if (nWndY < 0) nWndY = { 0 };
		if (nWndY > nDspHgt - 1) nWndY = { nDspHgt - 1 };

		std::cout << "New (X Y) window point (" << nWndX << " " << nWndY << ")\n";
	}
	void setResize(Display* display) {
		std::array<int, 2> arrDspParam{ display->getDspParam() };
		int nDspLgt{ arrDspParam[0] };
		int nDspHgt{ arrDspParam[1] };

		std::cout << "Enter window lenght: ";
		std::cin >> nWndLgt;
		if (nWndLgt < 1) nWndLgt = { 1 };
		nWndLgt *= 2;
		if ((nWndX + nWndLgt) > nDspLgt) nWndLgt = { nDspLgt - nWndX };

		std::cout << "Enter window haight: ";
		std::cin >> nWndHgt;
		if (nWndHgt < 1) nWndHgt = { 1 };
		if ((nWndY + nWndHgt) > nDspHgt) nWndHgt = { nDspHgt - nWndY };

		std::cout << "New size window (" << nWndLgt / 2 << " X " << nWndHgt << ")\n";
	}
	std::array <int,4> getWinParam() {
		std::array <int,4> arrWinParam {nWndX, nWndY, nWndLgt, nWndHgt };
		return arrWinParam;
	}
};

void Display::getDisplay(Window* window) {

	std::array <int,4> arrWinParam{ window->getWinParam()};
	int nWndX{ arrWinParam[0]};
	int nWndY{ arrWinParam[1]};
	int nWndLgt{ arrWinParam[2]};
	int nWndHgt{ arrWinParam[3]};

	std::cout << (char)0xC9;
	for (int i = 0; i <= nDspLgt; i++) {
		std::cout << (char)0xCD;
	}
	std::cout << (char)0xBB << std::endl;

	for (int i = 0; i <= nDspHgt; i++) {
		std::cout << (char)0xBA;
		for (int j = 0; j <= nDspLgt; j++) {
			if (nWndLgt != 0 && nWndHgt != 0 && i >= nWndY && i <= nWndY + nWndHgt
				&& j >= nWndX && j <= nWndX + nWndLgt) { // отрисовка окна					
				if (i == nWndY && j == nWndX) std::cout << (char)0xDA;
				if (i == nWndY && j > nWndX && j < nWndX + nWndLgt) std::cout << (char)0xC4;
				if (i == nWndY && j == nWndX + nWndLgt) std::cout << (char)0xBF;

				if (i > nWndY && i < nWndY + nWndHgt && j == nWndX) std::cout << (char)0xB3;
				if (i > nWndY && i < nWndY + nWndHgt && j > nWndX && j < nWndX + nWndLgt) std::cout << " ";
				if (i > nWndY && i < nWndY + nWndHgt && j == nWndX + nWndLgt) std::cout << (char)0xB3;

				if (i == nWndY + nWndHgt && j == nWndX) std::cout << (char)0xC0;
				if (i == nWndY + nWndHgt && j > nWndX && j < nWndX + nWndLgt) std::cout << (char)0xC4;
				if (i == nWndY + nWndHgt && j == nWndX + nWndLgt) std::cout << (char)0xD9;
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << (char)0xBA << std::endl;
	}

	std::cout << (char)0xC8;
	for (int i = 0; i <= Display::nDspLgt; i++) {
		std::cout << (char)0xCD;
	}
	std::cout << (char)0xBC << std::endl;
}


int main() {
	Display display1;
	Window window1;
	std::cout << "Enter display size\n";
	display1.setDisplay();
	window1.setWindow(&display1);
	std::string cCmd{ "" };

	while (cCmd != "close") {
		std::cout << "Enter command (move, resize, display, close): ";
		std::cin >> cCmd;
		if (cCmd == "move") window1.setMove(&display1);
		else if (cCmd == "resize") window1.setResize(&display1);
		else if (cCmd == "display") display1.getDisplay(&window1);
		else std::cout << "unknown command\n";
	}

	return 0;
}
