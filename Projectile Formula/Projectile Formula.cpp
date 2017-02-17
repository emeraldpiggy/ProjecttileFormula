#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void CalculateDistanceAndHeight();
void CalculateVelocityAndTime();
const double PI = 3.141592654, g = 9.8;

int main()
{

	CalculateVelocityAndTime();

	system("pause");
	return 0;
}


void CalculateDistanceAndHeight()
{
	double launch_angle, Vo, Vx, Vy, time, x, y, y_max;

	do
	{

		cout << "Enter intial Velocity: \n";
		cin >> Vo;

	} while ((Vo < 0) || (Vo > 100));

	do
	{
		cout << "Enter Launch Angle: \n";
		cin >> launch_angle;
	} while ((launch_angle < 1) || (launch_angle > 89));

	Vx = Vo * cos(launch_angle*PI / 180);
	Vy = Vo * sin(launch_angle*PI / 180);

	cout << "Vx = " << Vx << endl;
	cout << "Vy = " << Vy << endl;

	do
	{
		cout << "Enter the time: \n";
		cin >> time;
	} while (time < 0);

	y_max = (Vo * sin(launch_angle*PI / 180)*Vo * sin(launch_angle*PI / 180)) / 2 * g;
	cout << "Y max = " << y_max << endl;

	x = Vo * cos(launch_angle*PI / 180) * time;
	y = (1 / 2) * g *time*time + Vo * sin(launch_angle*PI / 180) * time;

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

void CalculateVelocityAndTime()
{
	double launch_angle, Vo, x, y, time, Verify;

	cout << "Enter Height: \n";
	x = 10;

	do
	{
		cout << "Enter Distance: \n";
		y = 100;

	} while ((y < 0));

	do
	{
		cout << "Enter Launch Angle: \n";
		launch_angle = 30;
	} while ((launch_angle < 1) || (launch_angle > 89));


	auto sinA = sin(launch_angle*PI / 180);
	auto cosA = cos(launch_angle*PI / 180);

	auto tempa = ((sinA*y / cosA) - x);
	time = sqrt(2 *tempa/ g);

	Vo = y / (cosA* time);

	Verify = (x + 0.5 * g *time*time) / (sinA * time);


	cout << "Verify Velocity = " << Verify << endl;

	cout << "Final Velocity = " << Vo << endl;

	cout << "Time = " << time << endl;
}