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
    public partial class Form2 : Form
    {
        static object full;
        static object part;
        public Form2(object fu, object pa)
        {
            InitializeComponent();
            full = fu;
            part = pa;
        }

        Form f3 = new Form3(full, part);

        private void groupBox4_Enter(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            full.GetType().GetProperty("forReal").SetValue(full, (sender as RadioButton).Checked);
            part.GetType().GetProperty("forReal").SetValue(part, (sender as RadioButton).Checked);

        }

        private void please_CheckedChanged(object sender, EventArgs e)
        {
            full.GetType().GetProperty("mag1").SetValue(full, (sender as CheckBox).Checked);
            part.GetType().GetProperty("mag1").SetValue(part, (sender as CheckBox).Checked);
        }

        private void sesame_CheckedChanged(object sender, EventArgs e)
        {
            full.GetType().GetProperty("mag2").SetValue(full, (sender as CheckBox).Checked);
            part.GetType().GetProperty("mag2").SetValue(part, (sender as CheckBox).Checked);
        }

        private void abra_CheckedChanged(object sender, EventArgs e)
        {
            full.GetType().GetProperty("mag3").SetValue(full, (sender as CheckBox).Checked);
            part.GetType().GetProperty("mag3").SetValue(part, (sender as CheckBox).Checked);
        }

        private void fullTime_CheckedChanged(object sender, EventArgs e)
        {
            perWeek.Enabled = false;
        }

        private void perWeek_TextChanged(object sender, EventArgs e)
        {
            int hours;
            if (Int32.TryParse((sender as TextBox).Text, out hours))
            {
                part.GetType().GetProperty("hours").SetValue(part, hours);
            }
            else
            {
                MessageBox.Show("Type your hours as an int!");
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Program.form1.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}
