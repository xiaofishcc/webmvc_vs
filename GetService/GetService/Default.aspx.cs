using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace GetService
{
    public partial class Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }
        //前端调用后台Add接口方法，实现加法运算
        protected void btnOk_Click(object sender,EventArgs e)
        {
            KissHan.ServicejiafaSoapClient ss = new KissHan.ServicejiafaSoapClient();
            int i = Convert.ToInt32(txtValue1.Text);
            int j = Convert.ToInt32(txtValue2.Text);
            txtSum.Text = ss.Add(i,j).ToString();
        }
    }
}