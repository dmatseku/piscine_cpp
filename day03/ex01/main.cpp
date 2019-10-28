#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    FragTrap robot("Rusty Bot");
    ScavTrap scv("NonRusty Bot");
    std::cout << std::endl;

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
    std::cout << std::endl;
    scv.rangedAttack("enemy");
    scv.meleeAttack("enemy");
    scv.takeDamage(80);
    scv.beRepaired(150);
    scv.takeDamage(120);
    scv.challengeNewcomer();
    scv.challengeNewcomer();
    scv.challengeNewcomer();
    scv.challengeNewcomer();
    scv.challengeNewcomer();
    std::cout << std::endl;
    return (0);
}