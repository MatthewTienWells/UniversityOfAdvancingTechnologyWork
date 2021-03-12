namespace CompanyBenefits
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// Estimated work time 1 hr
        /// March 28 - 1 Hour, 8 minutes
        /// March 29 - 4 minutes
        /// Final analysis:
        /// The project took 20% longer than anticipated. 
        /// This was mostly due to rounding at a high relative significance at the initial estimate.
        /// Another source of time loss was forgetting which file my method was in for five minutes.
        /// The final issue was that I forgot to comment while writing it and had to go back through.
        /// In summary, more time should be budgeted for future projects.
        /// 
        /// Part 2:
        /// Estimated work time 5 minutes
        /// March 29 - 5 minutes
        /// I expected this to be very quick, because I already had graceful error handling set up.
        /// I did still need to implement try-catch error handling however.
        /// So that took a few minutes.
        /// I also took a phone call, which added about a minute.
        /// All-in-all, my estimation was spot-on.
        /// 
        /// Part 3:
        /// Estimated work time 1 hr 30 mn
        /// April 1 - 10 minutes
        /// April 3 - 45 minutes
        /// April 4 - 1 hr 53 minutes
        /// April 4 - 39 minutes
        /// The total time was 3 hours and 27 minutes, more than 200% of the expected time.
        /// This was largely due to feature creep.
        /// The initial while loop implemented in the number guesser was complete on the first day.
        /// The file IO for the save and load features were complete on the second day, within the initial estimate.
        /// However, future-proofing the save and load features by generalizing them to all elements within group boxes
        /// proved an extreme time-sink, taking more than the initial estimate to implement, and another session to debug.
        /// The future-proofing did include the addition of the other loop requirements, however, and should cut down on 
        /// update overhead later in the project.
        /// In later updates, I should be able to get closer to my estimate by not changing the scope of the project during implementation.
        /// 
        /// Part 4:
        /// Estimated work time 30 minutes
        /// April 7 - 30 minutes
        /// My estimate proved to be correct.
        /// This was mostly because there were very few tasks to complete.
        /// This, in turn, was because I had already implemented several of this sprint's objectives in the last part's future-proofing.
        /// In summary, the expected gains from the past work have already begun to take place.
        /// 
        /// Part 5:
        /// Estimated work time 150 minutes
        /// April 15 - 45 minutes
        /// April 16 - 27 minutes
        /// April 19 - 70 minutes
        /// Total time: 142 minutes.
        /// My estimate proved mostly correct, at 105% of the actual time.
        /// I regard this as an indicator that I'm grasping the scope and difficulty of c# programs better.
        /// I also attribute this to having a good idea of what I needed to do beginning the project.
        /// Finally, I budgeted time for error-handling and modifications in the case I misunderstood something, which I ended up needing.
        /// 
        /// Part 6:
        /// Estimated work time 90 minutes
        /// April 22 - 30 minutes 
        /// April 23 - 15 minutes
        /// April 24 - 140 minutes
        /// This was the second furthest off my estimate has been, at just over 200% of the expected time.
        /// This can largely be attributed to my running into the issue of being unable to pass both the class objects I need and the Form
        /// objects into each forms constructor, so that previous forms could be accessed.
        /// After spending a considerable amount of time searching for a workaround to this issue, I decided to take a different tack.
        /// I switched my code over from several linked Forms to a single form with variably visible panels.
        /// This ensured there were no issues with inheritance, and that the window's size remained constant when changing pages.
        /// All-in-all, I consider this to have been a productive session, as the issue was fixed and would not have been reasonable to
        /// fit into the inital estimate.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.nameField = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.salaryField = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.button2 = new System.Windows.Forms.Button();
            this.dateField = new System.Windows.Forms.TextBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.button4 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.button1 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.perWeek = new System.Windows.Forms.TextBox();
            this.fullTime = new System.Windows.Forms.CheckBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.abra = new System.Windows.Forms.CheckBox();
            this.sesame = new System.Windows.Forms.CheckBox();
            this.please = new System.Windows.Forms.CheckBox();
            this.panel3 = new System.Windows.Forms.Panel();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.successDisplay = new System.Windows.Forms.TextBox();
            this.button5 = new System.Windows.Forms.Button();
            this.successBox = new System.Windows.Forms.TextBox();
            this.Finish = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.panel3.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox1.Controls.Add(this.nameField);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(10, 13);
            this.groupBox1.MaximumSize = new System.Drawing.Size(2000, 74);
            this.groupBox1.MinimumSize = new System.Drawing.Size(148, 61);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(474, 74);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Your Name";
            // 
            // nameField
            // 
            this.nameField.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.nameField.Location = new System.Drawing.Point(7, 29);
            this.nameField.Name = "nameField";
            this.nameField.Size = new System.Drawing.Size(461, 30);
            this.nameField.TabIndex = 0;
            this.nameField.LostFocus += new System.EventHandler(this.nameField_TextChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox2.Controls.Add(this.salaryField);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.Location = new System.Drawing.Point(11, 147);
            this.groupBox2.MaximumSize = new System.Drawing.Size(2000, 78);
            this.groupBox2.MinimumSize = new System.Drawing.Size(149, 53);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(473, 78);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Your Current Salary";
            // 
            // salaryField
            // 
            this.salaryField.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.salaryField.Location = new System.Drawing.Point(7, 29);
            this.salaryField.MinimumSize = new System.Drawing.Size(136, 22);
            this.salaryField.Name = "salaryField";
            this.salaryField.Size = new System.Drawing.Size(460, 30);
            this.salaryField.TabIndex = 0;
            this.salaryField.LostFocus += new System.EventHandler(this.salaryField_TextChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox3.Controls.Add(this.button2);
            this.groupBox3.Controls.Add(this.dateField);
            this.groupBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox3.Location = new System.Drawing.Point(11, 298);
            this.groupBox3.MaximumSize = new System.Drawing.Size(2000, 110);
            this.groupBox3.MinimumSize = new System.Drawing.Size(149, 110);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(473, 110);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Lucky Number";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(6, 58);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(182, 47);
            this.button2.TabIndex = 1;
            this.button2.Text = "Guess For Me!";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // dateField
            // 
            this.dateField.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dateField.Location = new System.Drawing.Point(7, 22);
            this.dateField.MinimumSize = new System.Drawing.Size(136, 22);
            this.dateField.Name = "dateField";
            this.dateField.Size = new System.Drawing.Size(460, 30);
            this.dateField.TabIndex = 0;
            this.dateField.LostFocus += new System.EventHandler(this.dateField_TextChanged);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveToolStripMenuItem,
            this.loadToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(501, 36);
            this.menuStrip1.TabIndex = 8;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(67, 32);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // loadToolStripMenuItem
            // 
            this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
            this.loadToolStripMenuItem.Size = new System.Drawing.Size(69, 32);
            this.loadToolStripMenuItem.Text = "Load";
            this.loadToolStripMenuItem.Click += new System.EventHandler(this.loadToolStripMenuItem_Click);
            // 
            // button4
            // 
            this.button4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.Location = new System.Drawing.Point(411, 500);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(73, 36);
            this.button4.TabIndex = 11;
            this.button4.Text = "Next";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.Controls.Add(this.groupBox1);
            this.panel1.Controls.Add(this.button4);
            this.panel1.Controls.Add(this.groupBox2);
            this.panel1.Controls.Add(this.groupBox3);
            this.panel1.Location = new System.Drawing.Point(0, 35);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(501, 539);
            this.panel1.TabIndex = 12;
            // 
            // panel2
            // 
            this.panel2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel2.Controls.Add(this.groupBox4);
            this.panel2.Controls.Add(this.button1);
            this.panel2.Controls.Add(this.button3);
            this.panel2.Controls.Add(this.groupBox7);
            this.panel2.Controls.Add(this.groupBox5);
            this.panel2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.panel2.Location = new System.Drawing.Point(0, 35);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(501, 537);
            this.panel2.TabIndex = 15;
            // 
            // groupBox4
            // 
            this.groupBox4.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox4.Controls.Add(this.radioButton2);
            this.groupBox4.Controls.Add(this.radioButton1);
            this.groupBox4.Location = new System.Drawing.Point(19, 39);
            this.groupBox4.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox4.MaximumSize = new System.Drawing.Size(2000, 125);
            this.groupBox4.MinimumSize = new System.Drawing.Size(300, 125);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox4.Size = new System.Drawing.Size(478, 125);
            this.groupBox4.TabIndex = 5;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Did you increase revenue?";
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(10, 78);
            this.radioButton2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(131, 29);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "Yes for real";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(10, 34);
            this.radioButton1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(67, 29);
            this.radioButton1.TabIndex = 0;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Yes";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button1.Location = new System.Drawing.Point(423, 502);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 32);
            this.button1.TabIndex = 12;
            this.button1.Text = "Next";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button3
            // 
            this.button3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button3.Location = new System.Drawing.Point(17, 502);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(105, 32);
            this.button3.TabIndex = 13;
            this.button3.Text = "Previous";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // groupBox7
            // 
            this.groupBox7.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox7.Controls.Add(this.perWeek);
            this.groupBox7.Controls.Add(this.fullTime);
            this.groupBox7.Location = new System.Drawing.Point(18, 340);
            this.groupBox7.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox7.MaximumSize = new System.Drawing.Size(2000, 156);
            this.groupBox7.MinimumSize = new System.Drawing.Size(300, 156);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox7.Size = new System.Drawing.Size(479, 156);
            this.groupBox7.TabIndex = 11;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "How many hours did you work per week?";
            // 
            // perWeek
            // 
            this.perWeek.Location = new System.Drawing.Point(10, 38);
            this.perWeek.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.perWeek.Name = "perWeek";
            this.perWeek.Size = new System.Drawing.Size(148, 30);
            this.perWeek.TabIndex = 1;
            this.perWeek.LostFocus += new System.EventHandler(this.perWeek_TextChanged);
            // 
            // fullTime
            // 
            this.fullTime.AutoSize = true;
            this.fullTime.Location = new System.Drawing.Point(8, 111);
            this.fullTime.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.fullTime.Name = "fullTime";
            this.fullTime.Size = new System.Drawing.Size(114, 29);
            this.fullTime.TabIndex = 0;
            this.fullTime.Text = "Full Time";
            this.fullTime.UseVisualStyleBackColor = true;
            this.fullTime.CheckedChanged += new System.EventHandler(this.fullTime_CheckedChanged);
            // 
            // groupBox5
            // 
            this.groupBox5.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox5.Controls.Add(this.abra);
            this.groupBox5.Controls.Add(this.sesame);
            this.groupBox5.Controls.Add(this.please);
            this.groupBox5.Location = new System.Drawing.Point(18, 174);
            this.groupBox5.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox5.MaximumSize = new System.Drawing.Size(2000, 156);
            this.groupBox5.MinimumSize = new System.Drawing.Size(300, 156);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox5.Size = new System.Drawing.Size(479, 156);
            this.groupBox5.TabIndex = 6;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "What\'s the magic word?";
            // 
            // abra
            // 
            this.abra.AutoSize = true;
            this.abra.Location = new System.Drawing.Point(10, 122);
            this.abra.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.abra.Name = "abra";
            this.abra.Size = new System.Drawing.Size(147, 29);
            this.abra.TabIndex = 2;
            this.abra.Text = "Abracadabra";
            this.abra.UseVisualStyleBackColor = true;
            this.abra.CheckedChanged += new System.EventHandler(this.abra_CheckedChanged);
            // 
            // sesame
            // 
            this.sesame.AutoSize = true;
            this.sesame.Location = new System.Drawing.Point(10, 78);
            this.sesame.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.sesame.Name = "sesame";
            this.sesame.Size = new System.Drawing.Size(161, 29);
            this.sesame.TabIndex = 1;
            this.sesame.Text = "Open Sesame";
            this.sesame.UseVisualStyleBackColor = true;
            this.sesame.CheckedChanged += new System.EventHandler(this.sesame_CheckedChanged);
            // 
            // please
            // 
            this.please.AutoSize = true;
            this.please.Location = new System.Drawing.Point(10, 34);
            this.please.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.please.Name = "please";
            this.please.Size = new System.Drawing.Size(94, 29);
            this.please.TabIndex = 0;
            this.please.Text = "Please";
            this.please.UseVisualStyleBackColor = true;
            this.please.CheckedChanged += new System.EventHandler(this.please_CheckedChanged);
            // 
            // panel3
            // 
            this.panel3.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel3.Controls.Add(this.groupBox6);
            this.panel3.Controls.Add(this.Finish);
            this.panel3.Controls.Add(this.button6);
            this.panel3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.panel3.Location = new System.Drawing.Point(0, 35);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(500, 546);
            this.panel3.TabIndex = 16;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.button7);
            this.groupBox6.Controls.Add(this.successDisplay);
            this.groupBox6.Controls.Add(this.button5);
            this.groupBox6.Controls.Add(this.successBox);
            this.groupBox6.Location = new System.Drawing.Point(13, 15);
            this.groupBox6.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox6.Size = new System.Drawing.Size(460, 475);
            this.groupBox6.TabIndex = 10;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "List your accomplishments.";
            // 
            // successDisplay
            // 
            this.successDisplay.Location = new System.Drawing.Point(10, 120);
            this.successDisplay.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.successDisplay.Multiline = true;
            this.successDisplay.Name = "successDisplay";
            this.successDisplay.Size = new System.Drawing.Size(438, 346);
            this.successDisplay.TabIndex = 2;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(8, 74);
            this.button5.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(225, 36);
            this.button5.TabIndex = 1;
            this.button5.Text = "Add accomplishment";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // successBox
            // 
            this.successBox.Location = new System.Drawing.Point(10, 33);
            this.successBox.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.successBox.Name = "successBox";
            this.successBox.Size = new System.Drawing.Size(439, 30);
            this.successBox.TabIndex = 0;
            // 
            // Finish
            // 
            this.Finish.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Finish.Location = new System.Drawing.Point(384, 498);
            this.Finish.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Finish.Name = "Finish";
            this.Finish.Size = new System.Drawing.Size(112, 36);
            this.Finish.TabIndex = 11;
            this.Finish.Text = "Finish";
            this.Finish.UseVisualStyleBackColor = true;
            this.Finish.Click += new System.EventHandler(this.Finish_Click);
            // 
            // button6
            // 
            this.button6.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button6.Location = new System.Drawing.Point(4, 500);
            this.button6.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(112, 36);
            this.button6.TabIndex = 12;
            this.button6.Text = "Previous";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(361, 74);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(87, 36);
            this.button7.TabIndex = 3;
            this.button7.Text = "Undo";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.OldLace;
            this.ClientSize = new System.Drawing.Size(501, 577);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.MinimumSize = new System.Drawing.Size(519, 624);
            this.Name = "Form1";
            this.Text = "BenefitCalculator";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.groupBox7.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox nameField;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox salaryField;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox dateField;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItem;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.GroupBox groupBox7;
        private System.Windows.Forms.TextBox perWeek;
        private System.Windows.Forms.CheckBox fullTime;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.CheckBox abra;
        private System.Windows.Forms.CheckBox sesame;
        private System.Windows.Forms.CheckBox please;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.TextBox successDisplay;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.TextBox successBox;
        private System.Windows.Forms.Button Finish;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
    }
}

