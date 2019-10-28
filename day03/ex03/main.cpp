#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

int main()
{
    FragTrap robot("Rusty Bot");
    ScavTrap scv("NonRusty Bot");
    NinjaTrap ninja("NonRusty Bot");
    ClapTrap* ref = &robot;
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
    ninja.rangedAttack("enemy");
    ninja.meleeAttack("enemy");
    ninja.takeDamage(80);
    ninja.beRepaired(150);
    ninja.takeDamage(120);
    ninja.ninjaShoebox(scv);
    ninja.ninjaShoebox(robot);
    ninja.ninjaShoebox(ninja);
    ninja.ninjaShoebox(*ref);
    std::cout << std::endl;
    return (0);
}