using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using KPUCalcServerLib;

namespace Lab1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        IAdvCal calculator = new Calculator() as IAdvCal;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnCalculate_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string op = cbxOperation.Text;	// A very dirty hack - don't ever switch on text strings from the UI!!!
                switch (op)
                {
                    case "Add":
                        tbxResult.Text = calculator.Add(int.Parse(tbxArg1.Text), int.Parse(tbxArg2.Text)).ToString();
                        break;
                    case "Sub":
                        tbxResult.Text = calculator.Sub(int.Parse(tbxArg1.Text), int.Parse(tbxArg2.Text)).ToString();
                        break;
                    case "Mul":
                        tbxResult.Text = calculator.Mul(int.Parse(tbxArg1.Text), int.Parse(tbxArg2.Text)).ToString();
                        break;
                    case "Div":
                        tbxResult.Text = calculator.Div(int.Parse(tbxArg1.Text), int.Parse(tbxArg2.Text)).ToString();
                        break;

                    default:
                        MessageBox.Show("Operation not supported");
                        break;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void tbxOffset_TextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                calculator.Offset = int.Parse(tbxOffset.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
