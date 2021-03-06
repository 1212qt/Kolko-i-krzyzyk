// GraKK.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string.h>

void HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

bool IsConsoleVisible()
{
	return (::IsWindowVisible(::GetConsoleWindow()) != FALSE);
}

#define VIDEO_SIZE 800



int main()
{	
	HideConsole();
	sf::RenderWindow window(sf::VideoMode(VIDEO_SIZE, VIDEO_SIZE), "Kolko Krzyzyk");

	bool isChecked[3][3];
	memset(isChecked, 0, sizeof(isChecked));
	int moves[3][3];
	memset(moves, 0, sizeof(moves));
	bool move[3][3];
	memset(move, 0, sizeof(move));
	bool state = 0;
	int winner = 0;
	int mvCNT = 0;
	bool starting = 0;

	sf::Texture circleTexture;
	sf::Texture crossTexture;
	circleTexture.loadFromFile("circle.png");
	crossTexture.loadFromFile("cross.png");

	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text inscription("Teraz ruch:", font, 30);
	inscription.setPosition(220 ,30);
	inscription.setFillColor(sf::Color::Black);
	sf::Text winInscription("Wygral:", font, 30);
	winInscription.setPosition(240, 30);
	winInscription.setFillColor(sf::Color::Black);
	sf::Text resetInscription("Reset", font, 20);
	resetInscription.setPosition(28, 27);
	resetInscription.setFillColor(sf::Color::Red);
	sf::Text startingInscription("Zaczyna:", font, 20);
	startingInscription.setFillColor(sf::Color::Black);
	startingInscription.setPosition(600, 30);

	sf::RectangleShape round(sf::Vector2f(50,50));
	round.setPosition(VIDEO_SIZE / 2 - 25, 25);
	sf::RectangleShape resetButton(sf::Vector2f(60, 30));
	resetButton.setPosition(25, 25);
	resetButton.setFillColor(sf::Color::Cyan);
	sf::RectangleShape startingCircle(sf::Vector2f(30, 30));
	startingCircle.setFillColor(sf::Color::Red);
	startingCircle.setPosition(685, 30);
	startingCircle.setTexture(&circleTexture);
	sf::RectangleShape startingCross(sf::Vector2f(30, 30));
	startingCross.setPosition(715, 30);
	startingCross.setTexture(&crossTexture);
		
	sf::RectangleShape leftHorizontBorder(sf::Vector2f(4 ,VIDEO_SIZE - 200));
	leftHorizontBorder.setFillColor(sf::Color::Black);
	leftHorizontBorder.setPosition((VIDEO_SIZE - 200) / 3 + 98, 100);

	sf::RectangleShape rightHorizontBorder(sf::Vector2f(4, VIDEO_SIZE - 200));
	rightHorizontBorder.setFillColor(sf::Color::Black);
	rightHorizontBorder.setPosition(2*(VIDEO_SIZE - 200) / 3 + 98, 100);

	sf::RectangleShape upperVerticalBorder(sf::Vector2f(VIDEO_SIZE - 200, 4));
	upperVerticalBorder.setFillColor(sf::Color::Black);
	upperVerticalBorder.setPosition(100, (VIDEO_SIZE - 200) / 3 + 98);

	sf::RectangleShape lowerVerticalBorder(sf::Vector2f(VIDEO_SIZE - 200, 4));
	lowerVerticalBorder.setFillColor(sf::Color::Black);
	lowerVerticalBorder.setPosition(100, 2*( VIDEO_SIZE - 200) / 3 + 98);



	sf::RectangleShape leftUpperBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 2,
		(VIDEO_SIZE - 200) / 3 - 4));
	leftUpperBox.setPosition(100, 100);

	sf::RectangleShape centerUpperBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 4,
		(VIDEO_SIZE - 200) / 3 - 4));
	centerUpperBox.setPosition(302,100);
	
	sf::RectangleShape rightUpperBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 2,
		(VIDEO_SIZE - 200) / 3 - 4));
	rightUpperBox.setPosition(502, 100);

	sf::RectangleShape leftMiddleBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 2,
		(VIDEO_SIZE - 200) / 3 - 4));
	leftMiddleBox.setPosition(100, 302);
	
	sf::RectangleShape centerMiddleBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 4,
		(VIDEO_SIZE - 200) / 3 - 4));
	centerMiddleBox.setPosition(302, 302);
	
	sf::RectangleShape rightMiddleBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 2,
		(VIDEO_SIZE - 200) / 3 - 4));
	rightMiddleBox.setPosition(502, 302);
		
	sf::RectangleShape leftLowerBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 2,
		(VIDEO_SIZE - 200) / 3 - 4));
	leftLowerBox.setPosition(100, 502);
	

	sf::RectangleShape centerLowerBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 4,
		(VIDEO_SIZE - 200) / 3 - 4));
	centerLowerBox.setPosition(302, 502);
	

	sf::RectangleShape rightLowerBox(sf::Vector2f((VIDEO_SIZE - 200) / 3 - 2,
		(VIDEO_SIZE - 200) / 3 - 4));
	rightLowerBox.setPosition(502, 502);
	






	while (window.isOpen()) {
		sf::Event event;
		

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				startingCircle.getGlobalBounds().contains(
					sf::Vector2f(sf::Mouse::getPosition(window)))) {
				if (starting == 1 && mvCNT == 0) {
					starting = 0;
					startingCross.setFillColor(sf::Color::White);
					startingCircle.setFillColor(sf::Color::Red);
					state = starting;
				}
			}

			if (event.type == sf::Event::MouseButtonPressed &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				startingCross.getGlobalBounds().contains(
					sf::Vector2f(sf::Mouse::getPosition(window)))) {
				if (starting == 0 && mvCNT == 0) {
					starting = 1;
					startingCross.setFillColor(sf::Color::Red);
					startingCircle.setFillColor(sf::Color::White);
					state = starting;
				}
			}

			if (event.type == sf::Event::MouseButtonPressed &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				resetButton.getGlobalBounds().contains(
					sf::Vector2f(sf::Mouse::getPosition(window)))) {
				std::cout << "reset" << std::endl;

				memset(isChecked, 0, sizeof(isChecked));
				memset(moves, 0, sizeof(moves));
				memset(move, 0, sizeof(move));
				state = starting;
				winner = 0;
				mvCNT = 0;


				inscription.setString("Teraz ruch:");
				leftUpperBox.setTexture(NULL);
				centerUpperBox.setTexture(NULL);
				rightUpperBox.setTexture(NULL);
				leftMiddleBox.setTexture(NULL);
				centerMiddleBox.setTexture(NULL);
				rightMiddleBox.setTexture(NULL);
				leftLowerBox.setTexture(NULL);
				centerLowerBox.setTexture(NULL);
				rightLowerBox.setTexture(NULL);

			}






			if (event.type == sf::Event::MouseButtonPressed &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left) && winner == 0) {

				



				if (leftUpperBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[0][0] == 0) {
					if (state) {
						leftUpperBox.setTexture(&crossTexture);
						state = 0;
						moves[0][0] = 1;
						memset(move, 0, sizeof(move));
						move[0][0] = 1;
						mvCNT++;
					}
					else {
						leftUpperBox.setTexture(&circleTexture);
						state = 1;
						moves[0][0] = 2;
						memset(move, 0, sizeof(move));
						move[0][0] = 1;
						mvCNT++;
					}
					isChecked[0][0] = 1;
				}
				
				if (centerUpperBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[0][1] == 0) {
					if (state) {
						centerUpperBox.setTexture(&crossTexture);
						state = 0;
						moves[0][1] = 1;
						memset(move, 0, sizeof(move));
						move[0][1] = 1;
						mvCNT++;
					}
					else {
						centerUpperBox.setTexture(&circleTexture);
						state = 1;
						moves[0][1] = 2;
						memset(move, 0, sizeof(move));
						move[0][1] = 1;
						mvCNT++;
					}
					isChecked[0][1] = 1;
				}

				if (rightUpperBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[0][2] == 0) {
					if (state) {
						rightUpperBox.setTexture(&crossTexture);
						state = 0;
						moves[0][2] = 1;
						memset(move, 0, sizeof(move));
						move[0][2] = 1;
						mvCNT++;
					}
					else {
						rightUpperBox.setTexture(&circleTexture);
						state = 1;
						moves[0][2] = 2;
						memset(move, 0, sizeof(move));
						move[0][2] = 1;
						mvCNT++;
					}
					isChecked[0][2] = 1;
				}
			
				if (leftMiddleBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[1][0] == 0) {
					if (state) {
						leftMiddleBox.setTexture(&crossTexture);
						state = 0;
						moves[1][0] = 1;
						memset(move, 0, sizeof(move));
						move[1][0] = 1;
						mvCNT++;
					}
					else {
						leftMiddleBox.setTexture(&circleTexture);
						state = 1;
						moves[1][0] = 2;
						memset(move, 0, sizeof(move));
						move[1][0] = 1;
						mvCNT++;
					}
					isChecked[1][0] = 1;
				}
			
				if (centerMiddleBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[1][1] == 0) {
					if (state) {
						centerMiddleBox.setTexture(&crossTexture);
						state = 0;
						moves[1][1] = 1;
						memset(move, 0, sizeof(move));
						move[1][1] = 1;
						mvCNT++;
					}
					else {
						centerMiddleBox.setTexture(&circleTexture);
						state = 1;
						moves[1][1] = 2;
						memset(move, 0, sizeof(move));
						move[1][1] = 1;
						mvCNT++;
					}
					isChecked[1][1] = 1;
				}
			
				if (rightMiddleBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[1][2] == 0) {
					if (state) {
						rightMiddleBox.setTexture(&crossTexture);
						state = 0;
						moves[1][2] = 1;
						memset(move, 0, sizeof(move));
						move[1][2] = 1;
						mvCNT++;
					}
					else {
						rightMiddleBox.setTexture(&circleTexture);
						state = 1;
						moves[1][2] = 2;
						memset(move, 0, sizeof(move));
						move[1][2] = 1;
						mvCNT++;
					}
					isChecked[1][2] = 1;
				}

				if (leftLowerBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[2][0] == 0) {
					if (state) {
						leftLowerBox.setTexture(&crossTexture);
						state = 0;
						moves[2][0] = 1;
						memset(move, 0, sizeof(move));
						move[2][0] = 1;
						mvCNT++;
					}
					else {
						leftLowerBox.setTexture(&circleTexture);
						state = 1;
						moves[2][0] = 2;
						memset(move, 0, sizeof(move));
						move[2][0] = 1;
						mvCNT++;
					}
					isChecked[2][0] = 1;
				}

				if (centerLowerBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[2][1] == 0) {
					if (state) {
						centerLowerBox.setTexture(&crossTexture);
						state = 0;
						moves[2][1] = 1;
						memset(move, 0, sizeof(move));
						move[2][1] = 1;
						mvCNT++;
					}
					else {
						centerLowerBox.setTexture(&circleTexture);
						state = 1;
						moves[2][1] = 2;
						memset(move, 0, sizeof(move));
						move[2][1] = 1;
						mvCNT++;
					}
					isChecked[2][1] = 1;
				}

				if (rightLowerBox.getGlobalBounds().contains(sf::Vector2f(
					sf::Mouse::getPosition(window))) && isChecked[2][2] == 0) {
					if (state) {
						rightLowerBox.setTexture(&crossTexture);
						state = 0;
						moves[2][2] = 1;
						memset(move, 0, sizeof(move));
						move[2][2] = 1;
						mvCNT++;
					}
					else {
						rightLowerBox.setTexture(&circleTexture);
						state = 1;
						moves[2][2] = 2;
						memset(move, 0, sizeof(move));
						move[2][2] = 1;
						mvCNT++;
					}
					isChecked[2][2] = 1;
				}
			}




		}



		
		for (int i = 0; i < 3; i++) {
			
			for (int j = 0; j < 3; j++) {
				int tmpPC = 0;
				int tmpPK = 0;
				int tmpVC = 0;
				int tmpVK = 0;
				int tmpSCL = 0;
				int tmpSCR = 0;
				int tmpSKL = 0;
				int tmpSKR = 0;
				if (move[i][j] == 1) {
					for (int k = 0; k < 3; k++) {
						if ((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 2 && j == 2)) {
							if (moves[k][k] == 1) {
								tmpSCL++;
							}
							if (moves[k][k] == 2) {
								tmpSKL++;
							}
						}
						if ((i == 0 && j == 2) || (i == 3 && j == 0) || (i == 1 && j == 1)){
							if (moves[2-k][k] == 1) {
								tmpSCR++;
							}
							if (moves[2-k][k] == 2) {
								tmpSKR++;
							}
						}
						if (moves[i][k] == 1) {
							tmpPC++;
						}
						if (moves[k][j] == 1) {
							tmpVC++;
						}
						if (moves[i][k] == 2) {
							tmpPK++;
						}
						if (moves[k][j] == 2) {
							tmpVK++;
						}
					}
					if (tmpPC == 3 || tmpVC == 3 || tmpSCL == 3 || tmpSCR == 3) {
						winner = 2;
					}
					if (tmpVK == 3 || tmpPK == 3 || tmpSKL == 3 || tmpSKR == 3) {
						winner = 1;
					}
				}
			}
		}
			
		if (state && mvCNT <9) {
			round.setTexture(&crossTexture);
		}
		else if (!state && mvCNT <9) {
			round.setTexture(&circleTexture);
		}
		else if (mvCNT == 9 && winner == 0) {
			round.setTexture(NULL);
			inscription.setString("Remis");
		}
		
		if (winner == 1) {
			round.setTexture(&circleTexture);
		}
		if (winner == 2) {
			round.setTexture(&crossTexture);
		}

		window.clear(sf::Color::White);
		
		window.draw(leftHorizontBorder);
		window.draw(rightHorizontBorder);
		window.draw(upperVerticalBorder);
		window.draw(lowerVerticalBorder);
		
		window.draw(startingInscription);
		window.draw(startingCircle);
		window.draw(startingCross);
		
		if (winner == 0) {
			window.draw(inscription);
		}
		else {
			window.draw(winInscription);
		}
		window.draw(resetButton);
		window.draw(resetInscription);
		window.draw(round);
		window.draw(leftUpperBox);
		window.draw(centerUpperBox);
		window.draw(rightUpperBox);
		window.draw(leftMiddleBox);
		window.draw(centerMiddleBox);
		window.draw(rightMiddleBox);
		window.draw(leftLowerBox);
		window.draw(centerLowerBox);
		window.draw(rightLowerBox);
		
		window.display();
	}


    return 0;
}

