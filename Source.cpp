#include "Circle.h"
#include <iostream>
#include <string>
#include <sstream>

void interface_options();

int main()
{
	interface_options();
	
	std::string input;

	bool first_circle_has_params = 0, second_circle_has_params = 0;
	Circle Circle_1, Circle_2;

	do
	{
		//if (std::cin.peek() == '\n' || std::cin.peek() == '\0')
		//{
		//	std::cin.ignore();
		//}

		std::getline(std::cin, input);
		std::cin.clear();

		if (input == "1")
		{
			double x_temp, y_temp, r_temp;

			std::cout << "Input x coordinate of the first circle: ";
			std::cin >> x_temp;
			std::cout << "\nInput y coordinate of the first circle: ";
			std::cin >> y_temp;
			std::cout << "\nInput radius of the first circle: ";
			std::cin >> r_temp;
			std::cout << "\n\n";

			Circle_1.CircleSet(x_temp, y_temp, r_temp);

			first_circle_has_params = 1;
		}
		else if (input == "2")
		{
			double x_temp, y_temp, r_temp;

			std::cout << "Input x coordinate of the second circle: ";
			std::cin >> x_temp;
			std::cout << "\nInput y coordinate of the second circle: ";
			std::cin >> y_temp;
			std::cout << "\nInput radius of the second circle: ";
			std::cin >> r_temp;
			std::cout << "\n\n";

			Circle_2.CircleSet(x_temp, y_temp, r_temp);

			second_circle_has_params = 2;
		}
		else if (input == "3")
		{
			if (first_circle_has_params && second_circle_has_params)
			{
				if (Circle_1.CircleIntersect(Circle_2))
				{
					std::cout << "Circles intersect";
				}
				else
				{
					std::cout << "Circles do not intersect";
				}
			}
			else
			{
				std::cout << "Please input both circles before";
			}

			std::cout << "\n\n";
		}
		else if (input == "4")
		{
			if (first_circle_has_params && second_circle_has_params)
			{
				std::cout << "Distance between circles equals to: " << Circle_1.CircleDistance(Circle_2) << "\n\n";
			}
			else
			{
				std::cout << "Please input both circles before\n\n";
			}
		}
		else if (input == "5")
		{
			std::string temp_str;

			std::cout << "Length of which circle do you want to calculate: ";
			std::cin >> temp_str;

			if (temp_str == "1" && first_circle_has_params)
			{
				std::cout << "Length of circle 1 equals to: " << Circle_1.CircleLen() << "\n";
			}
			else if (temp_str == "2" && second_circle_has_params)
			{
				std::cout << "Length of circle 2 equals to: " << Circle_2.CircleLen() << "\n";
			}
			else if (temp_str != "1" && temp_str != "2")
			{
				std::cout << "Please choose the first or the second circle\n";
			}
			else if (temp_str == "1" && !first_circle_has_params)
			{
				std::cout << "Please enter the parameters of the circle first\n";
			}
			else if (temp_str == "2" && !second_circle_has_params)
			{
				std::cout << "Please enter the parameters of the circle first\n";
			}
		}
		else if (input == "6")
		{
			std::string temp_str;

			std::cout << "Area of which circle do you want to calculate: ";
			std::cin >> temp_str;

			if (temp_str == "1" && first_circle_has_params)
			{
				std::cout << "Area of circle 1 equals to: " << Circle_1.CircleArea() << "\n";
			}
			else if (temp_str == "2" && second_circle_has_params)
			{
				std::cout << "Area of circle 2 equals to: " << Circle_2.CircleArea() << "\n";
			}
			else if (temp_str != "1" && temp_str != "2")
			{
				std::cout << "Area choose the first or the second circle\n";
			}
			else if (temp_str == "1" && !first_circle_has_params)
			{
				std::cout << "Please enter the parameters of the circle first\n";
			}
			else if (temp_str == "2" && !second_circle_has_params)
			{
				std::cout << "Please enter the parameters of the circle first\n";
			}
		}
		else if (input == "7")
		{
			double x_temp, y_temp;
			int option_temp;

			std::cout << "Which circle do you want to use as a reference? ";
			std::cin >> option_temp;

			if (option_temp == 1 && first_circle_has_params)
			{
				std::cout << "Input x coordinate of the point: ";
				std::cin >> x_temp;
				std::cout << "\nInput y coordinate of the point: ";
				std::cin >> y_temp;

				if (Circle_1.InCircle(x_temp, y_temp))
				{
					std::cout << "The point lies whithin the circle\n";
				}
				else
				{
					std::cout << "The point does not lie whithin the circle\n";
				}
			}
			else if (option_temp == 2 && second_circle_has_params)
			{
				std::cout << "Input x coordinate of the point: ";
				std::cin >> x_temp;
				std::cout << "\nInput y coordinate of the point: ";
				std::cin >> y_temp;

				if (Circle_2.InCircle(x_temp, y_temp))
				{
					std::cout << "The point lies whithin the circle\n";
				}
				else
				{
					std::cout << "The point does not lie whithin the circle\n";
				}
			}
			else if ((option_temp == 1 && !first_circle_has_params) || (option_temp == 2 && !second_circle_has_params))
			{
				std::cout << "\nPlease enter the parameters of the circle first\n";
			}
			else
			{
				std::cout << "\nError. Incorrect input\n";
			}
		}
		else if (input == "8")
		{
			break;
		}
		//else
		//{
		//	std::cout << "\nInput error.\n";
		//}

	} while (input != "8");
}

void interface_options()
{
	std::cout << "Choose an option:\n";
	std::cout << "1. Input parameters of the first circle\n";
	std::cout << "2. Input parameters of the second circle\n";
	std::cout << "3. Check if circles intersect\n";
	std::cout << "4. Calculate distance between circles\n";
	std::cout << "5. Calculate length of one of the circles\n";
	std::cout << "6. Calculate area of one of the circles\n";
	std::cout << "7. Check if a point lies within a circle\n";
	std::cout << "8. Exit\n";
}