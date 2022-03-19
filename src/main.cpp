#include "main.h"

pros::Controller master(CONTROLLER_MASTER);
pros::Motor br(1);
pros::Motor fr(2);
pros::Motor bl(10);
pros::Motor fl(9);


class vector
{
	public:
		int x;
		int y;
		int r;
};

class remote
{
public:
	bool buttonA = master.get_digital(pros::E_CONTROLLER_DIGITAL_A);
};

remote Remote;
vector Vector;

void disabled()
{
	pros::lcd::set_text(1, "disabled...");
}

void competition_initialize()
{
	pros::lcd::set_text(1, "competition init");
}

void autonomous()
{
	pros::lcd::set_text(1, "autonomous");
}

void opcontrol()
{
	br.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	br.set_reversed(true);
	fr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	fr.set_reversed(true);
	bl.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	fl.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	while (true)
	{
		Vector.x = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
		Vector.y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		Vector.r = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		// ========= Math =========
		fl.move(Vector.y + Vector.x + Vector.r);
		fr.move(Vector.y - Vector.x - Vector.r);
		bl.move(Vector.y - Vector.x + Vector.r);
		br.move(Vector.y + Vector.x - Vector.r);

	}
}
