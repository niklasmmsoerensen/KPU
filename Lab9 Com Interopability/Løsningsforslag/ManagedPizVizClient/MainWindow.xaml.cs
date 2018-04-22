using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
using PizVizServerLib;

namespace ManagedPizVizClient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        ObservableCollection<OrderLine> order = new ObservableCollection<OrderLine>();
        IPizzaManager pizMan;
        IOrderCalculator orderCal;

        public MainWindow()
        {
            InitializeComponent();
            dgOrder.ItemsSource = order;
            pizMan = new PizzaManager();
            orderCal = new OrderCalculator();
        }

        private void btnLookUp_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                tbxPizzaName.Text = pizMan.GetName(short.Parse(tbxPizzaNo.Text));
            }
            catch (Exception exp)
            {
                MessageBox.Show(exp.Message, "Error message from Pizza Manager's GetName()");
            }
        }

        private void btnAddOrderLine_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                tbxTotal.Text = "";
                short count = short.Parse(tbxCount.Text);
                short pizzaNo = short.Parse(tbxOrderPizzaNo.Text);
                string pizzaName = pizMan.GetName(pizzaNo);
                OrderLine ol = new OrderLine() { Count = count, PizzaNo = pizzaNo, PizzaName = pizzaName };
                order.Add(ol);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                tbxCount.Text = "";
                tbxOrderPizzaNo.Text = "";
            }
        }

        private void btnClearOrder_Click(object sender, RoutedEventArgs e)
        {
            order.Clear();
            tbxTotal.Text = "";
        }

        private void btnCloseOrder_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                int countOrderLines = order.Count;
                short[] orderCount = new short[countOrderLines];
                short[] orderPizzaNo = new short[countOrderLines];

                for (int line = 0; line < countOrderLines; line++)
                {
                    orderCount[line] = order[line].Count;
                    orderPizzaNo[line] = order[line].PizzaNo;
                }

                // COM's SAFEARRAY expect to be passed in a strongly typed System.Array
                Array ordCountArr = orderCount;
                Array ordPizzaNoArr = orderPizzaNo;
                decimal totalPrice = orderCal.CalcOrder(ref ordCountArr, ref ordPizzaNoArr);
                tbxTotal.Text = totalPrice.ToString("C2");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
