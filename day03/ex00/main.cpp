#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap robot("Rusty Bot");

    std::srand(std::time(0));
    robot.rangedAttack("enemy");
    robot.meleeAttack("enemy");
    robot.takeDamage(80);
    robot.beRepaired(150);
    robot.takeDamage(120);
    robot.vaulthunter_dot_exe("enemy");
    robot.vaulthunter_dot_exe("enemy");
    robot.vaulthunter_dot_exe("enemy");
    robot.vaulthunter_dot_exe("enemy");
    robot.vaulthunter_dot_exe("enemy");
    return (0);
}