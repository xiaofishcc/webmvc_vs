using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Threading;
using System.Diagnostics;

namespace SplashDemo
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            //Thread to show splash window
            Thread thUI = new Thread(new ThreadStart(ShowSplashWindow));
            thUI.Name = "Splash UI";
            thUI.Priority = ThreadPriority.Normal;
            thUI.IsBackground = true;
            thUI.Start();                      
            
            //Thread to load time-consuming resources.
            Thread th = new Thread(new ThreadStart(LoadResources));
            th.Name = "Resource Loader";
            th.Priority = ThreadPriority.Highest;
            th.Start();

            th.Join();

            if (SplashForm!=null)
            {
                SplashForm.Invoke(new MethodInvoker(delegate { SplashForm.Close(); }));
            }

            thUI.Join();
            Application.Run(new frm_Main());         
        }
      
        public static frm_Splash SplashForm
        {
            get;
            set;
        }

        private static void LoadResources()
        {            
            for (int i = 1; i <=15; i++)
            {
                if (SplashForm != null)
                {
                    SplashForm.Invoke(new MethodInvoker(delegate { SplashForm.lblStatus.Text = "Loading some things... " + DateTime.Now.ToString(); }));
                }
                Thread.Sleep(30000);               
            }
            SplashForm.Invoke(new MethodInvoker(delegate { SplashForm.lblStatus.Text = "Done. " + DateTime.Now.ToString(); }));
        }

        private static void ShowSplashWindow()
        {
            SplashForm = new frm_Splash();
            Application.Run(SplashForm);
        }
    }
}
