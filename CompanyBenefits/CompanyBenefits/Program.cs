using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Threading.Tasks;
using System.Windows.Forms;
/// <summary>
/// Initial estimate 1 hour
/// March 28
/// </summary>
namespace CompanyBenefits
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        static public Form1 form1;
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            form1 = new Form1();
            Application.Run(form1);
        }
    }
}
