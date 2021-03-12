using System;
using System.ComponentModel.Design;
using System.Security.Cryptography;

namespace SuperRobotVSSpaceWizard
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to the battle for the fate of the galaxy!");
            Console.WriteLine("The Space Wizard Galmaxus seeks the power of the Everstone to remake the cosmos!");
            Console.WriteLine("Dynatron, defender of the Galactic Alliance, wishes to prevent the apocalyptic power of the Everstone from ever being used again!");
            Console.WriteLine("The two forces must now clash for the supreme power in the Alpha Quadrant!");
        }
    }

    class GameStructure
    {
        static int RandomRoll()
        {
            Random Gener = new Random();
            return Gener.Next(1, 100);
        }

        public void Help()
        { }
    }

    class Character: GameStructure
    {
        public string Name;
        private int Health;

        public void SetHealth(int NewValue)
        {
            if(NewValue < 0)
            {
                Health = 0;
                Console.WriteLine("Character has Expired...");
            }
            else
            {
                Health = NewValue;
            }
        }

        public int GetHealth()
        {
            return Health;
        }

        public void Talk(string name, string stuffToSay)
        {
            Console.WriteLine("I am " + name + ". " + stuffToSay);
        }

        public void Talk(string stuffToSay)
        {
            Console.WriteLine("I am " + Name + ". " + stuffToSay);
        }

        public int Attack()
        {
            return 10;
        }
    }

    class Wizard: Character
    {
        Wizard()
        {
            Name = "Galmaxus";
        }
        public void CastSpell()
        {
            Console.WriteLine("I cast Gamma Burst!");
        }

        new public int Attack()
        {
            return 25;
        }

        new public void Help()
        {
            Console.WriteLine("Wizards are powerful! They can Cast Spells!");
        }
    }

    class Robot: Character
    {
        Robot()
        {
            Name = "Dynatron";
        }
        public void RocketFist()
        {
            Console.WriteLine("Go, Rocket Powered Fist!");
        }

        new public int Attack()
        {
            return 25;
        }

        new public void Help()
        {
            Console.WriteLine("Robots can do anything they're designed for! Fire off a Rocket Fist!");
        }
    }
}
