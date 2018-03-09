﻿using System;
using System.Security;
using System.Security.Permissions;
using System.Security.Principal;
using System.Windows;

namespace RoleBasedSecurity
{
   /// <summary>
   /// Interaction logic for Window1.xaml
   /// </summary>
   public partial class Window1 : Window
   {
      public Window1()
      {
         InitializeComponent();
      }

      private void btnDoSomething_Click(object sender, RoutedEventArgs e)
      {
         MessageBox.Show("OnOpperation1");
      }

      [PrincipalPermission(SecurityAction.Demand, Role = @"T42\Teller")]
      //[PrincipalPermission(SecurityAction.Demand, Role = @"iha\per")]
      private void btnDoSomethingSecured_Click(object sender, RoutedEventArgs e)
      {
         MessageBox.Show("OnOpperation2");
      }

        private void btnReqAdmin_Click(object sender, RoutedEventArgs e)
        {
            AppDomain.CurrentDomain.SetPrincipalPolicy(PrincipalPolicy.WindowsPrincipal);
            PrincipalPermission principalPerm = new PrincipalPermission(null, "Administrators");
            try { 
            principalPerm.Demand();
            MessageBox.Show("Demand succeeded.");
            }
            catch (SecurityException ex)
            {
                MessageBox.Show("Message: " + ex.Message +
                    "\nPermissionType: " + ex.PermissionType +
                    "\nMethod: " + ex.Method +
                    "\nFailedAssemblyInfo: " + ex.FailedAssemblyInfo +
                    "\nZone: " + ex.Zone
                    , "Demand failed.");
            }
        }
    }
}
