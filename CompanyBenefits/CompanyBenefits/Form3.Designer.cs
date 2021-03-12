namespace CompanyBenefits
{
    partial class Form3
    {
        /// <summary>
        /// Required designer variable.
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
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.successDisplay = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.successBox = new System.Windows.Forms.TextBox();
            this.Finish = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.groupBox6.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.successDisplay);
            this.groupBox6.Controls.Add(this.button3);
            this.groupBox6.Controls.Add(this.successBox);
            this.groupBox6.Location = new System.Drawing.Point(13, 15);
            this.groupBox6.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox6.Size = new System.Drawing.Size(460, 296);
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
            this.successDisplay.ReadOnly = true;
            this.successDisplay.Size = new System.Drawing.Size(438, 166);
            this.successDisplay.TabIndex = 2;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(225, 78);
            this.button3.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(225, 36);
            this.button3.TabIndex = 1;
            this.button3.Text = "Add accomplishment";
            this.button3.UseVisualStyleBackColor = true;
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
            this.Finish.Location = new System.Drawing.Point(447, 349);
            this.Finish.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Finish.Name = "Finish";
            this.Finish.Size = new System.Drawing.Size(112, 36);
            this.Finish.TabIndex = 11;
            this.Finish.Text = "Finish";
            this.Finish.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button2.Location = new System.Drawing.Point(4, 349);
            this.button2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(112, 36);
            this.button2.TabIndex = 12;
            this.button2.Text = "Previous";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.groupBox6);
            this.panel1.Controls.Add(this.Finish);
            this.panel1.Controls.Add(this.button2);
            this.panel1.Location = new System.Drawing.Point(-1, 31);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(563, 390);
            this.panel1.TabIndex = 13;
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(652, 502);
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Form3";
            this.Text = "Form3";
            this.Load += new System.EventHandler(this.Form3_Load);
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.TextBox successDisplay;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.TextBox successBox;
        private System.Windows.Forms.Button Finish;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Panel panel1;
    }
}