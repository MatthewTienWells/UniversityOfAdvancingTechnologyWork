using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CompanyBenefits
{
    public partial class Form3 : Form
    {
        object full;
        object part;
        public Form3(object fu, object pa)
        {
            InitializeComponent();
            full = fu;
            part = pa;
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }
///        private void bonusCalc(object sender, EventArgs e)
///        {
///            if (Program.form1.fullTime.Checked)
///            {
///                full.displayBenefits(full.bonusSalary(), full.vacationhours());
///            }
///            else
///            {
///                part.displayBenefits(part.bonusSalary(), part.vacationhours());
///            }
///        }

        List<string> successes = new List<string>(); //Make a global variable containing the list of accomplishments
        private void button3_Click(object sender, EventArgs e)
        {
            string success = successBox.Text; //Get the new success to add
            successes.Add(success); //Add the successs to the global list
            string accomplishments = ""; //Create a string to display the successes
            foreach (string entry in successes) //Go through the list of successes
            {
                accomplishments += entry; //Add the success to the combined string
                accomplishments += " "; //Add a space
            }
            successDisplay.Text = accomplishments; //Display the text
            if (successes.Count() > 2) //If enough successes have been added since loading
            {
                MessageBox.Show("Good job! That isn't quantifiable enough to effect your bonus!"); //Display an encouraging message!
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            
        }
    }

}
