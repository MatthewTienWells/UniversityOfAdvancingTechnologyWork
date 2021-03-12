using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Security.Cryptography.X509Certificates;
using System.Data.SqlTypes;

/// <summary>
/// The rules for calculations are as follows:
/// For fulltime employees, bonus is determined by the length of their name * their salary, and doubled if they increased revenue for real.
/// For parttime employees, bonus is determined by the hours worked * their salary / forty, and tripled if they increased revenue for real.
/// For fulltime employees, the base vacation days is their lucky number mod 17, and for parttime, their base vacation is their lucky 
/// number mod 8.
/// Vacation days are determined by performing the following operations on the employee's base vacation days:
///     Multiply by 3 if they check 'please'
///     Multiply by 5 if they check 'Open Sesame'
///     Subtract 4 if they check 'Abracadabra'
/// 
/// A future update to consider would be an admin interface that allows these calculations to be altered.
/// </summary>

namespace CompanyBenefits
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            panel2.Visible = false;
            panel3.Visible = false;
        }

        class employee
        {
            public int salary { get; set; }
            public int luck { get; set;}
            public bool forReal { get; set; }
            public bool mag1 { get; set; }
            public bool mag2 { get; set; }
            public bool mag3 { get; set; }
            public List<string> accolades { get; set; }

            public employee()
            {
                accolades = new List<string>();
            }

            public void displayBenefits(int bonus, int vacation)
            {
                string output = "Your bonus is " + bonus.ToString() + " dollars, and your vacation days are " + vacation.ToString(); ///Format output text
                MessageBox.Show(output); ///Display output
            }

            public string displayAccolades()
            {
                string disText = ""; //Text to be displayed
                if (accolades.Count() > 0)
                {
                    foreach (string acc in accolades) //Iterate through accolades
                    {
                        disText += acc + "\r\n";
                    }
                }
                return disText;
            }
        }
        class fulltime : employee
        {
            public int nameLen { get; set; } //Length of employee name
            public string name { get; set; } //employee name

            public fulltime()
            {
                name = ""; ///Set a blank name
                nameLen = name.Length;
            }

            public void update()
            {
                nameLen = name.Length;
            }
            public int vacationhours()
            {
                int days = luck % 17;
                if (mag1) ///If the first magic word is checked
                {
                    days *= 3; ///Multiply vacation by 3
                }
                if (mag2) ///If the second magic word is checked
                {
                    days *= 5; ///Multiply vacation by 5
                }
                if (mag3) ///If the third magic word is checked
                {
                    days -= 4; ///SUbtract four vacation days
                }
                return days;
            }

            public int bonusSalary()
            {
                int bonus = nameLen * salary; ///Determine bonus by length of name times salary
                if (forReal)
                {
                    bonus *= 2; ///If revenue was increased for real, double bonus
                }
                return bonus;
            }
        }
        class parttime : employee
        {
            public int hours { get; set; } //Number of hours worked per week

            public parttime()
            {
                hours = 0;
            }
            public int vacationhours()
            {
                int days = luck % 8;
                if (mag1) ///If the first magic word is checked
                {
                    days *= 3; ///Multiply vacation by 3
                }
                if (mag2) ///If the second magic word is checked
                {
                    days *= 5; ///Multiply vacation by 5
                }
                if (mag3) ///If the third magic word is checked
                {
                    days -= 4; ///SUbtract four vacation days
                }
                return days;
            }

            public int bonusSalary()
            {
                int bonus = salary * hours / 40; ///Determine bonus by length of name times salary
                if (forReal)
                {
                    bonus *= 3; ///If revenue was increased for real, double bonus
                }
                return bonus;
            }
        }

        fulltime full = new fulltime();
        parttime part = new parttime();
        private void button2_Click(object sender, EventArgs e) //Guesses lucky number
        {
            var rand = new Random(); //Initiate random number generator
            const string caption = "Lucky Number"; //Caption for the message box
            DialogResult result; //Initialize variable to retain the user's acceptance outside of the loop context
            int number; //Initialize an int to hold the random number
            do
            {
                number = rand.Next(); //Get a random number
                var message = "Is your number " + number.ToString() + "?"; //Create a string to ask if the number is correct
                result = MessageBox.Show(message, caption, //Show a message to ask if the number is correct
                                 MessageBoxButtons.YesNo,
                                 MessageBoxIcon.Question);
            } while (result == DialogResult.No); //If the number was wrong, guess again
            dateField.Text = number.ToString(); //Write the guess to the lucky number field
            full.luck = number; //Update the class object
            part.luck = number;
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (
                MessageBox.Show(
                    "Warning, any previously saved session will be overwritten! Continue?", "Confirm", //Warn the user their last save will be lost
                    MessageBoxButtons.YesNo,
                    MessageBoxIcon.Question) == DialogResult.Yes)
            {
                string path = @"benefit_session.txt"; //Path to the save file
                string luck = full.luck.ToString(); //Read the data from class objects
                string name = full.name;
                string salary = full.salary.ToString();
                string mag1 = full.mag1.ToString();
                string mag2 = full.mag2.ToString();
                string mag3 = full.mag3.ToString();
                string fulltime = fullTime.Checked.ToString();
                string hours = part.hours.ToString();
                string accolades = full.displayAccolades();

                using (StreamWriter outfile = File.CreateText(path)) //Open a buffer to write to the save file, clearing any existing data
                {
                    outfile.WriteLine(name); //Write the data to the file
                    outfile.WriteLine(salary);
                    outfile.WriteLine(luck);
                    outfile.WriteLine(mag1);
                    outfile.WriteLine(mag2);
                    outfile.WriteLine(mag3);
                    outfile.WriteLine(fulltime);
                    outfile.WriteLine(hours);
                    outfile.Write(accolades);
                    outfile.Close();
                }
            }
        }

        private void loadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (
                MessageBox.Show(
                    "Warning, your current session will be overwritten! Continue?", "Confirm", //Warn the user their last save will be lost
                    MessageBoxButtons.YesNo,
                    MessageBoxIcon.Question) == DialogResult.Yes)
            {
                string path = @"benefit_session.txt"; //Path to the save file
                if (File.Exists(path)) //Validate that a save exists
                {
                    using (StreamReader infile = File.OpenText(path)) //Open a buffer to read from the save file
                    {
                        string name = infile.ReadLine(); //Read a line from the file
                        string salary = infile.ReadLine(); //Read a line from the file
                        string luck = infile.ReadLine(); //Read a line from the file
                        string mag1 = infile.ReadLine(); //Read a line from the file
                        string mag2 = infile.ReadLine(); //Read a line from the file
                        string mag3 = infile.ReadLine(); //Read a line from the file
                        string fulltime = infile.ReadLine(); //Read a line from the file
                        string hours = infile.ReadLine(); //Read a line from the file
                        full.name = name; //Set the attributes for full and parttime employees
                        full.luck = Int32.Parse(luck); //Write the data to the class objects
                        part.luck = Int32.Parse(luck);
                        full.salary = Int32.Parse(salary);
                        part.salary = Int32.Parse(salary);
                        full.mag1 = Boolean.Parse(mag1);
                        part.mag1 = Boolean.Parse(mag1);
                        full.mag2 = Boolean.Parse(mag2);
                        part.mag2 = Boolean.Parse(mag2);
                        full.mag3 = Boolean.Parse(mag3);
                        part.mag3 = Boolean.Parse(mag3);
                        fullTime.Checked = Boolean.Parse(fulltime);
                        part.hours = Int32.Parse(hours);
                        full.accolades.Clear(); //Clear the current accolades list
                        while (!infile.EndOfStream) //The rest of the file is accolades on multiple lines, so read it all
                        {
                            full.accolades.Add(infile.ReadLine());
                        }
                        part.accolades = full.accolades; //Save the accolades to both objects
                        successDisplay.Text = full.displayAccolades(); //Format the accolades an display them in the GUI
                        infile.Close(); //Close the file
                        resetFields(); //Update the UI
                    }
                }
                else //If no save file exists
                {
                    MessageBox.Show("No save file available!"); //Warn the user there is no save file
                }
            }
        }

        private void nameField_TextChanged(object sender, EventArgs e)
        {
            full.name = (sender as TextBox).Text; //Update the class object
            full.update();
        }

        private void salaryField_TextChanged(object sender, EventArgs e)
        {
            int money;
            if (Int32.TryParse((sender as TextBox).Text, out money))
            {
                full.salary = money; //Update the class object
                part.salary = money;
            } else
            {
                MessageBox.Show("Type your salary as an integer!");
                resetFields();
            }

        }

        private void dateField_TextChanged(object sender, EventArgs e)
        {
            int luck;
            if (Int32.TryParse((sender as TextBox).Text, out luck))
            {
                full.luck = luck; //Update the class object
                part.luck = luck;
            }
            else
            {
                MessageBox.Show("Type your lucky number as an integer!");
                resetFields();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            panel1.Visible = false; //Show a different panel
            panel2.Visible = true;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            full.forReal = (sender as RadioButton).Checked; //Update the class object
            part.forReal = (sender as RadioButton).Checked;
        }

        private void perWeek_TextChanged(object sender, EventArgs e)
        {
            int hours;
            long tooMany;
            if (Int32.TryParse((sender as TextBox).Text, out hours))
            {
                if (hours < 40)
                {
                    part.hours = hours; //Update the class object
                } else if (hours < 169)
                {
                    MessageBox.Show("No you have not, that would be illegal, shut up.");
                    resetFields();
                } else
                {
                    MessageBox.Show("Please forward your work schedule to the Nobel Committee for Physics for your award on time dilation.");
                    resetFields();
                }
            } else if (long.TryParse((sender as TextBox).Text, out tooMany))
            {
                MessageBox.Show("Please forward your work schedule to the Nobel Committee for Physics for your award on time dilation.");
                resetFields();
            } else
            {
                MessageBox.Show("Type your hours as an integer!");
                resetFields();
            }
        }

        private void abra_CheckedChanged(object sender, EventArgs e)
        {
            full.mag3 = (sender as CheckBox).Checked; //Update the class object
            part.mag3 = (sender as CheckBox).Checked;
        }

        private void sesame_CheckedChanged(object sender, EventArgs e)
        {
            full.mag2 = (sender as CheckBox).Checked; //Update the class object
            part.mag2 = (sender as CheckBox).Checked;
        }

        private void please_CheckedChanged(object sender, EventArgs e)
        {
            full.mag1 = (sender as CheckBox).Checked; //Update the class object
            part.mag1 = (sender as CheckBox).Checked;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            panel2.Visible = false; //Show a different panel
            panel1.Visible = true;
        }

        private void fullTime_CheckedChanged(object sender, EventArgs e)
        {
            perWeek.Enabled = (!fullTime.Checked); //Update the UI to show that hours should only be entered for parttime employees
        }

        private void button6_Click(object sender, EventArgs e)
        {
            panel2.Visible = true; //Show a different panel
            panel3.Visible = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            panel2.Visible = false;
            panel3.Visible = true; //Show a different panel
        }

        private void Finish_Click(object sender, EventArgs e)
        {
            if (fullTime.Checked) //Check if the employee is full or part time
            {
                full.displayBenefits(full.bonusSalary(), full.vacationhours()); //Show the results for a fulltime employee
            }else
            {
                part.displayBenefits(part.bonusSalary(), part.vacationhours()); //Show the results for a parttime employee
            }
        }

        private void resetFields() //Set the content of all UI elements to match the current back-end values.
        {
            nameField.Text = full.name;
            salaryField.Text = full.salary.ToString();
            dateField.Text = full.luck.ToString();
            radioButton1.Checked = !full.forReal;
            radioButton2.Checked = full.forReal;
            please.Checked = full.mag1;
            sesame.Checked = full.mag2;
            abra.Checked = full.mag3;
            perWeek.Text = part.hours.ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            full.accolades.Add(successBox.Text); //Update the class object
            part.accolades = full.accolades;
            successBox.Text = "";
            successDisplay.Text = full.displayAccolades();
        }

        private void button7_Click(object sender, EventArgs e) //Remove the last accolade from the list and display it in the edit box if the box is empty
        {
            string lastacc = full.accolades[full.accolades.Count() - 1]; //Get the last accolade
            full.accolades.Remove(lastacc); //Remove it from the class object
            part.accolades = full.accolades;
            if (successBox.Text == "") //If the editing box is empty
            {
                successBox.Text = lastacc; //Show the removed line in the editing field
            }
            successDisplay.Text = full.displayAccolades(); //Refresh the display
        }
    }
}
