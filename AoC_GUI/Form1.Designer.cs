namespace AoC_GUI
{
    partial class Form1
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
            this.tabControl = new System.Windows.Forms.TabControl();
            this.tab2015 = new System.Windows.Forms.TabPage();
            this.tab2016 = new System.Windows.Forms.TabPage();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.tabControl.SuspendLayout();
            this.tab2015.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.tab2015);
            this.tabControl.Controls.Add(this.tab2016);
            this.tabControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl.Location = new System.Drawing.Point(0, 0);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(1024, 603);
            this.tabControl.TabIndex = 0;
            // 
            // tab2015
            // 
            this.tab2015.Controls.Add(this.treeView1);
            this.tab2015.Location = new System.Drawing.Point(4, 25);
            this.tab2015.Name = "tab2015";
            this.tab2015.Padding = new System.Windows.Forms.Padding(3);
            this.tab2015.Size = new System.Drawing.Size(1016, 574);
            this.tab2015.TabIndex = 0;
            this.tab2015.Text = "2015";
            this.tab2015.UseVisualStyleBackColor = true;
            // 
            // tab2016
            // 
            this.tab2016.Location = new System.Drawing.Point(4, 25);
            this.tab2016.Name = "tab2016";
            this.tab2016.Padding = new System.Windows.Forms.Padding(3);
            this.tab2016.Size = new System.Drawing.Size(1016, 574);
            this.tab2016.TabIndex = 1;
            this.tab2016.Text = "2016";
            this.tab2016.UseVisualStyleBackColor = true;
            // 
            // treeView1
            // 
            this.treeView1.Dock = System.Windows.Forms.DockStyle.Left;
            this.treeView1.Location = new System.Drawing.Point(3, 3);
            this.treeView1.Name = "treeView1";
            this.treeView1.Size = new System.Drawing.Size(235, 568);
            this.treeView1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1024, 603);
            this.Controls.Add(this.tabControl);
            this.Name = "Form1";
            this.Text = "Form1";
            this.tabControl.ResumeLayout(false);
            this.tab2015.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage tab2015;
        private System.Windows.Forms.TabPage tab2016;
        private System.Windows.Forms.TreeView treeView1;
    }
}

