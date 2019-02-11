#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <thread>

class Sonar {
public:
	Sonar() {
		//Da Luong, do EXIT ham tinh nen khong tac dong den private duoc, nen phai them this
		std::thread subProcess(&Sonar::runningApp, this);

		while (true) {
			if (_getch() == 27) {
				//Goi Exit to bien Da luong
				Exit(&subProcess);
				return;
			}
		}
	}

	void runningApp() {
		const std::string Mess = "this app is running";
		while (!EXIT) {
			std::cout << Mess << std::endl;
			Sleep(500);
		}
	}

	void Exit(std::thread *subProcess) {
		system("cls");
		EXIT = true;
		subProcess->join();
	}

private:
	bool EXIT = false;
};

int main() {
	Sonar sonar;
}