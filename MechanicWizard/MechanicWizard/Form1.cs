using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MechanicWizard
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        bicycle bike = new bicycle(); //Create bicycle object
        van car = new van(); //Create van object

        private void button1_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex.Equals(0)) //If the bike is selected
            {
                textBox2.Text = bike.check(); //Display the results of checking the bike
            }
            else if (listBox1.SelectedIndex.Equals(1)) //If the van is checked
            {
                textBox2.Text = car.check(); //DIsplay the results of checking the van
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex.Equals(0)) //If the bike is selected
            {
                bike.repair(); //Repair the bike
            } else if (listBox1.SelectedIndex.Equals(1)) //If the van is checked
            {
                car.repair(); //Repair the van
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex.Equals(0)) //If the bike is selected
            {
                textBox2.Text = bike.invoice(); //Display an invoice for any repairs to the bike
            }
            else if (listBox1.SelectedIndex.Equals(1)) //If the van is checked
            {
                textBox2.Text = car.invoice(); //Display an invoice for any repairs to the car
            }
        }
    }
    class vehicle
    {
        protected List<double> wheels = new List<double>(); //Create a list to hold wear-and-tear damage on the wheels
        protected int numWheels = 4; //There are four wheels by default
        Random rand = new Random(); //Create a random number generator
        protected float price = 0; //Set the default cost of repairs to 0
        protected int time = 0; //Set the default time for repairs to 0
        protected double paint; //Create a double representing the percentage of paint damage

        public vehicle() //Constructor
        {
            for (int i = 0; i <= numWheels; i++) //For each wheel
            {
                double wheelDamage = rand.NextDouble(); //Get a random damage percentage for the wheel
                wheels.Add(wheelDamage); //Record the damage
            }
            paint = rand.NextDouble(); //Set the paint to a random damage percentage
        }

        public void repairWheel(int wheel) //Repair the wheel
        {
            wheels[wheel] = 1.0;
            price += 30; //Increase the repair cost and time
            time += 30;
        }

        public void freshPaint() //Repaint the vehicle
        {
            paint = 0.99;
            price += 50; //Increase the repair cost and time
            time += 25;
        }

        public string invoice() //Get a string representing the job's invoice
        {
            string receipt = "Our total man-hours were " + time.ToString();
            receipt += " minutes, and given the nature of the work, it'll run " + price.ToString() + " dollars.";
            return receipt;
        }
    }

    class bicycle : vehicle //Class representing bicycles. Inherits from vehicle.
    {
        Random rand = new Random(); //Create a random number generator
        bool gearChain; //Boolean representing whether or not the gear chain is broken

        public bicycle() : base() //Constructor
        {
            base.numWheels = 2; //Overwrite the base number of wheels
            if (rand.NextDouble() < 0.5) //Get a 50% probability that the gear chain is broken
            {
                gearChain = false;
            }
            else
            {
                gearChain = true;
            }
        }

        public string check() //Create a string representing the bike's current state
        {
            string quote = "Well, the front wheel is ";
            if (wheels[0] > 0.9)
            {
                quote += "just fine.";
            } else if (wheels[0] > 0.75) 
            {
                quote += "servicable, but replacing it now will save you trouble later.";
            } else if (wheels[0] > 0.50)
            {
                quote += "wearing down a bit, but I can replace that for you.";
            } else if (wheels[0] > 0.25)
            {
                quote += "nearly worn out! It's a good thing you came in today.";
            } else
            {
                quote += "dangerously worn down! You gotta come in more often!";
            }
            quote += " As for the back wheel, it's ";
            if (wheels[1] > 0.9)
            {
                quote += "just fine.";
            }
            else if (wheels[1] > 0.75)
            {
                quote += "servicable, but replacing it now will save you trouble later.";
            }
            else if (wheels[1] > 0.50)
            {
                quote += "wearing down a bit, but I can replace that for you.";
            }
            else if (wheels[1] > 0.25)
            {
                quote += "nearly worn out! It's a good thing you came in today.";
            }
            else
            {
                quote += "dangerously worn down! You gotta come in more often!";
            }
            if (!gearChain)
            {
                quote += " The gear chain definitely needs replacing.";
            }
            if (paint < 0.5)
            {
                if (paint > 0.25)
                {
                    quote += " The paint's looking a little scuffed, could use a touch up.";
                } else
                {
                    quote += " It's real scratched up, too. It'll need a fresh coat of paint.";
                }
            }
            return quote;
        }

        public void repair() //Open a dialog to repair the bike
        {
            DialogResult dialog = MessageBox.Show("Repair front wheel?", "Repairs", MessageBoxButtons.YesNo); //Open dialog
            if (dialog == DialogResult.Yes) //If user chose to repair part
            {
                base.repairWheel(0); //Set part to maximum value
            }
            DialogResult dialog2 = MessageBox.Show("Repair back wheel?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog2 == DialogResult.Yes)
            {
                base.repairWheel(1);
            }
            DialogResult dialog3 = MessageBox.Show("Fresh coat of paint?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog3 == DialogResult.Yes)
            {
                base.freshPaint();
            }
            DialogResult dialog4 = MessageBox.Show("Replace gear chain?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog4 == DialogResult.Yes)
            {
                gearChain = true;
                base.price += 40; //Increase price
                base.time += 10; //Increase time
            }
        }
    }

    class van : vehicle //Class representing vans. Inherits from vehicle class.
    {
        Random rand = new Random(); //Create a random number generator
        bool wipers; //Boolean representing whether or not the wipers are broken
        double engine; //Double representing damage to the engine

        public van() : base() //Constructor
        {
            if (rand.NextDouble() < 0.5) //Get a 50% probability that the wipers are broken
            {
                wipers = true;
            }
            else
            {
                wipers = false;
            }
            engine = rand.NextDouble(); //Set the engine to a random damage percentage
        }

        public string check() //Create a string representing the van's current state
        {
            string quote = "Well, the front driver's side wheel is ";
            if (wheels[0] > 0.9)
            {
                quote += "just fine.";
            }
            else if (wheels[0] > 0.75)
            {
                quote += "servicable, but replacing it now will save you trouble later.";
            }
            else if (wheels[0] > 0.50)
            {
                quote += "wearing down a bit, but I can replace that for you.";
            }
            else if (wheels[0] > 0.25)
            {
                quote += "nearly worn out! It's a good thing you came in today.";
            }
            else
            {
                quote += "dangerously worn down! You gotta come in more often!";
            }
            quote += " As for the other front wheel, it's ";
            if (wheels[1] > 0.9)
            {
                quote += "just fine.";
            }
            else if (wheels[1] > 0.75)
            {
                quote += "servicable, but replacing it now will save you trouble later.";
            }
            else if (wheels[1] > 0.50)
            {
                quote += "wearing down a bit, but I can replace that for you.";
            }
            else if (wheels[1] > 0.25)
            {
                quote += "nearly worn out! It's a good thing you came in today.";
            }
            else
            {
                quote += "dangerously worn down! You gotta come in more often!";
            }
            quote += " Now, the one behind it, that's ";
            if (wheels[2] > 0.9)
            {
                quote += "just fine.";
            }
            else if (wheels[2] > 0.75)
            {
                quote += "servicable, but replacing it now will save you trouble later.";
            }
            else if (wheels[2] > 0.50)
            {
                quote += "wearing down a bit, but I can replace that for you.";
            }
            else if (wheels[2] > 0.25)
            {
                quote += "nearly worn out! It's a good thing you came in today.";
            }
            else
            {
                quote += "dangerously worn down! You gotta come in more often!";
            }
            quote += " And the last one's ";
            if (wheels[3] > 0.9)
            {
                quote += "just fine.";
            }
            else if (wheels[3] > 0.75)
            {
                quote += "servicable, but replacing it now will save you trouble later.";
            }
            else if (wheels[3] > 0.50)
            {
                quote += "wearing down a bit, but I can replace that for you.";
            }
            else if (wheels[3] > 0.25)
            {
                quote += "nearly worn out! It's a good thing you came in today.";
            }
            else
            {
                quote += "dangerously worn down! You gotta come in more often!";
            }
            if (paint < 0.5)
            {
                if (paint > 0.25)
                {
                    quote += " The paint's looking a little scuffed, could use a touch up.";
                }
                else
                {
                    quote += " It's real scratched up, too. It'll need a fresh coat of paint.";
                }
            }
            if (!wipers)
            {
                quote += " Oh, you've got a misaligned wiper, that needs replacing. It's a safety hazard.";
            }
            if (engine < 0.8)
            {
                quote += " And that sound the engine's making? Yeah, that's gonna cost you.";
            }
            else
            {
                quote += " And the engine could always use a tune-up. I'll change the oil while I'm at it."; //Upsell
            }
            return quote;
        }
        public void repair() //Open a dialog to repair the van
        {
            DialogResult dialog = MessageBox.Show("Repair front driver's wheel?", "Repairs", MessageBoxButtons.YesNo); //Open dialog
            if (dialog == DialogResult.Yes) //Set part to maximum value
            {
                base.repairWheel(0); //Set part to maximum value
            }
            DialogResult dialog2 = MessageBox.Show("Repair front passenger's wheel?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog2 == DialogResult.Yes)
            {
                base.repairWheel(1);
            }
            DialogResult dialog3 = MessageBox.Show("Repair rear driver's wheel?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog3 == DialogResult.Yes)
            {
                base.repairWheel(2);
            }
            DialogResult dialog4 = MessageBox.Show("Repair rear passenger's wheel?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog4 == DialogResult.Yes)
            {
                base.repairWheel(3);
            }
            DialogResult dialog5 = MessageBox.Show("Fresh coat of paint?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog5 == DialogResult.Yes)
            {
                base.freshPaint();
            }
            DialogResult dialog6 = MessageBox.Show("Replace wipers?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog6 == DialogResult.Yes)
            {
                wipers = true;
                base.price += 10; //Increase base price and time
                base.time += 5;
            }
            DialogResult dialog7 = MessageBox.Show("Fix engine?", "Repairs", MessageBoxButtons.YesNo);
            if (dialog7 == DialogResult.Yes)
            {
                engine = 0.99;
                base.price += 150; //increase base price and time
                base.time += 100;
            }
        }
    }
}
