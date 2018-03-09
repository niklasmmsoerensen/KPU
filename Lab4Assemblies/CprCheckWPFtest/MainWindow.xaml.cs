using CprDLL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
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

namespace CprCheckWPFtest
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnValidateCPR_Click(object sender, RoutedEventArgs e)
        {
            CprCheck checker = new CprCheck();
            string cpr = TxtBoxCPR.Text;
            CprCheck.CprError errorMessage;
            bool result = checker.Check(cpr, out errorMessage);
            if(!result)
            {
                lblValidationResult.Foreground = (SolidColorBrush)(new BrushConverter().ConvertFrom("#FF0000"));
                lblValidationResult.Content = "Invalid CPR!";
            }
            else
            {
                lblValidationResult.Foreground = (SolidColorBrush)(new BrushConverter().ConvertFrom("#008000"));
                lblValidationResult.Content = "Valid CPR!";
            }
        }
    }
}
