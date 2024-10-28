#include <iostream>

class Display {

	private:
		int nDspLgt{ 0 }, nDspHgt{ 0 }, nWndX{ 0 }, nWndY{ 0 }, nWndLgt{ 0 }, nWndHgt{ 0 };

	public:
	void setDisplay() {
		std::cout << "Enter display lenght: ";
		std::cin >> nDspLgt;
		if (nDspLgt < 1) nDspLgt = { 1 };
		nDspLgt *= 2;
		std::cout << "Enter display haight: ";
		std::cin >> nDspHgt;
		if (nDspHgt < 1) nDspHgt = { 1 };
	}
	
	void getDisplay() {
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
		for (int i = 0; i <= nDspLgt; i++) {
			std::cout << (char)0xCD;
		}
		std::cout << (char)0xBC << std::endl;

	}

	void setWindow() {
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
	void setMove() {
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
	void setResize() {
		std::cout << "Enter window lenght: ";
		std::cin >> nWndLgt;
		if (nWndLgt < 1) nWndLgt = { 1 };
		nWndLgt *= 2;
		if ((nWndX + nWndLgt) > nDspLgt) nWndLgt = { nDspLgt - nWndX };
		
		std::cout << "Enter window haight: ";
		std::cin >> nWndHgt;
		if (nWndHgt < 1) nWndHgt = { 1 };
		if ((nWndY + nWndHgt) > nDspHgt) nWndHgt = { nDspHgt - nWndY };

		std::cout << "New size window (" << nWndLgt/2 << " X " << nWndHgt << ")\n";
	}

};

int main() {
	Display* display1 = new Display;

	display1->setDisplay();
	display1->setWindow();

	std::string cCmd{ "" };

	while (cCmd != "close") {
		std::cout << "Enter command (move, resize, display, close): ";
		std::cin >> cCmd;
		if (cCmd == "move") display1->setMove();
		else if (cCmd == "resize")display1->setResize();
		else if (cCmd == "display") display1->getDisplay();
		else std::cout << "unknown command\n";
	}

	delete display1;
	display1 = { nullptr };
	return 0;
}
